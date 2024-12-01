#include"Pose.h"
namespace adas{

//Pose的判别等于运算符重载
bool operator == (const Pose& poseA,const Pose& poseB) {
    return (poseA.x == poseB.x) && (poseA.y == poseB.y) && (poseA.heading == poseB.heading);
}

}