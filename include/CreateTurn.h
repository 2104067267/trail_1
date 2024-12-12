#include<iostream>
#include <functional>
#include"StaticPoseHandler.h"
namespace adas{

class CreateTurn: public StaticPoseHandler{
public:
    // 工厂函数：根据车辆类型创建不同的前进函数
    static std::function<void(Pose&,int)> createTurnFunction(const int& vehicleType) ;

    virtual ~CreateTurn() = default;
    // 普通汽车的前进函数
    static void regularTurn(Pose &myPose, int dir) ;
    // 跑车的前进函数
    static void sportsCarTurn(Pose &myPose,int dir) ;
    // 公交车的前进函数
    static void busTurn(Pose &myPose,int dir) ;

};


}