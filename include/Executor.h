#pragma once         //当编译器读取该文件时，会记录该文件已经被包含；从而下次再读取时，不会重新读取；防止头文件被多次包含，简化代码，避免重复定义和编译错误
#include"Pose.h"
#include"Point.h"
#include<string>

namespace adas       //namespace//：组织代码并防止命名冲突，使代码更易于管理和阅读
{
//指令类
class Executor :Point
{
public:
    //带参构造
    static Executor* NewExecutor(const Pose& myPose = {0, 0,'N'});
    //默认构造函数
    Executor();
    //虚构函数
    virtual ~Executor(void) = default;
    //执行指令
    virtual void Execute(const std::string& commands);
    //查询
    virtual Pose Query();
    //转弯
    virtual void Turn(int dir);
    //前进
    virtual void MoveForward(bool isTurn);
    //加速
    virtual void SpeedUp();
    //减速
    virtual void MoveBackward();

    Pose pose{};
    int  index ;                  //下标指针
    int  speed ;                  //速度大小

};

}
