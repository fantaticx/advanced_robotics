#include <laser_based_localization_pf/laser_based_localization_pf.h>
#include <occupancy_grid_utils/ray_tracer.h>

LaserBasedLocalizationPf::LaserBasedLocalizationPf(ros::NodeHandle n)
{
    data_mutex_ = new boost::mutex();
    tf_listener_ = new tf::TransformListener(n);

    nh_ = n;

    //Publisher for particles
    particles_pub_ = nh_.advertise<geometry_msgs::PoseArray>("particles", 100);
    pose_with_cov_pub_ = nh_.advertise<geometry_msgs::PoseWithCovarianceStamped>("robot_pose_with_cov",100);
    pose_pub_ = nh_.advertise<geometry_msgs::PoseStamped>("robot_pose_",100);
    vis_pub_ = nh_.advertise<visualization_msgs::Marker>( "uncertainty_marker", 100 );
    laser_pub_ = nh_.advertise<sensor_msgs::LaserScan>("simulated_laser",100);
    real_laser_pub_ = nh_.advertise<sensor_msgs::LaserScan>("real_laser",100);
    x = Eigen::MatrixXd::Zero(3,1);

    //initialize Particles here
    num_particles_ = 100;
    initParticles();
}

void LaserBasedLocalizationPf::initParticles()
{
    ros::ServiceClient map_client = nh_.serviceClient<nav_msgs::GetMap>("static_map");
    ros::service::waitForService("static_map");

    //get map from map server
    nav_msgs::GetMap srv;
    if(!map_client.call(srv))
    {
        ROS_ERROR("Not able to get map from map server!");
        ros::shutdown();
    }
    nav_msgs::OccupancyGrid map = srv.response.map;

    //get max x and y values - use them to distribute your particles over the whole map
    max_y_position_ = static_cast<int>(map.info.height * map.info.resolution);
    max_x_position_ = static_cast<int>(map.info.width * map.info.resolution);

    //TODO
    for(int i = 0; i < num_particles_; i++){
        Particle p;
        double x = ((double) std::rand() / ((double)RAND_MAX+1)) * (max_x_position_+1);
        double y = ((double) std::rand() / ((double)RAND_MAX+1)) * (max_y_position_+1);
        double theta = ((double) std::rand() / ((double)RAND_MAX+1)) * (2 * M_PI);

        p.updatePose(x,y,theta);
        p.weight_ = 1.0;
        particles_.push_back(p);
    }

    //std::cout<<(map.data.at(0)) << std::endl;




    
    // 1.) Initialize the Likelihood Field
    // 2.) Initialize the Sample Set



    //normalize weight of particles
    //normalizeParticleWeights();
}

void LaserBasedLocalizationPf::updateOdometry(nav_msgs::Odometry odometry)
{

    //todo move particles the same way robot moved
    static bool first_call = true;

    if (first_call)
    {
        last_odometry = odometry;
        
        resetLocalization(odometry.pose.pose.position.x, odometry.pose.pose.position.y, tf::getYaw(odometry.pose.pose.orientation));
        
        updateLocalization(x,particles_);
        first_call = false;
        return;
    }

	
	//TODO
    // 1. Enter your odometry update for each particle 

    // global variable last_odometry contains the last odometry position estimation (ROS Odometry Messasge)
    // local variable odometry contains the current odometry position estimation (ROS Odometry Messasge)


    // Keep This - reports your update
    updateLocalization(x, particles_);
    last_odometry = odometry;
}

void LaserBasedLocalizationPf::visualizeSeenLaser(sensor_msgs::LaserScan laser)
{
    static bool first = true;
    if(first)
        laser_info_ = laser;
    first = false;

    tf::Transform transform;
    transform.setOrigin( tf::Vector3(0.38, 0.0, 0.103) );
    transform.setRotation( tf::createQuaternionFromRPY(0, 0, 0) );
    pose_tf_broadcaster_.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "base_link_real", "laser_link_real"));

    laser.header.frame_id = "laser_link_real";
    real_laser_pub_.publish(laser);
}

void LaserBasedLocalizationPf::updateLaser(sensor_msgs::LaserScan laser)
{
    visualizeSeenLaser(laser);

	// TODO
    // 1. Compute the pose of the virutal laser for each particle
    // - keep in mind that the laser is not positioned at the particle (lookup base_laser_link in rviz)
    // 2. Derive the propbality of a laser measurement using the likelihood field
	// 3. Compoute the probability of the particles
   
   
    // normalize your weights
    normalizeParticleWeights();
    // do resampling
    resamplingParticles();

    // Keep This - reports your update
    updateLocalization(x, particles_);
}

void LaserBasedLocalizationPf::resetLocalization(double x, double y, double theta)
{
    this->x(0,0) = x;
    this->x(1,0) = y;
    this->x(2,0) = theta;

    //distribute particles around true pose

    double scale_factor = 1000.0;

    int x_range = static_cast<int>(max_x_position_ / 10.0 * scale_factor);
    int y_range = static_cast<int>(max_y_position_ / 10.0 * scale_factor);
    int theta_range = static_cast<int>(M_PI / 4.0 * scale_factor);
    for(int i = 0; i < particles_.size(); i++)
    {
        double new_x = x + (std::rand() % x_range - static_cast<int>(x_range/2.0) ) / scale_factor;
        double new_y = y + (std::rand() % y_range - static_cast<int>(y_range/2.0) ) / scale_factor;
        double new_theta  = theta + (std::rand() % theta_range - static_cast<int>(theta_range/2.0)) / scale_factor;
        particles_[i].updatePose(new_x, new_y, new_theta);
        particles_[i].weight_ = 1.;
    }
}

void LaserBasedLocalizationPf::updateLocalization(Eigen::MatrixXd x, std::vector<Particle>& particles)
{
    //visualisation of pose
    publishPose(x, particles);

    //visualization of particles
    publishParticles(particles);
}

void LaserBasedLocalizationPf::laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
    data_mutex_->lock();
    updateLaser(*msg);
    updateLocalization(x,particles_);
    data_mutex_->unlock();
}
void LaserBasedLocalizationPf::odometryCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
    data_mutex_->lock();
    updateOdometry(*msg);
    data_mutex_->unlock();
}

void LaserBasedLocalizationPf::initialposeCallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
    double x, y, theta;
    data_mutex_->lock();
    x = msg->pose.pose.position.x;
    y = msg->pose.pose.position.y;
    theta =  tf::getYaw(msg->pose.pose.orientation);
    ROS_INFO("initalPoseCallback x=%f, y=%f, theta=%f", x, y, theta);
    resetLocalization(x, y, theta);
    data_mutex_->unlock();
}

void LaserBasedLocalizationPf::mapCallback(const nav_msgs::OccupancyGrid::ConstPtr& msg)
{
    data_mutex_->lock();
    occ_grid_ = *msg;
    data_mutex_->unlock();
}

void LaserBasedLocalizationPf::normalizeParticleWeights()
{
    // TODO Normalize the particles

    double weight_sum = 0.0;
    for(Particle p: particles_){
        weight_sum += p.weight_;
    }

    for(Particle p : particles_){
        double updated_weight = p.weight_/weight_sum;
        p.updateWeight(updated_weight);
    }


}

void LaserBasedLocalizationPf::resamplingParticles()
{
    // TODO Resample the particles
}

void LaserBasedLocalizationPf::publishParticles(std::vector<Particle>& particles)
{
    geometry_msgs::PoseArray array;
    array.poses = getParticlePositions(particles);
    array.header.frame_id = "map";
    array.header.stamp = ros::Time(0);

    particles_pub_.publish(array);
}

std::vector<geometry_msgs::Pose> LaserBasedLocalizationPf::getParticlePositions(std::vector<Particle>& particles)
{
    std::vector<geometry_msgs::Pose> positions;

    for(int i = 0; i < particles.size(); i++)
        positions.push_back(particles[i].pose_);

    return positions;
}

void LaserBasedLocalizationPf::publishPose(Eigen::MatrixXd& x, std::vector<Particle>& particles)
{
    //calculate mean of given particles
    double x_mean = 0;
    double y_mean = 0;
    double yaw_mean = 0;
	
	// TODO Calculate the robot pose from the particles
	
    x(0,0) = x_mean;
    x(1,0) = y_mean;
    x(2,0) = yaw_mean;

    tf::Transform transform;
    transform.setOrigin( tf::Vector3(x_mean, y_mean, 0.0) );
    transform.setRotation( tf::createQuaternionFromRPY(0 , 0, yaw_mean) );
    pose_tf_broadcaster_.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "map", "base_link_pf"));

    //calculate covariance matrix
    double standard_deviation_x = 0;
    double standard_deviation_y = 0;
    double standard_deviation_theta = 0;

    //todo check if uncertainty possible
    for (int i = 0; i < particles.size(); i++)
    {
        standard_deviation_x += std::pow(particles[i].getX() - x_mean, 2);
        standard_deviation_y += std::pow(particles[i].getY() - y_mean, 2);
        standard_deviation_theta += std::pow(particles[i].getTheta() - yaw_mean, 2);
    }
    standard_deviation_theta = std::sqrt(standard_deviation_theta);
    standard_deviation_x = std::sqrt(standard_deviation_x);
    standard_deviation_y = std::sqrt(standard_deviation_y);
    standard_deviation_theta /= static_cast<double>(particles.size() - 1);
    standard_deviation_x /= static_cast<double>(particles.size() - 1);
    standard_deviation_y /= static_cast<double>(particles.size() - 1);

    //need to bound it otherwise calc of uncertainty marker doesn't work
    double thresh = 0.0000001;
    if(standard_deviation_theta < thresh)
        standard_deviation_theta = thresh;
    if(standard_deviation_x < thresh)
        standard_deviation_x = thresh;
    if(standard_deviation_y < thresh)
        standard_deviation_y = thresh;

    //put in right msg
    geometry_msgs::PoseWithCovarianceStamped pose_with_cov;
    pose_with_cov.header.frame_id = "map";
    pose_with_cov.header.stamp = ros::Time(0);

    tf::Quaternion q;
    q = tf::createQuaternionFromYaw(yaw_mean);

    pose_with_cov.pose.pose.position.x = x_mean;
    pose_with_cov.pose.pose.position.y = y_mean;
    pose_with_cov.pose.pose.position.z = 0;
    pose_with_cov.pose.pose.orientation.w = q.getW();
    pose_with_cov.pose.pose.orientation.x = q.getX();
    pose_with_cov.pose.pose.orientation.y = q.getY();
    pose_with_cov.pose.pose.orientation.z = q.getZ();

    pose_with_cov.pose.covariance[0] = std::pow(standard_deviation_x,2);
    pose_with_cov.pose.covariance[7] = std::pow(standard_deviation_y,2);
    pose_with_cov.pose.covariance[35] = std::pow(standard_deviation_theta,2);
    pose_with_cov_pub_.publish(pose_with_cov);

    // Uncertainty Visualization
    Eigen::Matrix2f uncertainty_mat;
    uncertainty_mat(0,0) = standard_deviation_x * 100.0;
    uncertainty_mat(0,1) = thresh;
    uncertainty_mat(1,0) = thresh;
    uncertainty_mat(1,1) = standard_deviation_y * 100.0;

    Eigen::Vector2f uncertainty_position;
    uncertainty_position(0) = x(0,0);
    uncertainty_position(1) = x(1,0);

    visualization_msgs::Marker uncertainly_marker;
    generateUncertaintyMarker(uncertainly_marker, uncertainty_mat, uncertainty_position);
    vis_pub_.publish(uncertainly_marker);
}

void LaserBasedLocalizationPf::generateUncertaintyMarker(visualization_msgs::Marker& marker, Eigen::Matrix2f uncertainly_mat, Eigen::Vector2f position)
{
    Eigen::EigenSolver<Eigen::Matrix2f> solver(uncertainly_mat);
    Eigen::VectorXf uncertainty_eigenvalues = solver.eigenvalues().real();
    //std::cout << std::endl << "Eigenvalues: " << std::endl << uncertainty_eigenvalues.transpose() << std::endl;
    Eigen::MatrixXf uncertainty_eigenvectors = solver.eigenvectors().real();
    //std::cout << std::endl << uncertainty_eigenvectors << std::endl;

    double phi_ellipse = std::atan2(uncertainty_eigenvectors(0,1), uncertainty_eigenvectors(0,0));

    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time();
    marker.ns = "ellipses";
    marker.id = 0;
    marker.type = visualization_msgs::Marker::CYLINDER;
    marker.action = visualization_msgs::Marker::ADD;
    geometry_msgs::Pose ellipse_pose;

    ellipse_pose.position.x = position(0);
    ellipse_pose.position.y = position(1);
    ellipse_pose.position.z = 0;

    tf::Quaternion tf_quat = tf::createQuaternionFromRPY(0, 0, phi_ellipse);
    tf::quaternionTFToMsg(tf_quat, ellipse_pose.orientation);

    marker.pose = ellipse_pose;

    // eigenvalue of uncertainty matrix is the square of the semi-major/minor of the ellipse;
    // 2.447*sigma => 95% area
    marker.scale.x = 2.447*2.0*std::sqrt(uncertainty_eigenvalues(0));
    marker.scale.y = 2.447*2.0*std::sqrt(uncertainty_eigenvalues(1));
    marker.scale.z = 0.1;
    marker.color.a = 0.2;
    marker.color.r = 0.9;
    marker.color.g = 0.0;
    marker.color.b = 0.3;
}

double LaserBasedLocalizationPf::probNormalDistribution(double a, double variance)
{
    if (variance == 0)
        return a;

    return ( 1.0 / ( std::sqrt(2*M_PI * variance) ) ) * std::exp( -0.5 * std::pow( a, 2.0 ) / variance );

}

double LaserBasedLocalizationPf::sampleNormalDistribution(double variance)
{
    double scaling_factor = 1000.0;
    if (variance <= (1.0/scaling_factor))
        return 0;

    double sum = 0;

    int border = std::sqrt(variance) * static_cast<int>(scaling_factor);
    for (int i = 0; i < 12; i++)
        sum += std::rand() % (2 * border) - border;

    return sum * 0.5 / scaling_factor;

}

sensor_msgs::LaserScan::Ptr LaserBasedLocalizationPf::simulateLaser(double x, double y, double theta, double speedup)
{
    const double laser_x_dist = 0.38;
    const double laser_z_dist = 0.103;
    geometry_msgs::Pose laser_pose;
    laser_pose.position.x = x + laser_x_dist*std::cos(theta);
    laser_pose.position.y = y + laser_x_dist*std::sin(theta);
    laser_pose.position.z = laser_z_dist;
    laser_pose.orientation = tf::createQuaternionMsgFromYaw(theta);

    double inc = laser_info_.angle_increment;
    laser_info_.angle_increment = inc * speedup;
    sensor_msgs::LaserScan::Ptr simulated_laser = occupancy_grid_utils::simulateRangeScan(occ_grid_, laser_pose, laser_info_, true);
    laser_info_.angle_increment = inc;
    return simulated_laser;

}


int main(int argc, char** argv)
{
    // Initialize ROS
    ros::init (argc, argv, "laser_based_localization");
    ros::NodeHandle n;

    LaserBasedLocalizationPf* lmbl_ptr = new LaserBasedLocalizationPf(n);


    ros::Subscriber odometry = n.subscribe("/gazebo/odom", 1, &LaserBasedLocalizationPf::odometryCallback, lmbl_ptr);
    ros::Subscriber initialpose = n.subscribe("/initialpose", 1, &LaserBasedLocalizationPf::initialposeCallback, lmbl_ptr);
    ros::Subscriber map = n.subscribe("/map", 1, &LaserBasedLocalizationPf::mapCallback, lmbl_ptr);
    ros::Subscriber laser_sub = n.subscribe("/front_laser/scan",1, &LaserBasedLocalizationPf::laserCallback, lmbl_ptr);
    //boost::thread(&Controller::stateMachine, controller);

    std::cout << "Laser Based Localization started..." << std::endl;

    ros::spin();

    return 0;
}
