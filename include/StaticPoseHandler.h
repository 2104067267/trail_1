#pragma once
#include "Point.h"
#include "Pose.h"
namespace adas{

class StaticPoseHandler : public Point{
public:

    virtual ~StaticPoseHandler() = default;
    //转弯
    static void Turn(Pose &myPose,int dir);
    //前进
    static void MoveForward(Pose &myPose);
    //后退
    static void BackForward(Pose &myPose);

};









}
