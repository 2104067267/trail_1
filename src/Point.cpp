#include"Point.h"
namespace adas{

//方向列表初始化
char Point:: directions[4] = { 'N', 'E', 'S', 'W'};
//方向到下标的映射表
std:: map<char, int> Point:: dir2index = { {'N',0}, {'E',1}, {'S',2}, {'W',3}};
//位移基数
int Point:: steps[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0}};

}