#include <g2o_based_mapping/g2o_based_mapping.h>

#include <Eigen/StdVector>
#include <thread>

#include "g2o/types/slam2d/vertex_point_xy.h"
#include "g2o/types/slam2d/edge_se2_pointxy.h"
#include "g2o/types/slam2d/vertex_se2.h"
#include "g2o/types/slam2d/edge_se2.h"

#include "g2o/core/block_solver.h"
#include "g2o/core/factory.h"
#include "g2o/core/optimization_algorithm_factory.h"
#include "g2o/core/optimization_algorithm_gauss_newton.h"
#include "g2o/solvers/csparse/linear_solver_csparse.h"

#include "nabo/nabo.h"

#include <fstream>

G2oBasedMapping::G2oBasedMapping(ros::NodeHandle n)
{
    data_mutex_ = new boost::mutex();
    tf_listener_ = new tf::TransformListener(n);
    nh_ = n;
    x = Eigen::MatrixXd::Zero(3,1);

    typedef g2o::LinearSolverCSparse<g2o::BlockSolverX::PoseMatrixType> SlamLinearSolver;

    auto linearSolver = g2o::make_unique<SlamLinearSolver>();
    linearSolver->setBlockOrdering(false);
    //std::unique_ptr<g2o::Solver> solver(new g2o::BlockSolverX(linearSolver));
    g2o::OptimizationAlgorithmGaussNewton *algorithm = new g2o::OptimizationAlgorithmGaussNewton(g2o::make_unique<g2o::BlockSolverX>(std::move(linearSolver)));
    graph_.setAlgorithm(algorithm);

    // Use standard dimensions for the map publishing, as we already know the actual map size. 
    // In real unknown environments, the map size has to be dynamic!
    graph_map.header.frame_id = "map";
    graph_map.header.stamp = ros::Time::now();
    graph_map.info.map_load_time = ros::Time::now();
    graph_map.info.resolution = 0.05;
    graph_map.info.width = 560;
    graph_map.info.height = 360;
    geometry_msgs::Pose origin;
    origin.position.x = -19.5;
    origin.position.y = -9.0;
    origin.orientation.w = 1.0;
    graph_map.info.origin = origin;

    laser_params_ = 0;

    init(10,28,0);

    // TODO
    // find appropriate parameters
    double x_noise = 1;
    double y_noise = 1;
    double rot_noise = 1;    //rad
    double landmark_x_noise = 1;
    double landmark_y_noise = 1;

    odom_noise_.fill(0.);
    odom_noise_(0, 0) = 1/(x_noise*x_noise);
    odom_noise_(1, 1) = 1/(y_noise*y_noise);
    odom_noise_(2, 2) = 1/(rot_noise*rot_noise);

    laser_noise_.fill(0.);
    laser_noise_(0, 0) = 1;
    laser_noise_(1, 1) = 1;
    laser_noise_(2, 2) = 1;

    landmark_noise_.fill(0.);
    landmark_noise_(0, 0) = 1/(landmark_x_noise*landmark_x_noise);
    landmark_noise_(1, 1) = 1/(landmark_y_noise*landmark_y_noise);
}

void G2oBasedMapping::updateOdometry(nav_msgs::Odometry odometry)
{

    if (reset_)
    {
        last_odometry = odometry;
        updateLocalization();
        
        init(odometry.pose.pose.position.x, odometry.pose.pose.position.y, tf::getYaw(odometry.pose.pose.orientation));
        
        reset_ = false;
        valid_ = false;
        return;
    }

    // TODO
    // 1. Enter your odometry update here
    // 2. Keep track of the odometry updates to the robot position

    // global variable last_odometry contains the last odometry position estimation (ROS Odometry Messasge)
    // local variable odometry contains the current odometry position estimation (ROS Odometry Messasge)

    // local variable x holds your position (Eigen vector of size 3 [x,y,theta])

    // Keep This - reports your update
    last_odometry = odometry;

}

void G2oBasedMapping::updateLaserScan(sensor_msgs::LaserScan scan)
{

    if (!laser_params_ || graph_.vertices().size() == 0)
    {
        // first laser update
        laser_params_ = new g2o::LaserParameters(scan.ranges.size(), scan.angle_min, scan.angle_increment, scan.range_max);
        addLaserVertex(x(0), x(1), x(2), scan, last_id_, true);
        return;
    }

    // TODO
    // 1. Enter your laser scan update here
    // 2. Build up the pose graph by adding odometry and laser edges
    // 3. Check for loop closures
    // 4. Optimize the graph


    // Keep This - reports your update
    updateLocalization();
    visualizeRobotPoses();
    // Keep This - if you like to visualize your map (collected laser scans in the graph)
    visualizeLaserScans();
}

sensor_msgs::LaserScan G2oBasedMapping::rawLasertoLaserScanMsg(g2o::RawLaser rawlaser)
{
    sensor_msgs::LaserScan msg;

    msg.header.frame_id = "base_laser_link";
    msg.angle_min = rawlaser.laserParams().firstBeamAngle;
    msg.angle_increment = rawlaser.laserParams().angularStep;
    msg.range_min = 0;
    msg.range_max = rawlaser.laserParams().maxRange;

    std::vector<double>::const_iterator it = rawlaser.ranges().begin();
    msg.ranges.assign(it, rawlaser.ranges().end());

    //static ros::Publisher pub = nh_.advertise<sensor_msgs::LaserScan>("scan_match", 0);
    //pub.publish(msg);

    return msg;
}


void G2oBasedMapping::visualizeLaserScans()
{
    sensor_msgs::PointCloud graph_cloud;
    graph_cloud.header.frame_id = "map";
    graph_cloud.header.stamp = ros::Time::now();
    double laser_x_trans = 0.38;
    
    for(int j = 0; j < robot_pose_ids_.size(); j++)
    {
        std::vector<double> data;
        graph_.vertex(robot_pose_ids_[j])->getEstimateData(data);

        g2o::OptimizableGraph::Data* d = graph_.vertex(robot_pose_ids_[j])->userData();

        g2o::RawLaser* rawLaser = dynamic_cast<g2o::RawLaser*>(d);
        if (rawLaser)
        {
            float angle = rawLaser->laserParams().firstBeamAngle;
            for(std::vector<double>::const_iterator i = rawLaser->ranges().begin(); i != rawLaser->ranges().end(); i++)
            {
                geometry_msgs::Point32 p;
                float x = *i*cos(angle);
                float y = *i*sin(angle);
                p.x = data[0] + laser_x_trans * std::cos(data[2]) + x*cos(data[2])-y*sin(data[2]);
                p.y = data[1] + laser_x_trans * std::sin(data[2]) + x*sin(data[2])+y*cos(data[2]);
                p.z = 0;
                angle += rawLaser->laserParams().angularStep;
                graph_cloud.points.push_back(p);

            }
        }
    }


    static ros::Publisher pub = nh_.advertise<sensor_msgs::PointCloud>("graph_cloud", 0);
    pub.publish(graph_cloud);
}

void G2oBasedMapping::visualizeRobotPoses()
{

    visualization_msgs::Marker marker;
    visualization_msgs::MarkerArray marker_array;

    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();
    marker.ns = "robot_poses";
    marker.pose.position.z = 0.0;
    marker.type = visualization_msgs::Marker::SPHERE;
    marker.action = visualization_msgs::Marker::ADD;
    marker.scale.x = 0.2;
    marker.scale.y = 0.2;
    marker.scale.z = 0.2;
    marker.color.a = 0.5;
    marker.color.r = 0.1;
    marker.color.g = 0.1;
    marker.color.b = 0.9;

    for(int j = 0; j < robot_pose_ids_.size(); j++)
    {
        // Sphere Marker
        std::vector<double> data;
        graph_.vertex(robot_pose_ids_[j])->getEstimateData(data);
        marker.pose.position.x = data[0];
        marker.pose.position.y = data[1];
        marker.id = robot_pose_ids_[j];
        marker_array.markers.push_back(marker);
    }

    static ros::Publisher pub = nh_.advertise<visualization_msgs::MarkerArray>("robot_pose_marker", 0);
    pub.publish(marker_array);

    visualizeEdges();
}


void G2oBasedMapping::visualizeLandmarks()
{
    visualization_msgs::Marker marker;
    visualization_msgs::Marker marker_text;;
    visualization_msgs::MarkerArray marker_array;
    visualization_msgs::MarkerArray marker_array_text;

    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();
    marker.pose.position.z = 0.0;
    marker.ns = "observed_fiducials";
    marker.type = visualization_msgs::Marker::SPHERE;
    marker.action = visualization_msgs::Marker::ADD;
    marker.scale.x = 0.6;
    marker.scale.y = 0.6;
    marker.scale.z = 0.6;
    marker.color.a = 0.5;
    marker.color.r = 1.0;
    marker.color.g = 0.3;
    marker.color.b = 0.0;
    
    marker_text.header = marker.header;
    marker_text.ns = "observed_fiducials_text";
    marker_text.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
    marker_text.action = visualization_msgs::Marker::ADD;
    marker_text.scale.z = 0.6*0.85;
    marker_text.color.a = 0.7;
    marker_text.color.r = 0.0;
    marker_text.color.g = 0.0;
    marker_text.color.b = 0.0;
    
    for(int j = 0; j < seen_landmarks_.size(); j++)
    {
        // Sphere Marker
        std::vector<double> data;
        graph_.vertex(seen_landmarks_[j])->getEstimateData(data);

        marker.pose.position.x = data[0];
        marker.pose.position.y = data[1];
        marker.id = seen_landmarks_[j];
        marker_array.markers.push_back(marker);

        // Text Marker
        marker_text.pose.position = marker.pose.position;
        marker_text.id = seen_landmarks_[j];
        marker_text.text = arg_cast<std::string>(marker_text.id);
        marker_array_text.markers.push_back(marker_text);
    }

    static ros::Publisher pub = nh_.advertise<visualization_msgs::MarkerArray>("fiducials_observed_marker", 0);
    pub.publish(marker_array);

    static ros::Publisher pub2 = nh_.advertise<visualization_msgs::MarkerArray>("fiducials_observed_marker", 0);
    pub2.publish(marker_array_text);

    visualizeEdges();
}


void G2oBasedMapping::visualizeEdges()
{
    visualization_msgs::Marker marker;
    visualization_msgs::MarkerArray marker_array;

    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();
    marker.scale.x = 0.05;
    marker.scale.y = 0.05;
    marker.scale.z = 0.05;
    marker.color.a = 0.5;
    marker.color.r = 0.9;
    marker.color.g = 0.1;
    marker.color.b = 0.1;
    marker.id = 0;
    marker.type = visualization_msgs::Marker::LINE_STRIP;
    marker.action = visualization_msgs::Marker::ADD;
    marker.ns = "edges";

    geometry_msgs::Point p;
    p.z = 0;

    std::vector<double> data;

    for(int j = 0; j < robot_pose_ids_.size(); j++)
    {
        graph_.vertex(robot_pose_ids_[j])->getEstimateData(data);

        p.x = data[0];
        p.y = data[1];
        marker.points.push_back(p);
    }


    static ros::Publisher pub = nh_.advertise<visualization_msgs::Marker>("graph_edges", 0);
    pub.publish(marker);

    marker.points.clear();
    marker.id = 1;
    marker.type = visualization_msgs::Marker::LINE_LIST;

    for(int j = 0; j < robot_landmark_edge_ids_.size(); j++)
    {
        graph_.vertex(robot_landmark_edge_ids_[j].first)->getEstimateData(data);
        p.x = data[0];
        p.y = data[1];
        marker.points.push_back(p);

        graph_.vertex(robot_landmark_edge_ids_[j].second)->getEstimateData(data);
        p.x = data[0];
        p.y = data[1];
        marker.points.push_back(p);
    }

    for(int j = 0; j < laser_edge_ids_.size(); j++)
    {
        graph_.vertex(laser_edge_ids_[j].first)->getEstimateData(data);
        p.x = data[0];
        p.y = data[1];
        marker.points.push_back(p);

        graph_.vertex(laser_edge_ids_[j].second)->getEstimateData(data);
        p.x = data[0];
        p.y = data[1];
        marker.points.push_back(p);
    }



    pub.publish(marker);
}

void G2oBasedMapping::visualizeOldLandmarks()
{
    visualization_msgs::Marker marker;
    visualization_msgs::Marker marker_text;;
    visualization_msgs::MarkerArray marker_array;
    visualization_msgs::MarkerArray marker_array_text;

    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();
    marker.pose.position.z = 0.0;
    marker.type = visualization_msgs::Marker::SPHERE;
    marker.action = visualization_msgs::Marker::ADD;
    marker.scale.x = 0.6;
    marker.scale.y = 0.6;
    marker.scale.z = 0.6;
    marker.color.a = 0.5;
    marker.color.r = 0.1;
    marker.color.g = 0.1;
    marker.color.b = 0.8;
    marker.ns = "old_observed_fiducials";

    marker_text.header = marker.header;
    marker_text.pose.position = marker.pose.position;
    marker_text.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
    marker_text.action = visualization_msgs::Marker::ADD;
    marker_text.scale.z = 0.6*0.85;
    marker_text.color.a = 0.7;
    marker_text.color.r = 0.0;
    marker_text.color.g = 0.0;
    marker_text.color.b = 0.0;
    marker_text.ns = "old_observed_fiducials_text";

    for(int j = 0; j < seen_landmarks_.size(); j++)
    {
        // Sphere Marker
        std::vector<double> data;
        graph_.vertex(seen_landmarks_[j])->getEstimateData(data);

        marker.pose.position.x = data[0];
        marker.pose.position.y = data[1];
        marker.id = seen_landmarks_[j];
        marker_array.markers.push_back(marker);

        // Text Marker
        marker_text.id = seen_landmarks_[j];
        marker_text.text = arg_cast<std::string>(marker_text.id);
        marker_array_text.markers.push_back(marker_text);
    }

    static ros::Publisher pub = nh_.advertise<visualization_msgs::MarkerArray>("old_fiducials_observed_marker", 0);
    pub.publish(marker_array);

    static ros::Publisher pub2 = nh_.advertise<visualization_msgs::MarkerArray>("old_fiducials_observed_marker", 0);
    pub2.publish(marker_array_text);
}


void G2oBasedMapping::init(double x, double y, double theta)
{
    this->x(0,0) = x;
    this->x(1,0) = y;
    this->x(2,0) = theta;

    graph_.clear();
    edge_set_.clear();
    vertex_set_.clear();
    seen_landmarks_.clear();
    robot_pose_ids_.clear();
    robot_landmark_edge_ids_.clear();
    laser_edge_ids_.clear();
    min_to_optimize_ = 4;
    last_id_ = 30;
    valid_ = false;
    reset_ = true;
    robot_pose_set = true;
    first_opt_ = true;
    visualizeOldLandmarks();
    visualizeLandmarks();
    visualizeRobotPoses();
    visualizeEdges();
}

void G2oBasedMapping::updateLocalization()
{
    tf::Transform transform;
    transform.setOrigin( tf::Vector3(x(0,0), x(1,0), 0.0) );
    transform.setRotation( tf::createQuaternionFromRPY(0 , 0, x(2,0)) );
    pose_tf_broadcaster.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "map", "base_link_g2o"));
}

void G2oBasedMapping::laserscanCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
    data_mutex_->lock();
    updateLaserScan(*msg);
    data_mutex_->unlock();
}

void G2oBasedMapping::odometryCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
    data_mutex_->lock();
    updateOdometry(*msg);
    data_mutex_->unlock();
}

void G2oBasedMapping::initialposeCallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
    double x, y, theta;
    data_mutex_->lock();
    x = msg->pose.pose.position.x;
    y = msg->pose.pose.position.y;
    theta =  tf::getYaw(msg->pose.pose.orientation);
    ROS_INFO("initalPoseCallback x=%f, y=%f, theta=%f", x, y, theta);
    init(x, y, theta);
    data_mutex_->unlock();
}

void G2oBasedMapping::addOdomVertex(double x, double y, double theta, int id, bool first)
{
    g2o::SE2 pose(x, y, theta);
    g2o::VertexSE2* vertex = new g2o::VertexSE2;
    vertex->setId(id);
    vertex->setEstimate(pose);
    graph_.addVertex(vertex);
    vertex_set_.insert(vertex);
    robot_pose_ids_.push_back(id);
    if(first)
        vertex->setFixed(true);
}

void G2oBasedMapping::addLaserVertex(double x, double y, double theta, sensor_msgs::LaserScan scan, int id, bool first)
{
    g2o::SE2 pose(x, y, theta);
    g2o::VertexSE2* vertex = new g2o::VertexSE2;
    vertex->setId(id);
    vertex->setEstimate(pose);
    g2o::RawLaser * rl = new g2o::RawLaser();
    rl->setLaserParams(*laser_params_);
    std::vector<double> r;
    std::vector<float>::iterator it = scan.ranges.begin();
    r.assign(it, scan.ranges.end());
    rl->setRanges(r);
    vertex->addUserData(rl);
    graph_.addVertex(vertex);
    vertex_set_.insert(vertex);
    robot_pose_ids_.push_back(id);
    if(first)
        vertex->setFixed(true);
}



void G2oBasedMapping::addLaserEdge(int id1, int id2, double x, double y, double yaw, Eigen::Matrix3d noise)
{
    g2o::EdgeSE2* edge = new g2o::EdgeSE2;
    edge->vertices()[0] = graph_.vertex(id1);
    edge->vertices()[1] = graph_.vertex(id2);
    edge->setMeasurement(g2o::SE2(x,y,yaw));
    edge->setInformation(noise);

    laser_edge_ids_.push_back(std::pair<int, int>(id1, id2));

    graph_.addEdge(edge);
    edge_set_.insert(edge);
    std::cout << "added laser edge: " << id1 << " - " << id2 << std::endl;
}

void G2oBasedMapping::addOdomEdge(int id1, int id2)
{
    std::vector<double> data1,data2;

    graph_.vertex(id1)->getEstimateData(data1);
    graph_.vertex(id2)->getEstimateData(data2);

    g2o::SE2 vertex1(data1[0], data1[1], data1[2]);
    g2o::SE2 vertex2(data2[0], data2[1], data2[2]);

    g2o::SE2 transform = vertex1.inverse() * vertex2;
    g2o::EdgeSE2* edge = new g2o::EdgeSE2;
    edge->vertices()[0] = graph_.vertex(id1);
    edge->vertices()[1] = graph_.vertex(id2);
    edge->setMeasurement(transform);
    edge->setInformation(odom_noise_);

    graph_.addEdge(edge);
    edge_set_.insert(edge);
    std::cout << "added odometry edge: " << id1 << " - " << id2 << std::endl;
}

void G2oBasedMapping::addLandmarkVertex(double x, double y, int id)
{
    if(graph_.vertex(id))
        return;

    Eigen::Vector2d pos(x, y);
    seen_landmarks_.push_back(id);
    g2o::VertexPointXY *vertex = new g2o::VertexPointXY;
    vertex->setId(id);
    vertex->setEstimate(pos);
    graph_.addVertex(vertex);
    vertex_set_.insert(vertex);
}

void G2oBasedMapping::addLandmarkEdge(int id1, int id2, double x, double y)
{
    std::vector<double> data;
    graph_.vertex(id1)->getEstimateData(data);

    g2o::SE2 vertex1(data[0], data[1], data[2]);
    Eigen::Vector2d vertex2(x, y);
    Eigen::Vector2d measurement;
    measurement = vertex1.inverse() * vertex2;

    g2o::EdgeSE2PointXY* landmark_edge =  new g2o::EdgeSE2PointXY;
    landmark_edge->vertices()[0] = graph_.vertex(id1);
    landmark_edge->vertices()[1] = graph_.vertex(id2);
    landmark_edge->setMeasurement(measurement);
    landmark_edge->setInformation(landmark_noise_);
    graph_.addEdge(landmark_edge);
    edge_set_.insert(landmark_edge);
    robot_landmark_edge_ids_.push_back(std::pair<int, int>(id1, id2));
    std::cout << "added landmark edge: " << id1 << " - " << id2 << std::endl;
}

void G2oBasedMapping::optimizeGraph()
{
    graph_.save("state_before.g2o");
    graph_.setVerbose(true);
    visualizeOldLandmarks();
    std::cout << "Optimizing" << std::endl;

    if(first_opt_)
    {
        if(!graph_.initializeOptimization())
            std::cerr << "FAILED initializeOptimization";
    }
    else if(!graph_.updateInitialization(vertex_set_, edge_set_))
        std::cerr << "FAILED updateInitialization";

    int iterations = 10;
    graph_.optimize(iterations, !first_opt_);
    graph_.save("state_after.g2o");

    first_opt_ = false;
    vertex_set_.clear();
    edge_set_.clear();
    setRobotToVertex(robot_pose_ids_.back());
}

void G2oBasedMapping::setRobotToVertex(int id)
{
    std::vector<double> data;
    graph_.vertex(id)->getEstimateData(data);

    x(0,0) = data[0];
    x(1,0) = data[1];
    x(2,0) = data[2];

    updateLocalization();
}

void G2oBasedMapping::publishMapThread()
{
    ros::Rate rate(0.2); // ROS Rate at 0.2Hz
    
    while (ros::ok()) {
        ROS_INFO("Publishing map update");
        data_mutex_->lock();
        publishMap();
        data_mutex_->unlock();
        rate.sleep();
    }
}

void G2oBasedMapping::publishMap()
{

    graph_map.header.stamp = ros::Time::now();
    graph_map.info.map_load_time = ros::Time::now();

    int map_size = graph_map.info.width * graph_map.info.height;
    graph_map.data = std::vector<int8_t>(map_size, 0);
    double laser_x_trans = 0.38;
    
    for(int j = 0; j < robot_pose_ids_.size(); j++)
    {
        std::vector<double> data;
        graph_.vertex(robot_pose_ids_[j])->getEstimateData(data);

        g2o::OptimizableGraph::Data* d = graph_.vertex(robot_pose_ids_[j])->userData();

        g2o::RawLaser* rawLaser = dynamic_cast<g2o::RawLaser*>(d);
        if (rawLaser)
        {
            float angle = rawLaser->laserParams().firstBeamAngle;
            for(std::vector<double>::const_iterator i = rawLaser->ranges().begin(); i != rawLaser->ranges().end(); i++)
            {
                geometry_msgs::Point32 p;
                float x = *i*cos(angle);
                float y = *i*sin(angle);
                p.x = data[0] + laser_x_trans * std::cos(data[2]) +x*cos(data[2])-y*sin(data[2]) - graph_map.info.origin.position.x;
                p.y = data[1] + laser_x_trans * std::sin(data[2]) +x*sin(data[2])+y*cos(data[2]) - graph_map.info.origin.position.y;
                angle += rawLaser->laserParams().angularStep;

                int map_x = p.x / graph_map.info.resolution;
                int map_y = p.y / graph_map.info.resolution;

                if (map_x >= 0 && map_y >= 0 && map_x < graph_map.info.width && map_y < graph_map.info.height)
                {
                  graph_map.data[map_y * graph_map.info.width + map_x] = (int8_t) 100;
                }
            }
        }
    }


    static ros::Publisher pub = nh_.advertise<nav_msgs::OccupancyGrid>("graph_map", 0);
    pub.publish(graph_map);
}

int main(int argc, char** argv)
{
    // Initialize ROS
    ros::init (argc, argv, "g2o_based_mapping");
    ros::NodeHandle n;

    G2oBasedMapping* slamar_ptr = new G2oBasedMapping(n);

    ros::Subscriber laserscan = n.subscribe("/front_laser/scan", 1, &G2oBasedMapping::laserscanCallback, slamar_ptr);
    ros::Subscriber odometry = n.subscribe("/gazebo/odom", 1, &G2oBasedMapping::odometryCallback, slamar_ptr);
    ros::Subscriber initialpose = n.subscribe("/initialpose", 1, &G2oBasedMapping::initialposeCallback, slamar_ptr);

    std::thread worker(&G2oBasedMapping::publishMapThread, slamar_ptr);

    std::cout << "g2o based mapping started ..." << std::endl;
    ros::spin();
    worker.join();

    return 0;
}
