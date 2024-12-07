#pragma once
#include<iostream>
#include<map>
namespace adas{

class Point{
public:
    static std:: map<char, int> dir2index;  //方向转下标列表
    static int   steps[4][2];               //位移基数
    static char  directions[4];             //方向参数列表
};

}