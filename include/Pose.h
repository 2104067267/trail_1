#pragma once
#include<iostream>
namespace adas{
//基数
struct Pose {
    int x;
    int y;
    char heading;
};
//Pose的判别等于运算符重载
bool  operator == (const Pose& poseA,const Pose& poseB) ;

}