#ifndef FRONTIER_EXPLORATION_H
#define FRONTIER_EXPLORATION_H

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/Pose2D.h>
#include <visualization_msgs/MarkerArray.h>


#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <tf2_ros/transform_listener.h>


namespace exploration_cascade
{
  typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

  class FrontierExploration
  {
    public:
      FrontierExploration(ros::NodeHandle n, tf2_ros::Buffer& tf_buffer);

      void mapCallback(const nav_msgs::OccupancyGrid::ConstPtr& msg);
      void startExplorationCascade();

    private:
      std::vector<int> findFrontierRegions();
      std::vector<int> findFrontierEdgeCells();
      int getRegionCentroid(std::vector<int>& frontier_edge_cells);
      void gotoGoal(double x, double y, double theta);
      geometry_msgs::Pose2D getRobotPose();
      
      //std::vector<int> getNeighbours(int cell_idx);
      int getCellIndex(int x, int y);
      int mapX(int cell_idx);
      int mapY(int cell_idx);
      double worldX(int cell_idx);
      double worldY(int cell_idx);
      bool worldToMap(double world_x, double world_y, int& map_x, int& map_y);
      bool mapToWorld(int map_x, int map_y, double& world_x, double& world_y);
      void visualizeMarkers(std::vector<int>& frontier_region_centroids);
      visualization_msgs::Marker createFrontierMarker(double x, double y);
      void sensorSweep();
      void waitForMap();

      const int8_t UNOCCUPIED=0;
      const int8_t OCCUPIED=100;
      const int8_t UNKNOWN=-1;
      
      MoveBaseClient mb_action_client_;
      boost::mutex* data_mutex_;
      tf::TransformListener* tf_listener_;
      ros::NodeHandle nh_;
      tf2_ros::Buffer& tf_buffer_;
      ros::Publisher cmd_vel_;
      ros::Publisher marker_pub_;

      bool map_received_;

      nav_msgs::OccupancyGrid map_;
      unsigned int max_x_position_;
      unsigned int max_y_position_;


  };
}
#endif // FRONTIER_EXPLORATION_H
