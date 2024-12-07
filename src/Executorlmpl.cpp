#include"Executorlmpl.h"
#include"Command.h"
#include<unordered_map>
namespace adas{

//带参构造函数
Executorlmpl:: Executorlmpl(const Pose& pose) noexcept :poseHandler(pose) {}

//执行指令
void Executorlmpl::Execute(const std::string &commands)
{
    std::unordered_map<char, std::unique_ptr<ICommand>> cmderMap;
    cmderMap.emplace('M', std::make_unique<MoveCommand>());
    cmderMap.emplace('R', std::make_unique<TurnRightCommand>());
    cmderMap.emplace('L', std::make_unique<TurnLeftCommand>());
    cmderMap.emplace('F', std::make_unique<FastCommand>());
    cmderMap.emplace('B', std::make_unique<BackCommand>());

    for(const auto cmd: commands){
       const auto it = cmderMap.find(cmd);
       if(it != cmderMap.end()){
           it->second->DoOperate(this->poseHandler);
       }
    }
}
//带参构造
Executorlmpl* Executorlmpl:: NewExecutorlmpl(const Pose &myPose){
    auto* p  = new Executorlmpl(myPose);
    return p;
}
//查询
Pose Executorlmpl:: Query(){
    return poseHandler.Query();
}

}
