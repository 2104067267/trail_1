#pragma once    //当编译器读取该文件时，会记录该文件已经被包含；从而下次再读取时，不会重新读取；防止头文件被多次包含，简化代码，避免重复定义和编译错误
#include <string>
#include<iostream>
//命名空间语法：防止防止不同模块或库之间的名称冲突，使代码易于管理
namespace adas    //namespace//：组织代码并防止命名冲突，使代码更易于管理和阅读
{
struct Pose {        //在计算和计算机视觉领域，pose (或 spatial pose) 表示物体的位置和方向
    int x;           // 定义结构体，便于数据的组织和传递
    int y;
    char heading;
};

bool  operator ==(const Pose& poseA,const Pose& poseB) ;


class Executor    //抽象类，提供接口定义，隐藏功能实现细节
{
public:
    //static: 表明为静态成员函数； Executor* :表明返回类型是一个类指针 NewExecutor是函数名； {}表示是一个参数列表；
    static Executor* NewExecutor(const Pose& myPose = {0, 0,'N'});
    //
    static void InitIndex(Executor* &p ,const Pose & myPose);
    //默认构造函数
    Executor(void) = default;  // =default简化代码，明确表示使用编译器生成的默认实现
    //虚构函数
    virtual ~Executor(void)=default;
    //禁止拷贝函数，任何通过拷贝一个对象来初始化一个新对象的操作都会出错
    //拷贝构造函数： ClassName (const ClassName& other){}
    Executor(const Executor&) = delete;
    //ClassName& ：表示对当前对象的引用 ；  禁止拷贝赋值运算；
    //拷贝赋值运算；  ClassName& operator = (const ClassName & other) {}
    Executor& operator=(const Executor&) = delete;
    //virtual: 关键字表示该函数是一个虚函数，允许在派生类中进行重写
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
    Pose pose;
    int index=0;
    char directions[4]={'N','E','S','W'};
};

}


