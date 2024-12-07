#pragma once
#include "Executor.h"
namespace adas{

class PoseHandler final: Point{
public:
    explicit PoseHandler(const Pose& pose={0,0,'N'}) noexcept;

    PoseHandler(const PoseHandler&) = delete;

    PoseHandler& operator=(const PoseHandler&) = delete;
    //执行指令
    void Execute(const std::string& commands);
    //查询
    Pose Query();
    //转弯
    void Turn(int dir);
    //前进
    void MoveForward(bool isTurn = false);
    //加速
    void SpeedUp();
    //减速
    void MoveBackward();
private:
    Pose pose{} ;
    int  index  ;                  //下标指针
    int  speed  ;                  //速度大小
};









}
