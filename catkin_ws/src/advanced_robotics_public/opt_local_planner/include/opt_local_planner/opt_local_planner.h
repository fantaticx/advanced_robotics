#ifndef LOCAL_PLANNER_H_
#define LOCAL_PLANNER_H_

// abstract class from which our plugin inherits
#include <nav_core/base_local_planner.h>
#include <base_local_planner/odometry_helper_ros.h>
#include <base_local_planner/costmap_model.h>
#include <tf2_ros/buffer.h>
#include <ros/ros.h>
#include <opt_local_planner/pose_se2.h>
#include <opt_local_planner/obstacles.h>

// G2O Types
#include <opt_local_planner/g2o_types/vertex_pose.h>
#include <opt_local_planner/g2o_types/vertex_timediff.h>
#include <opt_local_planner/g2o_types/edge_obstacle.h>
#include <opt_local_planner/g2o_types/edge_velocity.h>
#include <opt_local_planner/g2o_types/edge_acceleration.h>
#include <opt_local_planner/g2o_types/edge_via_point.h>
#include <opt_local_planner/g2o_types/edge_time_optimal.h>
#include <opt_local_planner/g2o_types/edge_kinematics.h>
#include <opt_local_planner/g2o_types/edge_shortest_path.h>


// g2o lib stuff
#include <g2o/core/sparse_optimizer.h>
#include <g2o/core/block_solver.h>
#include <g2o/core/factory.h>
#include <g2o/core/optimization_algorithm_levenberg.h>
#include <g2o/solvers/csparse/linear_solver_csparse.h>

#include <g2o/types/slam2d/vertex_se2.h>
#include <g2o/types/slam2d/edge_se2.h>

#include <g2o/core/optimization_algorithm_factory.h>

#include <geometry_msgs/PoseStamped.h>
#include <costmap_2d/costmap_2d_ros.h>
#include <nav_msgs/Odometry.h>

using namespace std;

namespace opt_local_planner{

  //! Typedef for a container storing via-points
  typedef std::vector< Eigen::Vector2d, Eigen::aligned_allocator<Eigen::Vector2d> > ViaPointContainer;

  //! Typedef for the block solver utilized for optimization
  typedef g2o::BlockSolver< g2o::BlockSolverTraits<-1, -1> >  OptBlockSolver;

  //! Typedef for the linear solver utilized for optimization
  typedef g2o::LinearSolverCSparse<OptBlockSolver::PoseMatrixType> OptLinearSolver;

  //! Container of poses that represent the spatial part of the trajectory
  typedef std::vector<VertexPose*> PoseSequence;
  //! Container of time differences that define the temporal of the trajectory
  typedef std::vector<VertexTimeDiff*> TimeDiffSequence;

  class OptimizationLocalPlanner : public nav_core::BaseLocalPlanner{

    public:
      OptimizationLocalPlanner();

      OptimizationLocalPlanner(std::string name, tf2_ros::Buffer* tf, costmap_2d::Costmap2DROS* costmap_ros);

      ~OptimizationLocalPlanner();

      void initialize(std::string name, tf2_ros::Buffer* tf, costmap_2d::Costmap2DROS* costmap_ros);


      bool setPlan(const std::vector<geometry_msgs::PoseStamped>& orig_global_plan);

      bool computeVelocityCommands(geometry_msgs::Twist& cmd_vel);

      bool isGoalReached();

      /**
       * @brief Once a goal position is reached... rotate to the goal orientation
       * @param  global_pose The pose of the robot in the global frame
       * @param  robot_vel The velocity of the robot
       * @param  goal_th The desired th value for the goal
       * @param  cmd_vel The velocity commands to be filled
       * @return  True if a valid trajectory was found, false otherwise
       */
      bool rotateToGoal(const geometry_msgs::PoseStamped& global_pose, const geometry_msgs::PoseStamped& robot_vel, double goal_th, geometry_msgs::Twist& cmd_vel);

      /**
       * @brief Stop the robot taking into account acceleration limits
       * @param  global_pose The pose of the robot in the global frame
       * @param  robot_vel The velocity of the robot
       * @param  cmd_vel The velocity commands to be filled
       * @return  True if a valid trajectory was found, false otherwise
       */
      bool stopWithAccLimits(const geometry_msgs::PoseStamped& global_pose, const geometry_msgs::PoseStamped& robot_vel, geometry_msgs::Twist& cmd_vel);

       /**
       * @brief Update the obstacle container for planning. This can be done once if all obstacles are to be considered or dynamic based on the robot pose to improve performance
       */
      void updateObstacleContainer();

       /**
       * @brief Update the waypoints container for planning. 
       * @param  transformed_plan The plan to derive the waypoints from
       * @param  min_separation the minimum seperation between two points
       */
      void updateViaPointsContainer(const std::vector<geometry_msgs::PoseStamped>& transformed_plan, double min_separation);

              /**
       * @brief Clear an existing internal hyper-graph.
       * @see buildGraph
       * @see optimizeGraph
       */
      void clearGraph();

      void clearVertices();

      bool isTrajectoryFeasible(base_local_planner::CostmapModel* costmap_model, const std::vector<geometry_msgs::Point>& footprint_spec);

    private:
      static void registerG2OTypes();

      /**
       * @brief The actual planning function for the TEB functionality 
       * @param  initial_plan The pruned plan from the global planner
       */
      bool planTrajectory(const std::vector<geometry_msgs::PoseStamped>& initial_plan);

        /**
       * @brief Optimize a previously initialized trajectory (actual TEB optimization loop).
       * 
       * optimizeTEB implements the main optimization loop. \n
       * It consist of two nested loops:
       * 	- in the outer loop the internal method optimizeGraph() is called that constitutes the innerloop.
       * 	- The inner loop calls the solver (g2o framework, resp. sparse Levenberg-Marquardt) and iterates a specified
       * 	  number of optimization calls (\c iterations_innerloop).
       * 
       * The outer loop is repeated \c iterations_outerloop times. \n
       * The ratio of inner and outer loop iterations significantly defines the contraction behavior 
       * and convergence rate of the trajectory optimization. Based on our experiences, 2-6 innerloop iterations are sufficient. \n
       * The number of outer loop iterations should be determined by considering the maximum CPU time required to match the control rate. \n
       * @remarks This method is usually called from a plan() method
       * @param iterations_innerloop Number of iterations for the actual solver loop
       * @param iterations_outerloop Specifies how often the trajectory should be resized followed by the inner solver loop.
       * @return \c true if the optimization terminates successfully, \c false otherwise
       */	  
      bool optimizeTEB(int iterations_innerloop, int iterations_outerloop);

      /**
       * @brief the function to initialize the Pose and time_diff vector
       * @param  plan The plan to derive the pose and time_diff vector from
       */
      bool initializeTEBTuples(const std::vector<geometry_msgs::PoseStamped>& plan);

        /**
       * @brief Build the hyper-graph representing the TEB optimization problem.
       * 
       * This method creates the optimization problem according to the hyper-graph formulation. \n
       * For more details refer to the literature cited in the TebOptimalPlanner class description.
       * @see optimizeGraph
       * @see clearGraph
       * @param weight_multiplier Specify a weight multipler for selected weights in optimizeGraph
       *                          This might be used for weight adapation strategies.
       *                          Currently, only obstacle collision weights are considered.
       * @return \c true, if the graph was created successfully, \c false otherwise.
       */
      bool buildGraph(double weight_multiplier=1.0);

        /**
       * @brief Optimize the previously constructed hyper-graph to deform / optimize the TEB.
       * 
       * This method invokes the g2o framework to solve the optimization problem considering dedicated sparsity patterns. \n
       * The current implementation calls a non-constrained sparse Levenberg-Marquardt algorithm. Constraints are considered
       * by utilizing penalty approximations. Refer to the literature cited in the TebOptimalPlanner class description.
       * @see buildGraph
       * @see clearGraph
       * @param no_iterations Number of solver iterations
       * @param clear_after Clear the graph after optimization.
       * @return \c true, if optimization terminates successfully, \c false otherwise.
       */
      bool optimizeGraph(int no_iterations, bool clear_after=true);

        /**
       * @brief Add all relevant vertices to the hyper-graph as optimizable variables.
       * 
       * Vertices (if unfixed) represent the variables that will be optimized. \n
       * In case of the Timed-Elastic-Band poses and time differences form the vertices of the hyper-graph. \n
       * The order of insertion of vertices (to the graph) is important for efficiency,
       * since it affect the sparsity pattern of the underlying hessian computed for optimization.
       * @see VertexPose
       * @see VertexTimeDiff
       * @see buildGraph
       * @see optimizeGraph
       */
      void AddTEBVertices();

        /**
       * @brief Add all edges (local cost functions) for satisfying kinematic constraints of a differential drive robot
       * @warning do not combine with AddEdgesKinematicsCarlike()
       * @see AddEdgesKinematicsCarlike
       * @see buildGraph
       * @see optimizeGraph
       */
      void AddEdgesKinematicsDiffDrive();

      /**
       * @brief Add all edges (local cost functions) related to keeping a distance from static obstacles
       * @warning do not combine with AddEdgesInflatedObstacles
       * @see EdgeObstacle
       * @see buildGraph
       * @see optimizeGraph
       * @param weight_multiplier Specify an additional weight multipler (in addition to the the config weight)
       */
      void AddEdgesObstacles(double weight_multiplier=1.0);

        /**
       * @brief Add all edges (local cost functions) for limiting the translational and angular acceleration.
       * @see EdgeAcceleration
       * @see EdgeAccelerationStart
       * @see EdgeAccelerationGoal
       * @see buildGraph
       * @see optimizeGraph
       */
      void AddEdgesAcceleration();

        
      /**
       * @brief Add all edges (local cost functions) related to minimizing the distance to via-points
       * @see EdgeViaPoint
       * @see buildGraph
       * @see optimizeGraph
       */
      void AddEdgesViaPoints();

        /**
       * @brief Add all edges (local cost functions) for minimizing the transition time (resp. minimize time differences)
       * @see EdgeTimeOptimal
       * @see buildGraph
       * @see optimizeGraph
       */
      void AddEdgesTimeOptimal();

      /**
       * @brief Add all edges (local cost functions) for minimizing the path length
       * @see EdgeShortestPath
       * @see buildGraph
       * @see optimizeGraph
       */
      void AddEdgesShortestPath();

        /**
       * @brief Add all edges (local cost functions) for limiting the translational and angular velocity.
       * @see EdgeVelocity
       * @see buildGraph
       * @see optimizeGraph
       */
      void AddEdgesVelocity();

        /**
       * @brief Append a new pose vertex to the back of the pose sequence 
       * @param pose PoseSE2 to push back on the internal PoseSequence
       * @param fixed Mark the pose to be fixed or unfixed during trajectory optimization (important for the TebOptimalPlanner)
       */
      void addPose(const PoseSE2& pose, bool fixed=false); 

        /**
       * @brief Set a pose vertex at pos \c index of the pose sequence to be fixed or unfixed during optimization.
       * @param index index to the pose vertex
       * @param status if \c true, the vertex will be fixed, otherwise unfixed
       */
      void setPoseVertexFixed(int index, bool status);

        /**
       * @brief Append a (pose, timediff) vertex pair to the end of the current trajectory (pose and timediff sequences)
       * @param pose PoseSE2 to push back on the internal PoseSequence
       * @param dt time difference value to push back on the internal TimeDiffSequence
       * @warning 	Since the timediff is defined to connect two consecutive poses, this call is only 
       * 		allowed if there exist already n poses and n-1 timediffs in the sequences (n=1,2,...):
       * 		therefore add a single pose using addPose() first!
       */
      void addPoseAndTimeDiff(const PoseSE2& pose, double dt);

        /**
       * @brief Append a new time difference vertex to the back of the time diff sequence 
       * @param dt time difference value to push back on the internal TimeDiffSequence
       * @param fixed Mark the pose to be fixed or unfixed during trajectory optimization (important for the TebOptimalPlanner)
       */
      void addTimeDiff(double dt, bool fixed=false);


      void createObstacleEdge(int index, double weight_multiplier, Obstacle* obstacle);

      /**
       * @brief Find the closest point on the trajectory w.r.t. to a provided reference point.
       * 
       * This function can be useful to find the part of a trajectory that is close to an obstacle.
       * 
      
        /**
       * @brief Get the velocity command from a previously optimized plan to control the robot at the current sampling interval.
       * @warning Call plan() first and check if the generated plan is feasible.
       * @param[out] vx translational velocity [m/s]
       * @param[out] vy strafing velocity which can be nonzero for holonomic robots[m/s] 
       * @param[out] omega rotational velocity [rad/s]
       * @return \c true if command is valid, \c false otherwise
       */
      virtual bool getVelocityCommand(double& vx, double& vy, double& omega) const;
      
        /**
       * @brief Extract the velocity from consecutive poses and a time difference (including strafing velocity for holonomic robots)
       * 
       * The velocity is extracted using finite differences.
       * The direction of the translational velocity is also determined.
       * @param pose1 pose at time k
       * @param pose2 consecutive pose at time k+1
       * @param dt actual time difference between k and k+1 (must be >0 !!!)
       * @param[out] vx translational velocity
       * @param[out] vy strafing velocity which can be nonzero for holonomic robots
       * @param[out] omega rotational velocity
       */
      inline void extractVelocity(const PoseSE2& pose1, const PoseSE2& pose2, double dt, double& vx, double& vy, double& omega) const;
      

      

      costmap_2d::Costmap2DROS* costmap_ros_; ///< @brief The ROS wrapper for the costmap the controller will use
      costmap_2d::Costmap2D* costmap_; ///< @brief The costmap the controller will use
      tf2_ros::Buffer* tf_;
      std::string global_frame_; ///< @brief The frame in which the controller will run
      std::string robot_base_frame_; ///< @brief Used as the base frame id of the robot
      std::vector<geometry_msgs::Point> robot_footprint_;
      base_local_planner::CostmapModel* costmap_model_;
      double robot_inscribed_radius_, robot_circumscribed_radius_;

      bool reached_goal_;
      std::vector<geometry_msgs::PoseStamped> global_plan_;
      bool initialized_;

      ros::Publisher g_plan_pub_, l_plan_pub_;

      int id_counter_;

      bool prune_plan_;
      base_local_planner::OdometryHelperRos odom_helper_;
      bool xy_tolerance_latch_, latch_xy_goal_tolerance_;
      double yaw_goal_tolerance_, xy_goal_tolerance_;
      bool rotating_to_goal_;
      double acc_lim_x_, acc_lim_y_, acc_lim_theta_;
      double sim_period_;
      double min_vel_th_, max_vel_th_, min_in_place_vel_th_;
      double rot_stopped_velocity_, trans_stopped_velocity_;
      double costmap_obstacles_behind_robot_dist_;
      int control_look_ahead_poses_;
      double min_waypoint_separation_;
      int min_samples_;
      double max_vel_x_, max_vel_theta_;
      double weight_adapt_factor_;
      int no_inner_iterations_, no_outer_iterations_;
      double min_obstacle_dist_;

      // Weights for cost function
      double weight_obstacle_, weight_waypoint_;
      double weight_max_vel_theta_, weight_max_vel_x_;
      double weight_acc_lim_theta_, weight_acc_lim_x_;
      double weight_optimaltime_, weight_shortest_path_;
      double weight_kinematics_nh_, weight_kinematics_forward_drive_;

      PoseSE2 robot_pose_; //!< Store current robot pose
      PoseSE2 robot_goal_; //!< Store current robot goal
      geometry_msgs::Twist robot_vel_; //!< Store current robot translational and angular velocity (vx, vy, omega)
      ObstContainer obstacles_; //!< Obstacle vector that should be considered during local trajectory optimization
      ViaPointContainer via_points_; //!< Container of via-points that should be considered during local trajectory optimization
      PoseSequence pose_vec_; //!< Internal container storing the sequence of optimzable pose vertices
      TimeDiffSequence timediff_vec_;  //!< Internal container storing the sequence of optimzable timediff vertices
      boost::shared_ptr<g2o::SparseOptimizer> optimizer_; //!< g2o optimizer for trajectory optimization
  };
};

#endif