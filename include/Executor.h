#pragma once         //当编译器读取该文件时，会记录该文件已经被包含；从而下次再读取时，不会重新读取；防止头文件被多次包含，简化代码，避免重复定义和编译错误
#include "Pose.h"
#include"Point.h"
#include"CreateMove.h"
#include"CreateTurn.h"
#include"CreateBack.h"
#include"CreateFast.h"
namespace adas       //namespace//：组织代码并防止命名冲突，使代码更易于管理和阅读
{
//指令类
class Executor : public CreateMove,public CreateTurn, public CreateFast, public CreateBack {
public:
    //带参构造
    static Executor* NewExecutor(const Pose& myPose = {0,0,'N',0,0,1,0});
    //默认构造函数
    Executor();
    //
    //void Execute()
   void Execute(const std::string& commands);
   //查询
   Pose Query();
   //前进
   std::function<void(Pose&)> MoveForward;
   //转弯
   std::function<void(Pose&,int)> Turn;
   //后退
   std::function<void(Pose&)> BackForward;
   //加速
   std::function<void(Pose&)> Fast;

   Pose pose{};

};

}
