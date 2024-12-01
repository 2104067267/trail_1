#pragma once
#include"Executor.h"
#include<memory>
namespace adas{

class Executorlmpl final:public Executor{
public:

    //默认构造函数
    Executorlmpl() = default;
    //重定义执行指令
    void Execute(const std::string& commands) override;
    //带参数构造
    static Executorlmpl* NewExecutorlmpl(const Pose &myPose);
    //查询
    Pose Query() override;
    //转弯
    void Turn(int dir) override;
    //前进
    void MoveForward(bool isTurn = false) override;
    //加速
    void SpeedUp() override;

private:
    //指令虚基类
    class ICommand{
    public:
        virtual ~ICommand() = default;
        virtual void DoOperate(Executorlmpl& excutor) const noexcept = 0;
    };
    //前进指令类
    class MoveCommand final: public ICommand{
    public:
        void DoOperate(Executorlmpl& executor)const noexcept override;
    };
    //右转指令类
    class TurnRightCommand final:public ICommand{
    public:
        void DoOperate(Executorlmpl& executor) const noexcept override;
    };
    //左转指令类
    class TurnLeftCommand final:public ICommand{
    public:
        void DoOperate(Executorlmpl& executor)  const noexcept override;
    };
    //加速指令类
    class FastCommand final: public ICommand{
    public:
        void DoOperate(Executorlmpl& executor)const noexcept override;
    };

};





}
