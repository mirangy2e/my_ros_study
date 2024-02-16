#include <ros/ros.h> 
#include <tf/transform_datatypes.h> //TF에서 3D위치와 방향을 쉽게 관리할 수 있는 데이터 타입
#include <tf/transform_broadcaster.h> //TF를 게시하기 위한 헤더파일 선언

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_tf_node"); 
  ros::NodeHandle nh; 

  ros::Rate loop_rate(60); 

  tf::TransformBroadcaster broadcaster;

  while (ros::ok()) 
  {
        // 로그 출력
    ROS_INFO("TF broadcast");

    // 부모링크와 자식링크 사이의 변환 행렬을 발송,위치와 방향
    tf::Transform transform(tf::Quaternion(0.0, 0.0, 0.0, 1.0), tf::Vector3(1.0, 0.0, 0.0));
    //위치와 방향, 시간, 부모프레임ID, 자식프레임ID
    tf::StampedTransform stampedTransform(transform, ros::Time::now(), "parent_link", "child_link");
    broadcaster.sendTransform(stampedTransform);

    // ROS 이벤트 처리
    ros::spinOnce();

    // 주기 유지
    loop_rate.sleep();
  }     

  return 0; 
}