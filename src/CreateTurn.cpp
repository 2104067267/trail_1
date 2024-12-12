#include"CreateTurn.h"

namespace adas
{
// 普通汽车的转弯函数
void CreateTurn:: regularTurn(Pose &myPose,int dir){
    if (myPose.speed > 1) MoveForward(myPose);
    Turn(myPose,dir);
}

// 跑车的转弯函数
void CreateTurn:: sportsCarTurn(Pose &myPose,int dir){
    Turn(myPose,dir);
    int mySpeed = myPose.speed - 1;
    while(mySpeed){
        MoveForward(myPose);
        mySpeed -= 1;
    }
}

// 公交车的转弯函数
void CreateTurn:: busTurn(Pose &myPose,int dir){
    if(myPose.speed < 2 ) MoveForward(myPose);
    Turn(myPose,dir);
}

std::function<void(Pose&,int)> CreateTurn::createTurnFunction(const int& vehicleType)
{
    switch (vehicleType) {
    case 0:  // 普通汽车
        return [](Pose &myPose,int dir) { CreateTurn::regularTurn(myPose,dir); };
    case 1:  // 跑车
        return [](Pose &myPose,int dir) { CreateTurn::sportsCarTurn(myPose,dir); };
    case 2:  // 公交车
        return [](Pose &myPose,int dir) { CreateTurn::busTurn(myPose,dir); };
    default:
        // 返回一个空操作的lambda
        return [](Pose &myPose,int dir) {  };
    }
}


}