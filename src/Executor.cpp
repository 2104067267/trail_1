#include"Executor.h"
namespace adas {
//类的声明在adas空间作用域内，因此在实现类的成员时，要使用空间作用域解析符
//在函数声明时，已经明确了默认参数，因此在实现时，无需加上默认值

bool operator ==(const Pose& poseA,const Pose& poseB) {
    return (poseA.x == poseB.x) && (poseA.y == poseB.y) && (poseA.heading == poseB.heading);
}

//构造
Executor* Executor::NewExecutor(const Pose &myPose) {
    auto* p=new Executor();
    p->pose=myPose;
    InitIndex(p ,myPose);
    return p;
}

Executor:: Executor(){
    pose={0,0,'N'};
    index=0;
}

//转向
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

Pose Executor:: Query(){
     return this->pose;
}

void Executor:: MoveForward(){
    switch (this->pose.heading) {
    case 'N': this->pose.y++; break;
    case 'E': this->pose.x++; break;
    case 'S': this->pose.y--; break;
    case 'W': this->pose.x--; break;
    default : break;
    }
}

void Executor::TurnLeft() {
    index = (index - 1 + 4) % 4;
    pose.heading = directions[index];
}

void Executor::TurnRight() {
    index = (index + 1) % 4;
    pose.heading = directions[index];
}


void Executor:: InitIndex( Executor* &p ,const Pose &myPose){
    for(int i=0;i<4;i++){
        if(p->directions[i]!=myPose.heading)continue;
        p->index=i;
        break;
    }
}

}