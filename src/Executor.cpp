#include"Executor.h"
namespace adas {


//Pose的判别等于运算符重载
bool operator ==(const Pose& poseA,const Pose& poseB) {
    return (poseA.x == poseB.x) && (poseA.y == poseB.y) && (poseA.heading == poseB.heading);
}
//方向列表初始化
char Executor:: directions[4]={'N','E','S','W'};
//带参构造
Executor* Executor::NewExecutor(const Pose &myPose) {
    auto* p=new Executor();
    p->pose=myPose;
    InitIndex(p ,myPose);
    return p;
}
//默认构造
Executor:: Executor(){
    pose={0,0,'N'};
    index=0;

}
//执行指令
void Executor::Execute(const std::string& commands){
    for(int i=0;commands[i]!='\0';i++){
        if (commands[i] == 'M') {
              MoveForward();
        }
        else if (commands[i] =='L'){
              TurnLeft();
        }
        else if (commands[i] == 'R'){
              TurnRight();
        }
        else {
            std::cout << "command is illegal" << std::endl;
        }
    }
}
//查询
Pose Executor:: Query(){
     return this->pose;
}
//前进
void Executor:: MoveForward(){
    switch (this->pose.heading) {
    case 'N': this->pose.y++; break;
    case 'E': this->pose.x++; break;
    case 'S': this->pose.y--; break;
    case 'W': this->pose.x--; break;
    default : break;
    }
}
//左转
void Executor::TurnLeft() {
    index = (index - 1 + 4) % 4;
    pose.heading = directions[index];
}
//右转
void Executor::TurnRight() {
    index = (index + 1) % 4;
    pose.heading = directions[index];
}
//初始列表下标
void Executor:: InitIndex( Executor* &p ,const Pose &myPose){
    for(int i=0;i<4;i++){
        if(p->directions[i]!=myPose.heading)continue;
        p->index=i;
        break;
    }
}

}