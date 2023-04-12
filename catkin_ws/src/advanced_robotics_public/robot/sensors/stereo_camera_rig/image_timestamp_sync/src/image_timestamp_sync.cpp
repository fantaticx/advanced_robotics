#include <ros/ros.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/synchronizer.h>
#include <message_filters/subscriber.h>
#include <sensor_msgs/Image.h>

#include <image_transport/publisher.h>
#include <image_transport/image_transport.h>

typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::Image, sensor_msgs::Image> MySyncPolicy;

class Image_handler
{
    public:
        Image_handler():sync_(MySyncPolicy(10), left_image_, right_image_), it_(nh_)
        {  
            left_image_.subscribe(nh_, "/stereo_camera/left/image_raw", 1);
            right_image_.subscribe(nh_, "/stereo_camera/right/image_raw", 1);
            sync_.registerCallback(boost::bind(&Image_handler::image_callback,this, _1, _2));
            left_sync_ = it_.advertise("/stereo_camera/left/image_raw_sync", 1, this);
            right_sync_ = it_.advertise("/stereo_camera/right/image_raw_sync", 1, this);
        }
        void image_callback(const sensor_msgs::ImageConstPtr& left, const sensor_msgs::ImageConstPtr& right);
        
    private:
        ros::NodeHandle nh_;
        message_filters::Subscriber<sensor_msgs::Image> left_image_;
        message_filters::Subscriber<sensor_msgs::Image> right_image_;
        message_filters::Synchronizer<MySyncPolicy> sync_;
        image_transport::ImageTransport it_;
        image_transport::Publisher left_sync_;
        image_transport::Publisher right_sync_;
};

void Image_handler::image_callback(const sensor_msgs::ImageConstPtr& left, const sensor_msgs::ImageConstPtr& right)
{
    left_sync_.publish(left);
    right_sync_.publish(right);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "image_timestamp_sync");
    Image_handler image_handler;
    ros::spin();
    return 0;
}
