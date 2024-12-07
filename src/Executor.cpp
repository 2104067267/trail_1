#include"Executor.h"
namespace adas {

//带参构造
Executor* Executor::NewExecutor(const Pose &myPose) {
    auto* p  = new Executor();
    p->pose  = myPose;
    p->speed = 1;
    p->index = dir2index[myPose.heading];
    return p;
}
//默认构造
Executor:: Executor():pose({0,0,'N'}), index(0), speed(1){}
//执行指令
void Executor:: Execute(const std::string& commands) {
    for(char command : commands) {
        switch (command) {
        case 'B' : MoveBackward();     break;
        case 'F' : SpeedUp();          break;
        case 'M' : MoveForward(false);      break;
        case 'L' : Turn(-1);       break;   //-1代表向左转
        case 'R' : Turn(1);        break;   //1代表向右转
        default  : std::cout << "command is illegal\n" << std::endl; break;
        }
    }
}
//查询
Pose Executor:: Query() {
     return pose;
}
//加速
void Executor:: SpeedUp() {
    speed = (speed > 1) ? 1 : 2;
}
//前进
void Executor:: MoveForward(bool isTurn) { //默认值为false
    int mySpeed = isTurn ?  1 : speed;
    while(mySpeed > 0) {
        pose.x += steps[index][0];
        pose.y += steps[index][1];
        mySpeed -= 1;
    }
}
//后退
void Executor:: MoveBackward(){
    int mySpeed = speed;
    int myIndex = (index + 2 ) % 4;
    while(mySpeed > 0) {
        pose.x += steps[myIndex][0];
        pose.y += steps[myIndex][1];
        mySpeed -= 1;
    }
}
//转弯
void Executor:: Turn(int dir){
    if (speed > 1) MoveForward(true);
    index = (index + dir + 4) % 4;
    pose.heading = directions[index];
}

}


//初始列表下标
//void Executor:: InitIndex( Executor* &p ,const Pose &myPose) {
//    for (int i : {0 , 1, 2, 3}) {
//        if(directions[i] != myPose.heading) continue;
//        p->index = i;
//        break;
//    }
//}
////左转
//void Executor::TurnLeft() {
//    if (speed > 1) InertialMove();
//    index = (index - 1 + 4) % 4;
//    pose.heading = directions[index];
//}
////右转
//void Executor::TurnRight() {
//    if (speed > 1) InertialMove();
//    index = (index + 1) % 4;
//    pose.heading = directions[index];
//}