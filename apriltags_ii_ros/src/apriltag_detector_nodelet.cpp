#include <apriltags_ii_ros/apriltag_detector.h>
#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>



namespace apriltags_ii_ros{

class AprilTagDetectorNodelet : public nodelet::Nodelet
{

public:
  AprilTagDetectorNodelet(){}

private:
  void onInit(){
    detector_.reset(new AprilTagDetector(getNodeHandle(), getPrivateNodeHandle()));
  }
  boost::shared_ptr<AprilTagDetector> detector_;

};

}

PLUGINLIB_DECLARE_CLASS(apriltags_ii_ros, AprilTagDetectorNodelet, apriltags_ii_ros::AprilTagDetectorNodelet, nodelet::Nodelet);