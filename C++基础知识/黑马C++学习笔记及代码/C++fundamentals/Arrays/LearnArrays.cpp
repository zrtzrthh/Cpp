/*------------------------------------------------------------------------------
 * @file    LEARNARRAYS.CPP
 * @author  ZhouRongTao
 * @date    2023/11/28 14:27:00
------------------------------------------------------------------------------*/
#include <iostream>
#include <array>
using namespace std;
#define SIZE 5

class Entity
{
public:
    static const int size = 5; //带有类内初始值的成员必须设为常量
    int example[size]; //编译前就得知道size是多少
    int *anthor = new int[5];
    Entity()
    {
        for (int i = 0; i < 5; i++)
        {
            anthor[i] = 2;
        }
    }
};

int main()
{
    int example[SIZE]; 
}