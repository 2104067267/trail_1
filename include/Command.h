#pragma once
#include "PoseHandler.h"
namespace adas{
//指令虚基类
class ICommand{
public:
    virtual ~ICommand() = default;
    virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
};

//前进指令类
class MoveCommand final: public ICommand{
public:
    void DoOperate(PoseHandler& poseHandler)const noexcept override;
};
//加速指令类
class BackCommand final: public ICommand{
public:
    void DoOperate(PoseHandler& poseHandler)const noexcept override;
};

//右转指令类
class TurnRightCommand final:public ICommand{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

//左转指令类
class TurnLeftCommand final:public ICommand{
public:
    void DoOperate(PoseHandler& poseHandler)  const noexcept override;
};

//加速指令类
class FastCommand final: public ICommand{
public:
    void DoOperate(PoseHandler& poseHandler)const noexcept override;
};

}
