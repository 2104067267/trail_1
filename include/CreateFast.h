#include<iostream>
#include <functional>
#include"StaticPoseHandler.h"
namespace adas{

class CreateFast: public StaticPoseHandler{
public:
    // 工厂函数：根据车辆类型创建不同的前进函数
    static std::function<void(Pose &)> createFastFunction(const int& vehicleType) ;

    virtual ~CreateFast() = default;
    // 普通汽车的前进函数
    static void regularCarFast(Pose &myPose) ;
    // 跑车的前进函数
    static void sportsCarFast(Pose &myPose) ;
    // 公交车的前进函数
    static void busFast(Pose &myPose) ;

};


}
