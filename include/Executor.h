#pragma once         //当编译器读取该文件时，会记录该文件已经被包含；从而下次再读取时，不会重新读取；防止头文件被多次包含，简化代码，避免重复定义和编译错误
#include <string>
#include<iostream>
namespace adas       //namespace//：组织代码并防止命名冲突，使代码更易于管理和阅读
{
//基数
struct Pose {
    int x;
    int y;
    char heading;
};
//Pose的判别等于运算符重载
bool  operator ==(const Pose& poseA,const Pose& poseB) ;

//指令类
class Executor
{
public:
    //带参构造
    static Executor* NewExecutor(const Pose& myPose = {0, 0,'N'});
    //初始index成员变量
    static void InitIndex(Executor* &p ,const Pose & myPose);
    //默认构造函数
    Executor();
    //虚构函数
    virtual ~Executor(void)=default;
    //禁用拷贝构造
    Executor(const Executor&) = delete;
    //禁用赋值构造
    Executor& operator=(const Executor&) = delete;
    //执行指令
    virtual void Execute(const std::string& commands);
    //查询
    virtual Pose Query();
    //左转
    virtual void TurnLeft();
    //右转
    virtual void TurnRight();
    //前进
    virtual void MoveForward();

private:
    Pose pose{};
    int index=0;                //列表下标
    static char directions[4];  //方向参数列表
};

}


