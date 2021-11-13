#include <ros/ros.h>
#include "std_msgs/Int32.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int msg;
int fd = serialOpen ("/dev/ttyS0", 9600);
std_msgs::Int32 teleop_msg;

void msgCallback(const std_msgs::Int32& teleop_msg){
	msg = teleop_msg.data;
        std::cout << msg << std::endl;
	serialPutchar(fd,msg);
}

int main(int argc, char** argv)
{

  
	ros::init(argc, argv, "teleop_key_sub");
	ros::NodeHandle nh;
	
	ros::Subscriber teleop_sub = nh.subscribe("/teleop_key", 1, msgCallback);
	
	ros::Rate loop_rate(100);
	while(ros::ok())
	{
		ros::spinOnce();
		loop_rate.sleep();
	}
		return 0;
}
