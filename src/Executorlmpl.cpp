#include"Executorlmpl.h"

namespace adas{
//执行指令
void Executorlmpl::Execute(const std::string &commands)
{
    for(const auto cmd: commands){
        std::unique_ptr<ICommand> cmder;
        switch (cmd) {
        case 'F': cmder = std::make_unique<FastCommand>();      break;
        case 'M': cmder = std::make_unique<MoveCommand>();      break;
        case 'L': cmder = std::make_unique<TurnLeftCommand>();  break;
        case 'R': cmder = std::make_unique<TurnRightCommand>(); break;
        default : break;
        }
        if(cmder) cmder->DoOperate(*this);
    }
}
//前进指令类
void Executorlmpl:: MoveCommand::DoOperate(Executorlmpl& executor) const noexcept {
    executor.MoveForward();
}
//右转指令类
void Executorlmpl:: TurnRightCommand::DoOperate(Executorlmpl &executor) const noexcept
{
    executor.Turn(1);
}
//左转指令类
void Executorlmpl:: TurnLeftCommand::DoOperate(Executorlmpl &executor) const noexcept
{
    executor.Turn(-1);
}
//加速指令类
void Executorlmpl:: FastCommand::DoOperate(Executorlmpl &executor) const noexcept
{
    executor.SpeedUp();
}
//带参构造
Executorlmpl* Executorlmpl:: NewExecutorlmpl(const Pose &myPose){
    auto* p  = new Executorlmpl();
    p->index = dir2index[myPose.heading];
    p->pose  = myPose;
    p->speed = 1;
    return p;
}
//查询
Pose Executorlmpl:: Query(){
    return pose;
}
//转弯
void Executorlmpl:: Turn(int dir){
    if (speed > 1) MoveForward(true);
    index = (index + dir + 4) % 4;
    pose.heading = directions[index];
}
//前进
void Executorlmpl:: MoveForward(bool isTurn){
    int mySpeed = isTurn ?  1 : speed;
    while(mySpeed > 0) {
        pose.x += steps[index][0];
        pose.y += steps[index][1];
        mySpeed -= 1;
    }
}
//加速
void Executorlmpl:: SpeedUp(){
    speed = (speed > 1) ? 1 : 2;
}

}
