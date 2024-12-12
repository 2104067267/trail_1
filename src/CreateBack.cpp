#include"CreateBack.h"

namespace adas{

// 普通汽车的后退函数
void CreateBack:: regularCarBack(Pose &myPose) {
    int mySpeed = myPose.speed;
    while(mySpeed){
        BackForward(myPose);
        mySpeed--;
    }
}

// 跑车的后退函数
void CreateBack:: sportsCarBack(Pose &myPose) {
    int mySpeed = myPose.speed;
    while(mySpeed){
        BackForward(myPose);
        mySpeed--;
    }
}

// 公交车的后退函数
void CreateBack:: busBack(Pose &myPose) {
    int mySpeed = myPose.speed;
    while(mySpeed){
        BackForward(myPose);
        mySpeed--;
    }
}


// 工厂函数：根据车辆类型创建不同的后退函数
std:: function<void(Pose &)> CreateBack:: createBackFunction(const int& vehicleType) {
    switch (vehicleType) {
    case 0:  // 普通汽车
        return [](Pose & myPose) { CreateBack::regularCarBack(myPose); };
    case 1:  // 跑车
        return [](Pose & myPose) { CreateBack::sportsCarBack(myPose); };
    case 2:  // 公交车
        return [](Pose & myPose) { CreateBack::busBack(myPose); };
    default:
        // 返回一个空操作的lambda
        return [](Pose & myPose) {};
    }
}


}