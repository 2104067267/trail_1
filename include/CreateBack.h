#include<iostream>
#include <functional>
#include"StaticPoseHandler.h"
namespace adas{

class CreateBack: public StaticPoseHandler{
public:
    // 工厂函数：根据车辆类型创建不同的前进函数
    static std::function<void(Pose &)> createBackFunction(const int& vehicleType) ;

    virtual ~CreateBack() = default;
    // 普通汽车的前进函数
    static void regularCarBack(Pose &myPose) ;
    // 跑车的前进函数
    static void sportsCarBack(Pose &myPose) ;
    // 公交车的前进函数
    static void busBack(Pose &myPose) ;

};
}
