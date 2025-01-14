/**
 * 在控制台中发送位置，自动导航 
 */
#include "string.h"
#include "volcano_robotsim/VolcanoGoal.h" 
#include "volcano_robotsim/VolcanoGuiInfo.h"
#include "geometry_msgs/PoseStamped.h"
#include "ros/ros.h"
 
using namespace std;
 
ros::NodeHandle *n;
ros::Publisher pub_goal;
void goalCallback(const volcano_robotsim::VolcanoGoal::ConstPtr &value);
void guigoalCallback(const volcano_robotsim::VolcanoGuiInfo::ConstPtr &value);
int main(int argc, char **argv) {
    // create a node named 'volcano' on ROS network
    ros::init(argc, argv, "volcano_set_goal");
    n = new ros::NodeHandle;
    ros::Subscriber sub_goal;
    ros::Subscriber sub_gui_goal;
    sub_goal = n->subscribe("/volcano/goal",1,goalCallback);
    sub_gui_goal = n->subscribe("/VolcanoGuiInfo",1,guigoalCallback);

    pub_goal = n->advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal",2);
    ROS_INFO("Started success ");
    ros::spin();
}

void go_2_book_goal(int build_type,string goal_name){
    int isture=0;
    geometry_msgs::PoseStamped target_pose;
    target_pose.header.seq = 1;
    target_pose.header.frame_id = "map";
    /** 书籍分类区
     * A 马克思主义、列宁主义、毛泽东思想、邓小平理论
     * B 哲学、宗教
     * C 社会科学总论
     * D 政治、法律
     * E 军事
     * F 经济
     * G 文化、科学、教育、体育
     * H 语言、文字
     * T 工业技术
     * TB 一般工业技术
     * TD 矿业工程
     * TE 石油、天然气工业
     * TF 冶金工业
     * TG 金属学与金属工艺
     * TH 机械、仪表工业
     * TJ 武器工业
     * TK 能源与动力工程
     * TL 电子能技术
     * TM 电工技术
     * TN 光线电电子学、电信技术
     */
    
    // build_type == 1 -> gmapping 建图
    // build_type == 0 -> cartographer 建图
    if (build_type)
    {
        if (goal_name == "A"||goal_name == "B")
        {
            target_pose.pose.position.x = -2.0;
            target_pose.pose.position.y = 6.29;
            target_pose.pose.orientation.z = 0.0016;
            target_pose.pose.orientation.w = 0.9999;
            isture = 1;
        }else if(goal_name == "C"||goal_name == "D")
        {
            target_pose.pose.position.x = -2.0;
            target_pose.pose.position.y = 3.7;
            target_pose.pose.orientation.z = 0.0016;
            target_pose.pose.orientation.w = 0.9999;
            isture = 1;
        }else if (goal_name == "E"||goal_name == "F")
        {
            target_pose.pose.position.x = -2.0;
            target_pose.pose.position.y = 1.21;
            target_pose.pose.orientation.z = 0.0016;
            target_pose.pose.orientation.w = 0.9999;
            isture = 1;
        }else if (goal_name == "G"||goal_name == "H")
        {
            target_pose.pose.position.x = -2.0;
            target_pose.pose.position.y = -1.21;
            target_pose.pose.orientation.z = 0.0016;
            target_pose.pose.orientation.w = 0.9999;
            isture = 1;
        }else if (goal_name == "T"||goal_name == "TB"||goal_name == "TD")
        {
            target_pose.pose.position.x = -7.0;
            target_pose.pose.position.y = 5.95;
            target_pose.pose.orientation.z = 0.9999;
            target_pose.pose.orientation.w = 0.0028;
            isture = 1;
        }else if (goal_name == "TE"||goal_name == "TF"||goal_name == "TG")
        {
            target_pose.pose.position.x = -7.0;
            target_pose.pose.position.y = 3.6;
            target_pose.pose.orientation.z = 0.9999;
            target_pose.pose.orientation.w = 0.0028;
            isture = 1;
        }else if (goal_name == "TH"||goal_name == "TJ"||goal_name == "TK")
        {
            target_pose.pose.position.x = -7.0;
            target_pose.pose.position.y = 1.11;
            target_pose.pose.orientation.z = 0.9999;
            target_pose.pose.orientation.w = 0.0028;
            isture = 1;
        }else if (goal_name == "TL"||goal_name == "TM"||goal_name == "TN")
        {
            target_pose.pose.position.x = -7.0;
            target_pose.pose.position.y = -1.19;
            target_pose.pose.orientation.z = 0.9999;
            target_pose.pose.orientation.w = 0.0028;
            isture = 1;
        }
    }
    else
    {
        if (goal_name == "A"||goal_name == "B")
        {
            target_pose.pose.position.x = 10.0444;
            target_pose.pose.position.y = -7.0554;
            target_pose.pose.orientation.z = -0.7071;
            target_pose.pose.orientation.w = 0.7071;
            isture = 1;
        }else if(goal_name == "C"||goal_name == "D")
        {
            target_pose.pose.position.x = 7.5803;
            target_pose.pose.position.y = -7.0233;
            target_pose.pose.orientation.z = -0.7071;
            target_pose.pose.orientation.w = 0.7071;
            isture = 1;
        }else if (goal_name == "E"||goal_name == "F")
        {
            target_pose.pose.position.x = 5.379;
            target_pose.pose.position.y = -7.0233;
            target_pose.pose.orientation.z = -0.7071;
            target_pose.pose.orientation.w = 0.7071;
            isture = 1;
        }else if (goal_name == "G"||goal_name == "H")
        {
            target_pose.pose.position.x = 2.8888;
            target_pose.pose.position.y = -7.0233;
            target_pose.pose.orientation.z = -0.7071;
            target_pose.pose.orientation.w = 0.7071;
            isture = 1;
        }else if (goal_name == "T"||goal_name == "TB"||goal_name == "TD")
        {
            target_pose.pose.position.x = 10.0743;
            target_pose.pose.position.y = -0.2492;
            target_pose.pose.orientation.z = 0.7071;
            target_pose.pose.orientation.w = 0.7071;
            isture = 1;
        }else if (goal_name == "TE"||goal_name == "TF"||goal_name == "TG")
        {
            target_pose.pose.position.x = 7.414499282836914;
            target_pose.pose.position.y = -0.2492;
            target_pose.pose.orientation.z = 0.7071;
            target_pose.pose.orientation.w = 0.7071;
            isture = 1;
        }else if (goal_name == "TH"||goal_name == "TJ"||goal_name == "TK")
        {
            target_pose.pose.position.x = 4.8435;
            target_pose.pose.position.y = -0.2492;
            target_pose.pose.orientation.z = 0.7071;
            target_pose.pose.orientation.w = 0.7071;
            isture = 1;
        }else if (goal_name == "TL"||goal_name == "TM"||goal_name == "TN")
        {
            target_pose.pose.position.x = 2.8118;
            target_pose.pose.position.y = -0.2492;
            target_pose.pose.orientation.z = 0.7071;
            target_pose.pose.orientation.w = 0.7071;
            isture = 1;
        }
    }

    if (isture)
    {
        target_pose.header.stamp = ros::Time::now();
        pub_goal.publish(target_pose);
        ROS_INFO("Ready to go to the goal %s",goal_name.c_str());
    }
    else
    {
        ROS_ERROR("Can't compare the goal");
    }
}

void go_2_seat_goal(int seat_number){
    int isture=0;
    geometry_msgs::PoseStamped target_pose;
    target_pose.header.seq = 1;
    target_pose.header.frame_id = "map";
    if (seat_number <= 4 && seat_number >= 1){
        target_pose.pose.position.x = 1.8401894569396973;
        target_pose.pose.position.y = 12.73941421508789;
        target_pose.pose.orientation.z = 0.0014486014433241633;
        target_pose.pose.orientation.w = 0.9999989507763788;
        isture = 1;
    }
    else if (seat_number <= 8 && seat_number >= 5){
        target_pose.pose.position.x = 1.7912073135375977;
        target_pose.pose.position.y = 9.865933418273926;
        target_pose.pose.orientation.z = 0.009064143268526342;
        target_pose.pose.orientation.w = 0.9999589198096128;
        isture = 1;
    }
    else if (seat_number <= 12 && seat_number >= 9){
        target_pose.pose.position.x = -1.552984356880188;
        target_pose.pose.position.y = 12.73941421508789;
        target_pose.pose.orientation.z = 0.0014486014433241633;
        target_pose.pose.orientation.w = 0.9999989507763788;
        isture = 1;
    }
    if (isture)
    {
        target_pose.header.stamp = ros::Time::now();
        pub_goal.publish(target_pose);
        ROS_INFO("Ready to go to the seat %d",seat_number);
    }
    else
    {
        ROS_ERROR("Can't compare the goal");
    }
}

/*
    语音数据
*/
void goalCallback(const volcano_robotsim::VolcanoGoal::ConstPtr &value){
    string goal_name = value->goal_name;
    int build_type = value->build_type;
    go_2_book_goal(build_type,goal_name);
}

/*
    上位机数据
*/
void guigoalCallback(const volcano_robotsim::VolcanoGuiInfo::ConstPtr &value){
    string book_number = value->book_number.substr(0,2);
    int seat_number_on = value->seat_number_on;
    int seat_number_off = value->seat_number_off;
    int is_follow = value->is_follow;
    if (is_follow)
    {
        go_2_book_goal(1,book_number);
        is_follow = 0;
    }
    if (seat_number_on > 0)
    {
        go_2_seat_goal(seat_number_on);
    }
    
    

}