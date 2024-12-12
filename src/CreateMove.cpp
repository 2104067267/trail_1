#include"CreateMove.h"

namespace adas{

// 普通汽车的前进函数
void CreateMove:: regularCarMove(Pose &myPose) {
    int mySpeed = myPose.speed;
    while(mySpeed){
        MoveForward(myPose);
        mySpeed--;
    }
}

// 跑车的前进函数
void CreateMove:: sportsCarMove(Pose &myPose) {
    int cnt = myPose.speed;
    while(cnt) {
        MoveForward(myPose);
        cnt--;
    }
}

// 公交车的前进函数
void CreateMove:: busMove(Pose &myPose) {
    int mySpeed = myPose.speed;
    while(mySpeed){
        MoveForward(myPose);
        mySpeed--;
    }
}


// 工厂函数：根据车辆类型创建不同的前进函数
std:: function<void(Pose &)> CreateMove:: createMoveFunction(const int& vehicleType) {
    switch (vehicleType) {
    case 0:  // 普通汽车
        return [](Pose & myPose) { CreateMove::regularCarMove(myPose); };
    case 1:  // 跑车
        return [](Pose & myPose) { CreateMove::sportsCarMove(myPose); };
    case 2:  // 公交车
        return [](Pose & myPose) { CreateMove::busMove(myPose); };
    default:
        // 返回一个空操作的lambda
        return [](Pose & myPose) {};
    }
}


}