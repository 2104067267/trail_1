#pragma once
#include "Point.h"
#include "Pose.h"
#include <functional>
#include"CreateMove.h"
#include"CreateTurn.h"
#include"CreateBack.h"
#include"CreateFast.h"
namespace adas{

class PoseHandler :  public CreateMove, public CreateBack,public CreateFast,public CreateTurn{
public:
    explicit PoseHandler(const Pose& pose={0,0,'N',0,1,1,0}) noexcept;

    PoseHandler(const PoseHandler&) = delete;
    virtual ~PoseHandler() = default;

    PoseHandler& operator=(const PoseHandler&) = delete;

    //查询
    Pose Query();
    //前进
    std::function<void(Pose &)>  MoveForward;
    //转弯
    std::function<void(Pose &,int)> Turn;
    //后退
    std::function<void(Pose &)> BackForward;
    //加速
    std::function<void(Pose &)> Fast;

    Pose pose{} ;
};


//执行指令
//virtual void Execute(const std::string& commands);






}
