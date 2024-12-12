#pragma once
#include"PoseHandler.h"
#include<memory>
namespace adas{

class Executorlmpl final{
public:
    //默认构造函数
    Executorlmpl() = default;
    //带参构造函数
    explicit Executorlmpl(const Pose& pose) noexcept;
    //重定义执行指令
    void Execute(const std::string& commands) ;
    //带参数构造
    static Executorlmpl* NewExecutorlmpl(const Pose &myPose);
    //查询
    Pose Query() ;

private:
    PoseHandler poseHandler;
};

}
