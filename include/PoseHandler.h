#pragma once
#include "Point.h"
#include "Pose.h"
namespace adas{

class PoseHandler : public Point{
public:
    explicit PoseHandler(const Pose& pose={0,0,'N',0,1}) noexcept;

    PoseHandler(const PoseHandler&) = delete;
    virtual ~PoseHandler() = default;

    PoseHandler& operator=(const PoseHandler&) = delete;
     //执行指令
    virtual void Execute(const std::string& commands);
    //查询
    virtual Pose Query();
    //转弯
    virtual void Turn(int dir);
    //前进
    virtual void MoveForward(bool isTurn = false);
    //加速
    virtual void SpeedUp();
    //减速
    virtual void MoveBackward();

    Pose pose{} ;
    int  index  ;                  //下标指针
    int  speed  ;                  //速度大小
};









}
