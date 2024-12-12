#include"CreateFast.h"

namespace adas{

// 普通汽车的加速函数
void CreateFast:: regularCarFast(Pose &myPose) {
    myPose.speed = myPose.speed > 1 ? 1 : 2;
}

// 跑车的加速函数
void CreateFast:: sportsCarFast(Pose &myPose) {
    myPose.speed = myPose.speed > 2 ? 2 : 3;
}

// 公交车的加速函数
void CreateFast:: busFast(Pose &myPose) {
    myPose.speed = myPose.speed > 1 ? 1 : 2;
}

// 工厂函数：根据车辆类型创建不同的加速函数
std:: function<void(Pose &)> CreateFast:: createFastFunction(const int& vehicleType) {
    switch (vehicleType) {
    case 0:  // 普通汽车
        return [](Pose & myPose) { CreateFast::regularCarFast(myPose); };
    case 1:  // 跑车
        return [](Pose & myPose) { CreateFast::sportsCarFast(myPose); };
    case 2:  // 公交车
        return [](Pose & myPose) { CreateFast::busFast(myPose); };
    default:
        // 返回一个空操作的lambda
        return [](Pose & myPose) {};
    }
}


}