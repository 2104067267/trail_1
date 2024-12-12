#include"Executor.h"
namespace adas {

//带参构造
Executor* Executor::NewExecutor(const Pose &myPose) {
    auto* p  = new Executor();
    p->pose = myPose;
    p->pose.index = dir2index[myPose.heading];
    p->MoveForward = createMoveFunction(myPose.car);
    p->Turn = createTurnFunction(myPose.car);
    p->BackForward = createBackFunction(myPose.car);
    p->Fast = createFastFunction(myPose.car);
    return p;
}
//默认构造
Executor:: Executor():
      MoveForward(createMoveFunction(0)),
      Turn(createTurnFunction(0)),
      BackForward(createBackFunction(0)),
      Fast(createMoveFunction(0)),
      pose({0,0,'N',0,1,1,0})
      {
}

//执行指令
void Executor:: Execute(const std::string& commands) {
    for(char command : commands) {
        switch (command) {
        case 'B' : BackForward(this->pose);      break;
        case 'F' : Fast(this->pose);             break;
        case 'M' : MoveForward(this->pose);      break;
        case 'L' : Turn(this->pose,-1);          break;   //-1代表向左转
        case 'R' : Turn(this->pose,1);           break;   //1代表向右转
        default  : std::cout << "command is illegal\n" << std::endl; break;
        }
    }
}

//查询
Pose Executor:: Query() {
     return pose;
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

//加速
//void Executor:: SpeedUp() {
//    pose.speed = (pose.speed > 1) ? 1 : 2;
//}
//
////后退
//void Executor:: MoveBackward(){
//    int mySpeed = pose.speed;
//    int myIndex = (pose.index + 2 ) % 4;
//    while(mySpeed > 0) {
//        pose.x += steps[myIndex][0];
//        pose.y += steps[myIndex][1];
//        mySpeed -= 1;
//    }
//}