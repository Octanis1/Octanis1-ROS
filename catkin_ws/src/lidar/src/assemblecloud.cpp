#include <ros/ros.h>
#include <laser_assembler/AssembleScans.h>
using namespace laser_assembler;
int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_client");
  ros::NodeHandle n;
  //ros::Publisher chatter_pub = n.advertise<std_msgs::PointCloud>("/assembled_cloud", 1000);
  ros::service::waitForService("assemble_scans");
  ros::ServiceClient client = n.serviceClient<AssembleScans>("assemble_scans");
  AssembleScans srv;
  srv.request.begin = ros::Time(0,0);
  srv.request.end   = ros::Time::now();
  if (client.call(srv))
    printf("Got cloud with %u points\n", srv.response.cloud.points.size());
    
    //n.publish(srv.response.cloud);
  else
    printf("Service call failed\n");
  return 0;
}
