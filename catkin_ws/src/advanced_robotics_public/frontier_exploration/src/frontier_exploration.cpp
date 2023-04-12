#include <frontier_exploration/frontier_exploration.h>
#include <thread>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>
#include <string> 


namespace exploration_cascade
{

FrontierExploration::FrontierExploration(ros::NodeHandle n, tf2_ros::Buffer& tf_buffer) : mb_action_client_("move_base", true), tf_buffer_(tf_buffer)
{
    data_mutex_ = new boost::mutex();
    tf_listener_ = new tf::TransformListener(n);
    nh_ = n;

    max_x_position_ = 0;
    max_y_position_ = 0;
    map_received_ = false;

    cmd_vel_ = nh_.advertise<geometry_msgs::Twist>("cmd_vel", 1);
    marker_pub_ = nh_.advertise<visualization_msgs::MarkerArray>("frontier_markers", 1);

    while(!mb_action_client_.waitForServer(ros::Duration(5.0)))
    {
      ROS_INFO("Waiting for the move_base action server to come up");
    }

}

void FrontierExploration::startExplorationCascade()
{
    waitForMap();

    ROS_INFO("Starting frontier exploration cascade...");

    sensorSweep(); // get initial overview of the environment by turning the robot 360 deg

    // TODO: Implement your exploration algorithm here
    //
    // Use the map to identify frontiers:
    std::vector<int> frontier_regions = findFrontierRegions();
    visualizeMarkers(frontier_regions);

    // TODO:
    // Use the move base action server (gotoGoal()) to navigate the robot to the nearest accessible, unvisited frontier
    // Conduct a 360 deg rotation to update the map (sensorSweep())
    // Repeat until no more frontiers are detected
}

std::vector<int> FrontierExploration::findFrontierRegions()
{
    std::vector<int> frontier_region_centroids;

    //TODO: 
    // Find the frontier edge cells within the map_:
    data_mutex_->lock(); // prevent map updates while identifying edge cells
    std::vector<int> edge_cells = findFrontierEdgeCells();
    data_mutex_->unlock();

    //TODO: 
    // Identify potential frontier regions and calculate their centroid (getRegionCentroid())
    // Return the centroids for the identified regions

    return frontier_region_centroids;
}

std::vector<int> FrontierExploration::findFrontierEdgeCells()
{
    std::vector<int> edge_cells;
    //TODO: find the frontier edge cells within the map (map_). Therefore search for unoccupied cells which have unknown neighbours
    //
    // use mapX(), mapY() to get the cell positions
    // Occupancy grid values: UNOCCUPIED: 0, OCCUPIED: 100, UNKNOWN: -1

    return edge_cells;
}

int FrontierExploration::getRegionCentroid(std::vector<int>& frontier_edge_cells)
{
    // TODO:: calculate the centroid of the frontier and return the cell index of the center
}

void FrontierExploration::gotoGoal(double x, double y, double theta)
{
    move_base_msgs::MoveBaseGoal goal;

    //we'll send a goal to the robot to move 1 meter forward
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();

    goal.target_pose.pose.position.x = x;
    goal.target_pose.pose.position.y = y;

    tf2::Quaternion quat_tf;
    quat_tf.setRPY(0.0, 0.0, theta);
    goal.target_pose.pose.orientation = tf2::toMsg(quat_tf);

    ROS_INFO("Sending goal %f %f %f", x, y, theta);
    mb_action_client_.sendGoal(goal);

    // TODO: wait for goal to be reached or conduct error handling
    //
    // You can check the current state with mb_action_client_.getState()
    // You can use mb_action_client_.waitForResult() for waiting (and optionally give a timeout)
}

geometry_msgs::Pose2D FrontierExploration::getRobotPose()
{
    geometry_msgs::TransformStamped transform_stamped;
    geometry_msgs::Pose2D robot_pose;
    try
    {
      transform_stamped = tf_buffer_.lookupTransform("map", "base_link_robot", ros::Time(0));
      robot_pose.x = transform_stamped.transform.translation.x;
      robot_pose.y = transform_stamped.transform.translation.y;
      robot_pose.theta =tf::getYaw(transform_stamped.transform.rotation);
    }
    catch (tf2::TransformException &ex) {
      ROS_ERROR("Couldn't lookup robot pose!");
      ROS_WARN("%s",ex.what());
    }

    return robot_pose;
}

void FrontierExploration::mapCallback(const nav_msgs::OccupancyGrid::ConstPtr& msg)
{
    ROS_INFO("New Map Received");
    data_mutex_->lock();
    map_ = *msg;

    max_y_position_ = map_.info.height;
    max_x_position_ = map_.info.width;
    data_mutex_->unlock();

    map_received_ = true;
}

void FrontierExploration::sensorSweep()
{
    double rot_speed = 1.0;
    geometry_msgs::Twist twist_;
    twist_.angular.z = rot_speed;

    ros::Time start_time = ros::Time::now();
    ros::Duration duration = ros::Duration(2.5* M_PI / rot_speed); // roughly 2PI / rot_speed including acceleration/slip overhead
    ros::Time end_time = start_time + duration;
    while(ros::Time::now() < end_time )
    {
        cmd_vel_.publish(twist_);

        // Time between messages, so you don't blast out an thousands of 
        // messages in your period
        ros::Duration(0.1).sleep();
    }

    // tell the robot to stop again
    twist_.angular.z = 0.0;
    cmd_vel_.publish(twist_);

}

visualization_msgs::Marker FrontierExploration::createFrontierMarker(double x, double y)
{
    uint32_t shape = visualization_msgs::Marker::CUBE;
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/map";
    marker.header.stamp = ros::Time::now();
    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "basic_shapes" + std::to_string(x) + std::to_string(y);
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = x;
    marker.pose.position.y = y;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.2;
    marker.scale.y = 0.2;
    marker.scale.z = 0.5;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration(5.0);
    return marker;
    
}

void FrontierExploration::visualizeMarkers(std::vector<int>& frontier_region_centroids)
{
    visualization_msgs::MarkerArray marker_array;
    marker_array.markers.resize(frontier_region_centroids.size());

    for (int i = 0; i < frontier_region_centroids.size(); i++)
    {
        int cell_idx = frontier_region_centroids[i];
        double wx, wy;

        if (!mapToWorld(mapX(cell_idx), mapY(cell_idx), wx, wy))
        {
            continue;
        }
        marker_array.markers[i] = createFrontierMarker(wx, wy);
    }
    // Publish the marker
    if (marker_pub_.getNumSubscribers() < 1)
    {
      return;
    }
    marker_pub_.publish(marker_array);
}

void FrontierExploration::waitForMap()
{
    ROS_INFO("Waiting for initial map...");
    while(!map_received_)
    {
        ros::Duration(0.1).sleep();
    }
    ROS_INFO("Map received!");
}

int FrontierExploration::getCellIndex(int x, int y)
{
  return y * max_x_position_ + x;
}

int FrontierExploration::mapX(int cell_idx)
{
  return cell_idx % max_x_position_;
}

int FrontierExploration::mapY(int cell_idx)
{
  return cell_idx / max_x_position_;
}

double FrontierExploration::worldX(int cell_idx)
{
  return mapX(cell_idx) * map_.info.resolution;
}

double FrontierExploration::worldY(int cell_idx)
{
  return mapY(cell_idx) * map_.info.resolution;
}

bool FrontierExploration::worldToMap(double world_x, double world_y, int& map_x, int& map_y)
{
  int x = (world_x - map_.info.origin.position.x) / map_.info.resolution;
  int y = (world_y - map_.info.origin.position.y) / map_.info.resolution;

  if (x >= 0 && y >= 0 && x < max_x_position_ && y < max_y_position_)
  {
      map_x = x;
      map_y = y;
      return true;
  }
  return false;
}

bool FrontierExploration::mapToWorld(int map_x, int map_y, double& world_x, double& world_y)
{
  if (map_x < 0 || map_y < 0 || map_x >= max_x_position_ || map_y >= max_y_position_)
  {
      return false;
  }
  world_x = map_.info.origin.position.x + map_x * map_.info.resolution;
  world_y = map_.info.origin.position.y + map_y * map_.info.resolution;
  return true;
}

} // end of namespace exploration_cascade

using namespace exploration_cascade;

int main(int argc, char** argv)
{
    // Initialize ROS
    ros::init (argc, argv, "frontier_exploration");
    ros::NodeHandle n;
    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener tfListener(tfBuffer);

    FrontierExploration* explorer = new FrontierExploration(n, tfBuffer);

    ros::Subscriber map = n.subscribe("/slam_map", 1, &FrontierExploration::mapCallback, explorer);

    std::cout << "Frontier Exploration Initialized ..." << std::endl;

    std::thread worker(&FrontierExploration::startExplorationCascade, explorer);

    ros::spin();
    worker.join();
    delete explorer;

    return 0;
}
