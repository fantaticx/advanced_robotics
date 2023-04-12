#include <opt_local_planner/opt_local_planner.h>
#include <tf2/utils.h>
#include <cmath>

#include <base_local_planner/goal_functions.h>
#include <base_local_planner/trajectory.h>
#include <pluginlib/class_list_macros.h>

//PLUGINLIB_DECLARE_CLASS(local_planner, OptimizationLocalPlanner, opt_local_planner::OptimizationLocalPlanner, nav_core::BaseLocalPlanner)
PLUGINLIB_EXPORT_CLASS(opt_local_planner::OptimizationLocalPlanner, nav_core::BaseLocalPlanner)

namespace opt_local_planner{

        OptimizationLocalPlanner::OptimizationLocalPlanner() : costmap_ros_(NULL), tf_(NULL), costmap_model_(NULL), initialized_(false), odom_helper_("/ground_truth/state") {}

        OptimizationLocalPlanner::OptimizationLocalPlanner(std::string name, tf2_ros::Buffer* tf, costmap_2d::Costmap2DROS* costmap_ros)
         : costmap_ros_(NULL), tf_(NULL), costmap_model_(NULL), initialized_(false), odom_helper_("/ground_truth/state")
         {
                initialize(name, tf, costmap_ros);
         }

        OptimizationLocalPlanner::~OptimizationLocalPlanner() 
        {
          if (initialized_)
          {
            delete costmap_model_;
          }
          clearVertices();
        }

        void OptimizationLocalPlanner::initialize(std::string name, tf2_ros::Buffer* tf, costmap_2d::Costmap2DROS* costmap_ros)
        {

          if(!initialized_)
          {
            ros::NodeHandle private_nh("~/" + name);
            g_plan_pub_ = private_nh.advertise<nav_msgs::Path>("global_plan", 1);
            l_plan_pub_ = private_nh.advertise<nav_msgs::Path>("local_plan", 1);


            //load and set all possible parameters
            private_nh.param("prune_plan", prune_plan_, true);
            private_nh.param("yaw_goal_tolerance", yaw_goal_tolerance_, 1.0);
            private_nh.param("xy_goal_tolerance", xy_goal_tolerance_, 0.3);
            private_nh.param("latch_xy_goal_tolerance", latch_xy_goal_tolerance_, false);
            private_nh.param("acc_lim_x", acc_lim_x_, 1.0);
            private_nh.param("acc_lim_theta", acc_lim_theta_, 0.5);
            private_nh.param("max_vel_x", max_vel_x_, 2.0);
            private_nh.param("max_vel_theta", max_vel_theta_, 0.5);
            private_nh.param("min_samples", min_samples_, 25);
            private_nh.param("costmap_obstacles_behind_robot_dist", costmap_obstacles_behind_robot_dist_, 1.5);
            private_nh.param("control_look_ahead_poses", control_look_ahead_poses_, 1);
            private_nh.param("min_waypoint_separation", min_waypoint_separation_, 0.75);
            private_nh.param("min_obstacle_dist", min_obstacle_dist_, 0.6);
            private_nh.param("no_inner_iterations", no_inner_iterations_, 7);
            private_nh.param("no_outer_iterations", no_outer_iterations_, 4);

            // Weights for cost functions
            private_nh.param("weight_adapt_factor", weight_adapt_factor_, 2.0);
            private_nh.param("weight_obstacle", weight_obstacle_, 5.0);
            private_nh.param("weight_waypoint", weight_waypoint_, 1.5);
            private_nh.param("weight_max_vel_x", weight_max_vel_x_, 1.0);
            private_nh.param("weight_max_vel_theta", weight_max_vel_theta_, 2.0);
            private_nh.param("weight_acc_lim_x", weight_acc_lim_x_, 1.0);
            private_nh.param("weight_acc_lim_theta", weight_acc_lim_theta_, 2.0);
            private_nh.param("weight_optimaltime", weight_optimaltime_, 1.0);
            private_nh.param("weight_shortest_path", weight_shortest_path_, 1.0);
            private_nh.param("weight_kinematics_nh", weight_kinematics_nh_, 15.0);
            private_nh.param("weight_kinematics_forward_drive", weight_kinematics_forward_drive_, 4.0);


            tf_ = tf;
            costmap_ros_ = costmap_ros;
            costmap_ = costmap_ros_->getCostmap();
            global_frame_ = costmap_ros_->getGlobalFrameID();
            robot_base_frame_ = costmap_ros_->getBaseFrameID();
            reached_goal_ = false;
            rotating_to_goal_ = false;
            min_in_place_vel_th_ = 0.4;
            max_vel_th_ = 1.0;
            min_vel_th_ = -1.0;
            rot_stopped_velocity_ = 1e-2;
            trans_stopped_velocity_ = 1e-2;
            id_counter_ = 0;


            //Assuming this planner is being run within the navigation stack, we can
            //just do an upward search for the frequency at which its being run. This
            //also allows the frequency to be overwritten locally.
            std::string controller_frequency_param_name;
            if(!private_nh.searchParam("controller_frequency", controller_frequency_param_name))
              sim_period_ = 0.05;
            else
            {
              double controller_frequency = 0;
              private_nh.param(controller_frequency_param_name, controller_frequency, 20.0);
              if(controller_frequency > 0)
                sim_period_ = 1.0 / controller_frequency;
              else
              {
                ROS_WARN("A controller_frequency less than 0 has been set. Ignoring the parameter, assuming a rate of 20Hz");
                sim_period_ = 0.05;
              }
            }
            ROS_INFO("Sim period is set to %.2f", sim_period_);

            robot_footprint_ = costmap_ros_->getRobotFootprint();
            costmap_2d::calculateMinAndMaxDistances(robot_footprint_, robot_inscribed_radius_, robot_circumscribed_radius_);  
            costmap_model_ = new base_local_planner::CostmapModel(*costmap_);

            // initialize the g2o optimizer
            // Call register_g2o_types once, even for multiple TebOptimalPlanner instances (thread-safe)
            static boost::once_flag flag = BOOST_ONCE_INIT;
            boost::call_once(&registerG2OTypes, flag);  

            // allocating the optimizer
            optimizer_ = boost::make_shared<g2o::SparseOptimizer>();
            std::unique_ptr<OptLinearSolver> linear_solver(new OptLinearSolver()); // see typedef in opt_local_planner.h
            linear_solver->setBlockOrdering(true);
            std::unique_ptr<OptBlockSolver> block_solver(new OptBlockSolver(std::move(linear_solver)));
            g2o::OptimizationAlgorithmLevenberg* solver = new g2o::OptimizationAlgorithmLevenberg(std::move(block_solver));
            optimizer_->setAlgorithm(solver);
            optimizer_->initMultiThreading(); // required for >Eigen 3.1

            initialized_ = true;
          }

        }

        /*
        * registers custom vertices and edges in g2o framework
        */
        void OptimizationLocalPlanner::registerG2OTypes()
        {
          g2o::Factory* factory = g2o::Factory::instance();
          factory->registerType("VERTEX_POSE", new g2o::HyperGraphElementCreator<VertexPose>);
          factory->registerType("VERTEX_TIMEDIFF", new g2o::HyperGraphElementCreator<VertexTimeDiff>);
          factory->registerType("EDGE_OBSTACLE", new g2o::HyperGraphElementCreator<EdgeObstacle>);
          factory->registerType("EDGE_VIA_POINT", new g2o::HyperGraphElementCreator<EdgeViaPoint>);
          factory->registerType("EDGE_VELOCITY", new g2o::HyperGraphElementCreator<EdgeVelocity>);
          factory->registerType("EDGE_ACCELERATION", new g2o::HyperGraphElementCreator<EdgeAcceleration>);
          factory->registerType("EDGE_ACCELERATION_START", new g2o::HyperGraphElementCreator<EdgeAccelerationStart>);
          factory->registerType("EDGE_ACCELERATION_GOAL", new g2o::HyperGraphElementCreator<EdgeAccelerationGoal>);
          factory->registerType("EDGE_TIME_OPTIMAL", new g2o::HyperGraphElementCreator<EdgeTimeOptimal>);
          factory->registerType("EDGE_SHORTEST_PATH", new g2o::HyperGraphElementCreator<EdgeShortestPath>);
          factory->registerType("EDGE_KINEMATICS_DIFF_DRIVE", new g2o::HyperGraphElementCreator<EdgeKinematicsDiffDrive>);
          return;
        }

        bool OptimizationLocalPlanner::setPlan(const std::vector<geometry_msgs::PoseStamped>& orig_global_plan)
        {
          if(!initialized_)
          {
            ROS_ERROR("This planner has not been initialized, please call initialize() before using this planner");
            return false;
          }

          //reset the global plan
          global_plan_.clear();
          global_plan_ = orig_global_plan;

          //when we get a new plan, we also want to clear any latch we may have on goal tolerances
          xy_tolerance_latch_ = false;
          //reset the at goal flag
          reached_goal_ = false;

          return true;
        }

        bool OptimizationLocalPlanner::computeVelocityCommands(geometry_msgs::Twist& cmd_vel)
        {
          if(!initialized_)
          {
            ROS_ERROR("This planner has not been initialized, please call initialize() before using this planner");
            return false;
          }

          std::vector<geometry_msgs::PoseStamped> local_plan;
          geometry_msgs::PoseStamped global_pose;
          if (!costmap_ros_->getRobotPose(global_pose)) {
            return false;
          }
          robot_pose_ = PoseSE2(global_pose.pose);

          std::vector<geometry_msgs::PoseStamped> transformed_plan;
          //get the global plan in our frame
          if (!base_local_planner::transformGlobalPlan(*tf_, global_plan_, global_pose, *costmap_, global_frame_, transformed_plan)) {
            ROS_WARN("Could not transform the global plan to the frame of the controller");
            return false;
          }

          //now we'll prune the plan based on the position of the robot
          if(prune_plan_)
            base_local_planner::prunePlan(global_pose, transformed_plan, global_plan_);

          geometry_msgs::PoseStamped robot_vel_tf;
          odom_helper_.getRobotVel(robot_vel_tf);
          robot_vel_.linear.x = robot_vel_tf.pose.position.x;
          robot_vel_.linear.y = robot_vel_tf.pose.position.y;
          robot_vel_.angular.z = tf2::getYaw(robot_vel_tf.pose.orientation);

          //if the global plan passed in is empty... we won't do anything
          if(transformed_plan.empty())
            return false;

          const geometry_msgs::PoseStamped& goal_point = transformed_plan.back();
          //we assume the global goal is the last point in the global plan
          robot_goal_.x() = goal_point.pose.position.x;
          robot_goal_.y() = goal_point.pose.position.y;
          robot_goal_.theta() = tf2::getYaw(goal_point.pose.orientation);

          //check to see if we've reached the goal position
          if (xy_tolerance_latch_ || (base_local_planner::getGoalPositionDistance(global_pose, robot_goal_.x(), robot_goal_.y()) <= xy_goal_tolerance_)) {

            //if the user wants to latch goal tolerance, if we ever reach the goal location, we'll
            //just rotate in place
            if (latch_xy_goal_tolerance_) {
              xy_tolerance_latch_ = true;
            }

            double angle = base_local_planner::getGoalOrientationAngleDifference(global_pose, robot_goal_.theta());
            //check to see if the goal orientation has been reached
            if (fabs(angle) <= yaw_goal_tolerance_) {
              //set the velocity command to zero
              cmd_vel.linear.x = 0.0;
              cmd_vel.linear.y = 0.0;
              cmd_vel.angular.z = 0.0;
              rotating_to_goal_ = false;
              xy_tolerance_latch_ = false;
              reached_goal_ = true;
            } else {
              //we need to call the next two lines to make sure that the trajectory
              //planner updates its path distance and goal distance grids
              /*tc_->updatePlan(transformed_plan);
              Trajectory path = tc_->findBestPath(global_pose, robot_vel_tf, drive_cmds);
              map_viz_.publishCostCloud(costmap_);*/

              //copy over the odometry information
              nav_msgs::Odometry base_odom;
              odom_helper_.getOdom(base_odom);

              //if we're not stopped yet... we want to stop... taking into account the acceleration limits of the robot
              if ( ! rotating_to_goal_ && !base_local_planner::stopped(base_odom, rot_stopped_velocity_, trans_stopped_velocity_)) {
                if ( ! stopWithAccLimits(global_pose, robot_vel_tf, cmd_vel)) {
                  return false;
                }
              }
              //if we're stopped... then we want to rotate to goal
              else{
                //set this so that we know its OK to be moving
                rotating_to_goal_ = true;
                if(!rotateToGoal(global_pose, robot_vel_tf, robot_goal_.theta(), cmd_vel)) {
                  return false;
                }
              }
            }

            //publish an empty plan because we've reached our goal position
            base_local_planner::publishPlan(transformed_plan, g_plan_pub_);
            base_local_planner::publishPlan(local_plan, l_plan_pub_);

            //we don't actually want to run the controller when we're just rotating to goal
            return true;
          }

          // overwrite/update start of the transformed plan with the actual robot position (allows using the plan as initial trajectory)
          transformed_plan.front() = global_pose; // update start

          //compute what trajectory to drive along
          base_local_planner::Trajectory path; // TODO: remove this

          bool success = planTrajectory(transformed_plan);
          if (!success)
          {
            clearGraph();
            clearVertices();
            ROS_WARN("opt_local_planner was not able to obtain a local plan for the current setting.");
            cmd_vel.linear.x = cmd_vel.linear.y = cmd_vel.angular.z = 0;
            return false;
          }
          
          // TODO: Feasibility check
          bool feasible = isTrajectoryFeasible(costmap_model_, robot_footprint_);
          if (!feasible)                                                     
          {
            cmd_vel.linear.x = cmd_vel.linear.y = cmd_vel.angular.z = 0;

            // now we reset everything to start again with the initialization of new trajectories.
            clearGraph();
            clearVertices();
            return false;
          }

          // Get the velocity command for this sampling interval //TODO Implement
          if (!getVelocityCommand(cmd_vel.linear.x, cmd_vel.linear.y, cmd_vel.angular.z))
          {
            clearGraph();
            clearVertices();
            return false;
          }
         
          ROS_DEBUG_NAMED("OptimizationLocalPlanner", "A valid velocity command of (%.2f, %.2f, %.2f) was found for this cycle.",
              cmd_vel.linear.x, cmd_vel.linear.y, cmd_vel.angular.z);

          for (unsigned int i = 0; i < (int) pose_vec_.size(); ++i) 
          {
            geometry_msgs::PoseStamped pose;
            pose.header.frame_id = global_frame_;
            pose.header.stamp = ros::Time::now();
            pose.pose.position.x = pose_vec_.at(i)->x();
            pose.pose.position.y = pose_vec_.at(i)->y();
            pose.pose.position.z = 0.0;
            tf2::Quaternion q;
            q.setRPY(0, 0, pose_vec_.at(i)->theta());
            tf2::convert(q, pose.pose.orientation);
            local_plan.push_back(pose);
          }

          //publish information to the visualizer
          base_local_planner::publishPlan(transformed_plan, g_plan_pub_);
          base_local_planner::publishPlan(local_plan, l_plan_pub_);
          return true;

        }

    bool OptimizationLocalPlanner::isGoalReached()
    {
      if(!initialized_)
      {
        ROS_ERROR("This planner has not been initialized, please call initialize() before using this planner");
        return false;
      }
      return reached_goal_;
    }

    bool OptimizationLocalPlanner::planTrajectory(const std::vector<geometry_msgs::PoseStamped>& initial_plan)
    {
      // initialize your TEB tuples consisting of your robot poses (x,y,theta) and the estimated time differences
      initializeTEBTuples(initial_plan);

      // Update the obstacles from the costmap. Has to be done even in a static environment due to the rolling window
      updateObstacleContainer();
      // fill the way point container based on the given plan
      updateViaPointsContainer(initial_plan, min_waypoint_separation_);
          
      // now optimize
      return optimizeTEB(no_inner_iterations_, no_outer_iterations_);
    }

    bool OptimizationLocalPlanner::initializeTEBTuples(const std::vector<geometry_msgs::PoseStamped>& plan)
    {
      PoseSE2 start(plan.front().pose);
      PoseSE2 goal(plan.back().pose);

      // ----------------------------------------------------------------------
      // TODO
      // (re)initialize your tuples for TEB planner. 
      // Therefore, take the given plan and estimate your pose (x,y,theta) from the plan positions
      // Additonally, estimate the time difference between the poses. Hint: use max_vel_x_ and max_vel_theta_ as guess
      // Add your poses and time diffs to your pose/timediff vectors (see addPose(), addTimeDiff(), addPoseAndTimeDiff())
      // Make sure, that you have at least min_samples_ samples in your pose_vec_
      
      return true;
    }

    void OptimizationLocalPlanner::updateObstacleContainer()
    {
      // ----------------------------------------------------------------------
      // TODO
      // Update the obstacles from the costmap. Has to be done even in a static environment due to the rolling window.
      // search for obstacles within the costmap and add them to the obstacles_ vector. 
      // The obstacles should be of Type "Obstacle" (see obstacles.h)

    }

    void OptimizationLocalPlanner::updateViaPointsContainer(const std::vector<geometry_msgs::PoseStamped>& transformed_plan, double min_separation)
    {

      // ----------------------------------------------------------------------
      // TODO
      // Compute Waypoints from the given plan. Use min_seperation as seperation parameter. 
      // Add the waypoints into the via_points_ vector. 
      
    }

    bool OptimizationLocalPlanner::optimizeTEB(int iterations_innerloop, int iterations_outerloop)
    {
    
      bool success = false;
      bool optimized_ = false;
      
      double weight_multiplier = 1.0;
      
      for(int i=0; i<iterations_outerloop; ++i)
      {

        success = buildGraph(weight_multiplier);
        if (!success) 
        {
            clearGraph();
            return false;
        }
        success = optimizeGraph(iterations_innerloop, false);
        if (!success) 
        {
            clearGraph();
            return false;
        }
        optimized_ = true;
          
        clearGraph();
        
        weight_multiplier *= weight_adapt_factor_;
      }

      return true;
    }

    bool OptimizationLocalPlanner::buildGraph(double weight_multiplier)
    {
      if (!optimizer_->edges().empty() || !optimizer_->vertices().empty())
      {
        ROS_WARN("Cannot build graph, because it is not empty. Call graphClear()!");
        return false;
      }

      // Set to true to enable divergence detection.
      optimizer_->setComputeBatchStatistics(false);
      
      AddTEBVertices();
      
      AddEdgesObstacles(weight_multiplier);

      AddEdgesViaPoints();
      
      AddEdgesVelocity();
      
      AddEdgesAcceleration();

      AddEdgesTimeOptimal();	

      AddEdgesShortestPath();
      
      AddEdgesKinematicsDiffDrive(); // we have a differential drive robot
        
      return true;  
    }

    void OptimizationLocalPlanner::AddEdgesKinematicsDiffDrive()
    {
      
      // create edge for satisfiying kinematic constraints
      Eigen::Matrix<double,2,2> information_kinematics;
      information_kinematics.fill(0.0);
      information_kinematics(0, 0) = weight_kinematics_nh_;
      information_kinematics(1, 1) = weight_kinematics_forward_drive_;
      
      for (int i=0; i < (int)pose_vec_.size()-1; i++) // ignore twiced start only
      {
        EdgeKinematicsDiffDrive* kinematics_edge = new EdgeKinematicsDiffDrive;
        kinematics_edge->setVertex(0,pose_vec_.at(i));
        kinematics_edge->setVertex(1,pose_vec_.at(i+1));      
        kinematics_edge->setInformation(information_kinematics);
        optimizer_->addEdge(kinematics_edge);
      }	 
    }

    void OptimizationLocalPlanner::AddEdgesTimeOptimal()
    {
      Eigen::Matrix<double,1,1> information;
      information.fill(weight_optimaltime_);

      for (int i=0; i < (int)timediff_vec_.size(); ++i)
      {
        EdgeTimeOptimal* timeoptimal_edge = new EdgeTimeOptimal;
        timeoptimal_edge->setVertex(0,timediff_vec_.at(i));
        timeoptimal_edge->setInformation(information);
        optimizer_->addEdge(timeoptimal_edge);
      }
    }

    void OptimizationLocalPlanner::AddEdgesShortestPath()
    {
      Eigen::Matrix<double,1,1> information;
      information.fill(weight_shortest_path_);

      for (int i=0; i < (int)pose_vec_.size()-1; ++i)
      {
        EdgeShortestPath* shortest_path_edge = new EdgeShortestPath;
        shortest_path_edge->setVertex(0,pose_vec_.at(i));
        shortest_path_edge->setVertex(1,pose_vec_.at(i+1));
        shortest_path_edge->setInformation(information);
        optimizer_->addEdge(shortest_path_edge);
      }
    }

    void OptimizationLocalPlanner::AddEdgesAcceleration()
    {
      int n = (int) pose_vec_.size();
        
        Eigen::Matrix<double,2,2> information;
        information.fill(0);
        information(0,0) = weight_acc_lim_x_;
        information(1,1) = weight_acc_lim_theta_;
        
        // check if an initial velocity should be taken into accound
        EdgeAccelerationStart* acceleration_edge_s = new EdgeAccelerationStart(acc_lim_x_, acc_lim_theta_);
        acceleration_edge_s->setVertex(0,pose_vec_.at(0));
        acceleration_edge_s->setVertex(1,pose_vec_.at(1));
        acceleration_edge_s->setVertex(2,timediff_vec_.at(0));
        acceleration_edge_s->setInitialVelocity(robot_vel_);
        acceleration_edge_s->setInformation(information);
        optimizer_->addEdge(acceleration_edge_s);
        

        // now add the usual acceleration edge for each tuple of three teb poses
        for (int i=0; i < n - 2; ++i)
        {
          EdgeAcceleration* acceleration_edge = new EdgeAcceleration(acc_lim_x_, acc_lim_theta_);
          acceleration_edge->setVertex(0,pose_vec_.at(i));
          acceleration_edge->setVertex(1,pose_vec_.at(i+1));
          acceleration_edge->setVertex(2,pose_vec_.at(i+2));
          acceleration_edge->setVertex(3,timediff_vec_.at(i));
          acceleration_edge->setVertex(4,timediff_vec_.at(i+1));
          acceleration_edge->setInformation(information);
          optimizer_->addEdge(acceleration_edge);
        }
        
        geometry_msgs::Twist zero_goal;
        EdgeAccelerationGoal* acceleration_edge_g = new EdgeAccelerationGoal(acc_lim_x_, acc_lim_theta_);
        acceleration_edge_g->setVertex(0,pose_vec_.at(n-2));
        acceleration_edge_g->setVertex(1,pose_vec_.at(n-1));
        acceleration_edge_g->setVertex(2,timediff_vec_.at(timediff_vec_.size() - 1));
        acceleration_edge_g->setGoalVelocity(zero_goal);
        acceleration_edge_g->setInformation(information);
        optimizer_->addEdge(acceleration_edge_g);
        
      
    }

    void OptimizationLocalPlanner::AddEdgesVelocity()
    {
        int n = (int) pose_vec_.size();
        Eigen::Matrix<double,2,2> information;
        information(0,0) = weight_max_vel_x_;
        information(1,1) = weight_max_vel_theta_;
        information(0,1) = 0.0;
        information(1,0) = 0.0;

        for (int i=0; i < n - 1; ++i)
        {
          EdgeVelocity* velocity_edge = new EdgeVelocity(max_vel_x_, max_vel_theta_);
          velocity_edge->setVertex(0, pose_vec_.at(i));
          velocity_edge->setVertex(1, pose_vec_.at(i + 1));
          velocity_edge->setVertex(2, timediff_vec_.at(i));
          velocity_edge->setInformation(information);
          optimizer_->addEdge(velocity_edge);
        }

    }

    void OptimizationLocalPlanner::AddEdgesViaPoints()
    {

      //-----------------------------------------------------------------------
      // TODO
      // Add edges for the extracted waypoints. Therefore, search the closest
      // Pose on your initialized trajectory and add an EdgeViaPoint

    }


    void OptimizationLocalPlanner::AddTEBVertices()
    {
      //-----------------------------------------------------------------------
      // TODO
      // Add your poses from pose_vec_ and time differences (timediff_vec_) as 
      // Vertex to the graph. 
    }

    void OptimizationLocalPlanner::createObstacleEdge(int index, double weight_multiplier, Obstacle* obstacle) 
    {
      Eigen::Matrix<double,1,1> information;
      information.fill(weight_obstacle_ * weight_multiplier);
      EdgeObstacle* dist_bandpt_obst = new EdgeObstacle(min_obstacle_dist_);
      dist_bandpt_obst->setVertex(0, pose_vec_.at(index));
      dist_bandpt_obst->setInformation(information);
      dist_bandpt_obst->setParameters(obstacle);
      optimizer_->addEdge(dist_bandpt_obst);
    }

    void OptimizationLocalPlanner::AddEdgesObstacles(double weight_multiplier)
    {
      //-----------------------------------------------------------------------
      // TODO
      // Add relevant obstacles as edge to the graph
      // The obstacles should be connected to the closes pose vertex in the graph
      // As the number of obstacles heavily influences the overall optimization performance,
      // a wise addition of the obstacles is recommended
      // Hint: to create an ObstacleEdge in the graph, use createObstacleEdge() 

    }

    bool OptimizationLocalPlanner::optimizeGraph(int no_iterations,bool clear_after)
    {
      if (max_vel_x_ < 0.01)
      {
        ROS_WARN("optimizeGraph(): Robot Max Velocity is smaller than 0.01m/s. Optimizing aborted...");
        if (clear_after) clearGraph();
        return false;	
      }
      
      optimizer_->setVerbose(false);
      optimizer_->initializeOptimization();

      int iter = optimizer_->optimize(no_iterations);

      if(!iter)
      {
      ROS_ERROR("optimizeGraph(): Optimization failed! iter=%i", iter);
      return false;
      }

      if (clear_after) clearGraph();	
        
      return true;
    }

    bool OptimizationLocalPlanner::stopWithAccLimits(const geometry_msgs::PoseStamped& global_pose, const geometry_msgs::PoseStamped& robot_vel, geometry_msgs::Twist& cmd_vel){
      //slow down with the maximum possible acceleration... we should really use the frequency that we're running at to determine what is feasible
      //but we'll use a tenth of a second to be consistent with the implementation of the local planner.
      double vx = copysign(std::max(0.0, (fabs(robot_vel.pose.position.x) - acc_lim_x_ * sim_period_)), robot_vel.pose.position.x);

      double vel_yaw = tf2::getYaw(robot_vel.pose.orientation);
      double vth = copysign(std::max(0.0, (fabs(vel_yaw) - acc_lim_theta_ * sim_period_)), vel_yaw);

      //we do want to check whether or not the command is valid
      double yaw = tf2::getYaw(global_pose.pose.orientation);
      double new_yaw = yaw + vel_yaw; 
      geometry_msgs::Point robot_forward_position;  
      robot_forward_position.x = global_pose.pose.position.x + robot_vel.pose.position.x;
      robot_forward_position.y = global_pose.pose.position.y + robot_vel.pose.position.y;

      // check the footprint costs at the new position
      bool valid_cmd = costmap_model_->footprintCost(robot_forward_position.x, robot_forward_position.y, new_yaw, robot_footprint_) >= 0;

      //if we have a valid command, we'll pass it on, otherwise we'll command all zeros
      if(valid_cmd){
        ROS_DEBUG("Slowing down... using vx, vth: %.2f, %.2f", vx, vth);
        cmd_vel.linear.x = vx;
        cmd_vel.linear.y = 0.0;
        cmd_vel.angular.z = vth;
        return true;
      }

      cmd_vel.linear.x = 0.0;
      cmd_vel.linear.y = 0.0;
      cmd_vel.angular.z = 0.0;
      return false;
    }

    bool OptimizationLocalPlanner::rotateToGoal(const geometry_msgs::PoseStamped& global_pose, const geometry_msgs::PoseStamped& robot_vel, double goal_th, geometry_msgs::Twist& cmd_vel){
      double yaw = tf2::getYaw(global_pose.pose.orientation);
      double vel_yaw = tf2::getYaw(robot_vel.pose.orientation);
      cmd_vel.linear.x = 0;
      cmd_vel.linear.y = 0;
      double ang_diff = angles::shortest_angular_distance(yaw, goal_th);

      double v_theta_samp = ang_diff > 0.0 ? std::min(max_vel_th_,
          std::max(min_in_place_vel_th_, ang_diff)) : std::max(min_vel_th_,
          std::min(-1.0 * min_in_place_vel_th_, ang_diff));

      //take the acceleration limits of the robot into account
      double max_acc_vel = fabs(vel_yaw) + acc_lim_theta_ * sim_period_;
      double min_acc_vel = fabs(vel_yaw) - acc_lim_theta_ * sim_period_;

      v_theta_samp = copysign(std::min(std::max(fabs(v_theta_samp), min_acc_vel), max_acc_vel), v_theta_samp);

      //we also want to make sure to send a velocity that allows us to stop when we reach the goal given our acceleration limits
      double max_speed_to_stop = sqrt(2 * acc_lim_theta_ * fabs(ang_diff)); 

      v_theta_samp = copysign(std::min(max_speed_to_stop, fabs(v_theta_samp)), v_theta_samp);

      // Re-enforce min_in_place_vel_th_.  It is more important than the acceleration limits.
      v_theta_samp = v_theta_samp > 0.0
        ? std::min( max_vel_th_, std::max( min_in_place_vel_th_, v_theta_samp ))
        : std::max( min_vel_th_, std::min( -1.0 * min_in_place_vel_th_, v_theta_samp ));

      //we still want to lay down the footprint of the robot and check if the action is legal
      double new_yaw = yaw + vel_yaw; 
      geometry_msgs::Point robot_forward_position;  
      robot_forward_position.x = global_pose.pose.position.x + robot_vel.pose.position.x;
      robot_forward_position.y = global_pose.pose.position.y + robot_vel.pose.position.y;

      // check the footprint costs at the new position
      bool valid_cmd = costmap_model_->footprintCost(robot_forward_position.x, robot_forward_position.y, new_yaw, robot_footprint_) >= 0;

      ROS_DEBUG("Moving to desired goal orientation, th cmd: %.2f, valid_cmd: %d", v_theta_samp, valid_cmd);

      if(valid_cmd){
        cmd_vel.angular.z = v_theta_samp;
        return true;
      }

      cmd_vel.angular.z = 0.0;
      return false;

    }

    bool OptimizationLocalPlanner::isTrajectoryFeasible(base_local_planner::CostmapModel* costmap_model, const std::vector<geometry_msgs::Point>& footprint_spec)
    {
      int look_ahead_idx = (int)pose_vec_.size() - 1;
      for (int i=0; i <= look_ahead_idx; ++i)
      {   
        
        if ( costmap_model->footprintCost(pose_vec_.at(i)->pose().x(), pose_vec_.at(i)->pose().y(), pose_vec_.at(i)->pose().theta(), footprint_spec, robot_inscribed_radius_, robot_circumscribed_radius_) == -1 )
          return false;
        
        // Checks if the distance between two poses is higher than the robot radius or the orientation diff is bigger than the specified threshold
        // and interpolates in that case.
        // (if obstacles are pushing two consecutive poses away, the center between two consecutive poses might coincide with the obstacle ;-)!
        if (i<look_ahead_idx)
        {
          double delta_rot = g2o::normalize_theta(g2o::normalize_theta(pose_vec_.at(i+1)->pose().theta()) -
                                                  g2o::normalize_theta(pose_vec_.at(i)->pose().theta()));
          Eigen::Vector2d delta_dist = pose_vec_.at(i+1)->pose().position()-pose_vec_.at(i)->pose().position();
          if(fabs(delta_rot) > M_PI || delta_dist.norm() > robot_inscribed_radius_)
          {
            int n_additional_samples = std::max(std::ceil(fabs(delta_rot) / M_PI), 
                                                std::ceil(delta_dist.norm() / robot_inscribed_radius_)) - 1;
            PoseSE2 intermediate_pose = pose_vec_.at(i)->pose();
            for(int step = 0; step < n_additional_samples; ++step)
            {
              intermediate_pose.position() = intermediate_pose.position() + delta_dist / (n_additional_samples + 1.0);
              intermediate_pose.theta() = g2o::normalize_theta(intermediate_pose.theta() + 
                                                              delta_rot / (n_additional_samples + 1.0));

              if ( costmap_model->footprintCost(intermediate_pose.x(), intermediate_pose.y(), intermediate_pose.theta(),
                footprint_spec, robot_inscribed_radius_, robot_circumscribed_radius_) == -1)
                return false;
              
            }
          }
        }
      }
      return true;
    }

    bool OptimizationLocalPlanner::getVelocityCommand(double& vx, double& vy, double& omega) const
    {
      int look_ahead_poses = 5;
      double dt_ref = 0.3;
      if (pose_vec_.size()<2)
      {
        ROS_ERROR("OptimizationLocalPlanner::getVelocityCommand(): The trajectory contains less than 2 poses. Make sure to init and optimize/plan the trajectory fist.");
        vx = 0;
        vy = 0;
        omega = 0;
        return false;
      }
      look_ahead_poses = std::max(1, std::min(look_ahead_poses, (int) pose_vec_.size() - 1));
      double dt = 0.0;
      for(int counter = 0; counter < look_ahead_poses; ++counter)
      {
        dt += timediff_vec_.at(counter)->dt();
        if(dt >= dt_ref * look_ahead_poses)  
        {
            look_ahead_poses = counter + 1;
            break;
        }
      }
      if (dt<=0)
      {	
        ROS_ERROR("OptimizationLocalPlanner::getVelocityCommand() - timediff<=0 is invalid!");
        vx = 0;
        vy = 0;
        omega = 0;
        return false;
      }
        
      // Get velocity from the first two configurations
      extractVelocity(pose_vec_.at(0)->pose(), pose_vec_.at(look_ahead_poses)->pose(), dt, vx, vy, omega);
      return true;
    }

    void OptimizationLocalPlanner::extractVelocity(const PoseSE2& pose1, const PoseSE2& pose2, double dt, double& vx, double& vy, double& omega) const
    {
      if (dt == 0)
      {
        vx = 0;
        vy = 0;
        omega = 0;
        return;
      }
      
      Eigen::Vector2d deltaS = pose2.position() - pose1.position();
      

      // transform pose 2 into the current robot frame (pose1)
      // for velocities only the rotation of the direction vector is necessary.
      // (map->pose1-frame: inverse 2d rotation matrix)
      double cos_theta1 = std::cos(pose1.theta());
      double sin_theta1 = std::sin(pose1.theta());
      double p1_dx =  cos_theta1*deltaS.x() + sin_theta1*deltaS.y();
      double p1_dy = -sin_theta1*deltaS.x() + cos_theta1*deltaS.y();
      vx = p1_dx / dt;
      vy = p1_dy / dt;    
      
      
      // rotational velocity
      double orientdiff = g2o::normalize_theta(pose2.theta() - pose1.theta());
      omega = orientdiff/dt;
    }


    void OptimizationLocalPlanner::addPose(const PoseSE2& pose, bool fixed)
    {
      VertexPose* pose_vertex = new VertexPose(pose, fixed);
      pose_vertex->setId(++id_counter_);
      pose_vec_.push_back( pose_vertex );
      return;
    }

    void OptimizationLocalPlanner::setPoseVertexFixed(int index, bool status)
    {
      pose_vec_.at(index)->setFixed(status);   
    }

    void OptimizationLocalPlanner::addPoseAndTimeDiff(const PoseSE2& pose, double dt)
    {
      if (pose_vec_.size() != timediff_vec_.size())
      {
        addPose(pose,false);
        addTimeDiff(dt,false);
      } else
        ROS_ERROR("Method addPoseAndTimeDiff: Add one single Pose first. Timediff describes the time difference between last conf and given conf");
      return;
    }

    void OptimizationLocalPlanner::addTimeDiff(double dt, bool fixed)
    {
      ROS_ASSERT_MSG(dt > 0., "Adding a timediff requires a positive dt");
      VertexTimeDiff* timediff_vertex = new VertexTimeDiff(dt, fixed);
      timediff_vertex->setId(++id_counter_);
      timediff_vec_.push_back( timediff_vertex );
      return;
    }

    void OptimizationLocalPlanner::clearGraph()
    {
      // clear optimizer states
      if (optimizer_)
      {
        // we will delete all edges but keep the vertices.
        // before doing so, we will delete the link from the vertices to the edges.
        auto& vertices = optimizer_->vertices();
        for(auto& v : vertices)
          v.second->edges().clear();

        optimizer_->vertices().clear();  // necessary, because optimizer->clear deletes pointer-targets (therefore it deletes TEB states!)
        optimizer_->clear();
      }
    }

    void OptimizationLocalPlanner::clearVertices()
    {
      for (PoseSequence::iterator pose_it = pose_vec_.begin(); pose_it != pose_vec_.end(); ++pose_it)
        delete *pose_it;
      pose_vec_.clear();
      
      for (TimeDiffSequence::iterator dt_it = timediff_vec_.begin(); dt_it != timediff_vec_.end(); ++dt_it)
        delete *dt_it;
      timediff_vec_.clear();
    }
}
