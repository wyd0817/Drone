#include "ros/ros.h"
#include "drone_control.h"

joy_handler_hori::JoySelectedData joystick;

// 通常
void timerCallback(joy_handler_hori::JoySelectedData joystick)
{

	if (joystick.button_ps) {
		
		ROS_INFO("--> button_ps <--");
	}

	if (joystick.button_select and joystick.button_triangle) {
		
		ROS_INFO("--> button_ps <-- 	--> button_triangle <--");
	}


	if (joystick.button_select and joystick.button_circle) {
		
		ROS_INFO("--> button_ps <-- 	--> button_circle <--");
	}

	if(joystick.button_start){

    ROS_INFO("--> button_start <--");
   }

 
  if(joystick.button_select and joystick.button_start){

    ROS_INFO("--> button_select <-- 	--> button_start <--");
   }


   if (joystick.button_r3 ){	

    ROS_INFO("--> button_r3 <--");
   }

}


int main(int argc, char **argv)
{
// ノード名の初期化
ros::init(argc, argv, "drone_control");
// ROSシステムとの通信のためのノードハンドルを宣言
ros::NodeHandle nh;
ros::NodeHandle nh_s;
// 配信者ノードの宣言
// irvs_ros_tutorialsパッケージのmsgTutorialメッセージファイルを
// 利用した配信者ros_tutorial_pubを宣言する。
// トピック名を ros_tutorial_msg とし、配信者キュー( queue )の
// サイズを100に設定する。
// 配信者キューには、メッセージを送る際、メッセージデータを蓄積する。
// http://wiki.ros.org/msg
ros::Publisher ros_tutorial_pub =
nh.advertise<drone_msgs::drone_joint_data>("drone_joint_data", 100);
// ループの周期を設定する。 "10"は10Hzを表し、0.1秒間隔で繰り返される
// http://wiki.ros.org/roscpp/Overview/Time
ros::Rate loop_rate(10);
// メッセージに使用する変数の宣言
int count = 0;


ros::Subscriber sub_joy_selected_data =
			nh_s.subscribe("joy_selected_data", 1, &timerCallback);

// msgTutorialメッセージファイル形式でmsg変数を宣言する。
drone_msgs::drone_joint_data msg;

// メッセージを発行する。約0.1秒間隔で発行される。
ros_tutorial_pub.publish(msg);



// 上で定められたループサイクルになるように、スリープに入る
//loop_rate.sleep();
// count変数に1ずつ増加
//++count;
//}
ros::spin();
return 0;
}
