#include"StaticPoseHandler.h"
namespace adas{


//转弯
void StaticPoseHandler:: Turn(Pose &myPose ,int dir){
    myPose.index= ( myPose.index + dir + 4) % 4;
    myPose.heading = directions[myPose.index];
}
//前进
void StaticPoseHandler:: MoveForward(Pose &myPose){
    myPose.x += steps[myPose.index][0];
    myPose.y += steps[myPose.index][1];
}
//后退
void StaticPoseHandler:: BackForward(Pose &myPose){
    myPose.x -= steps[myPose.index][0];
    myPose.y -= steps[myPose.index][1];
}

}
