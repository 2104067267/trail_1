#include"PoseHandler.h"
namespace adas{


PoseHandler:: PoseHandler(const Pose& myPose) noexcept:
      pose (myPose){
    pose.index = dir2index[pose.heading];
    MoveForward = createMoveFunction(myPose.car);
    Fast = createFastFunction(myPose.car);
    BackForward = createBackFunction(myPose.car);
    Turn = createTurnFunction(myPose.car);
}

Pose PoseHandler:: Query() {
    return pose;
}




////执行指令
//void PoseHandler:: Execute(const std::string& commands) {
//    for(char command : commands) {
//        switch (command) {
//        case 'B' : BackForward(pose);     break;
//        case 'F' : Fast(pose);          break;
//        case 'M' : MoveForward(pose);      break;
//        case 'L' : Turn(pose,-1);       break;   //-1代表向左转
//        case 'R' : Turn(pose,1);        break;   //1代表向右转
//        default  : std::cout << "command is illegal\n" << std::endl; break;
//        }
//    }
//}
//查询
////前进
//void PoseHandler:: MoveForward(bool isTurn) { //默认值为false
//    int mySpeed = isTurn ?  1 : speed;
//    while(mySpeed > 0) {
//        pose.x += steps[index][0];
//        pose.y += steps[index][1];
//        mySpeed -= 1;
//    }
//}
////后退
//void PoseHandler:: MoveBackward(){
//    int mySpeed = speed;
//    int myIndex = (index + 2) % 4;
//    while(mySpeed > 0) {
//        pose.x += steps[myIndex][0];
//        pose.y += steps[myIndex][1];
//        mySpeed -= 1;
//    }
//}
////转弯
//void PoseHandler:: Turn(int dir){
//    if (speed > 1) MoveForward(true);
//    index = (index + dir + 4) % 4;
//    pose.heading = directions[index];
//}


}