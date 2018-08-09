// ROSメインヘッダーファイル
// ROSプログラミングを行う際に必要となるROSファイルのインクルードを行う。
// 後述するROS_INFO関数などを使用できるようになる。
#include "ros/ros.h"
#include "drone_control.h"

// 配信者ノードのメイン関数
int main(int argc, char **argv)
{
// ノード名の初期化
ros::init(argc, argv, "drone_control");
// ROSシステムとの通信のためのノードハンドルを宣言
ros::NodeHandle nh;
// 配信者ノードの宣言
// irvs_ros_tutorialsパッケージのmsgTutorialメッセージファイルを
// 利用した配信者ros_tutorial_pubを宣言する。
// トピック名を ros_tutorial_msg とし、配信者キュー( queue )の
// サイズを100に設定する。
// 配信者キューには、メッセージを送る際、メッセージデータを蓄積する。
// http://wiki.ros.org/msg
ros::Publisher ros_tutorial_pub =
nh.advertise<drone_control::msgTutorial>("drone_joint_data", 100);
// ループの周期を設定する。 "10"は10Hzを表し、0.1秒間隔で繰り返される
// http://wiki.ros.org/roscpp/Overview/Time
ros::Rate loop_rate(10);
// メッセージに使用する変数の宣言
int count = 0;
// ros::ok()はROSの動作が正常であるならtrueを返す関数である。
while (ros::ok())
{
// msgTutorialメッセージファイル形式でmsg変数を宣言する。
irvs_ros_tutorials::msgTutorial msg;
// 変数countを使用して、メッセージの値を定める。
msg.data = count;
// ROS_INFOというROS関数を使用して、count変数を表示する。
ROS_INFO("send msg = %d", count);
// メッセージを発行する。約0.1秒間隔で発行される。
ros_tutorial_pub.publish(msg);
// 上で定められたループサイクルになるように、スリープに入る
loop_rate.sleep();
// count変数に1ずつ増加
++count;
}
return 0;
}
