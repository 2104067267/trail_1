#include<iostream>
#include <functional>
#include"StaticPoseHandler.h"
namespace adas{

class CreateMove: public StaticPoseHandler{
public:
    // 工厂函数：根据车辆类型创建不同的前进函数
    static std::function<void(Pose &)> createMoveFunction(const int& vehicleType) ;

    virtual ~CreateMove() = default;
    // 普通汽车的前进函数
    static void regularCarMove(Pose &myPose) ;
    // 跑车的前进函数
    static void sportsCarMove(Pose &myPose) ;
    // 公交车的前进函数
    static void busMove(Pose &myPose) ;

};


}