#include"Command.h"
namespace adas{
//前进指令
void MoveCommand:: DoOperate(PoseHandler& poseHandler)const noexcept{
    poseHandler.MoveForward();
}
//后退指令
void BackCommand::  DoOperate(PoseHandler& poseHandler) const noexcept {
    poseHandler.MoveBackward();
}
//左转指令
void TurnLeftCommand:: DoOperate(PoseHandler& poseHandler) const noexcept {
    poseHandler.Turn(-1);
}
//右转指令
void TurnRightCommand:: DoOperate(PoseHandler& poseHandler) const noexcept {
    poseHandler.Turn(1);
}
//加速指令
void FastCommand::  DoOperate(PoseHandler& poseHandler) const noexcept {
    poseHandler.SpeedUp();
}

}
