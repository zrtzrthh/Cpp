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
    static const int size = 5; //�������ڳ�ʼֵ�ĳ�Ա������Ϊ����
    int example[size]; //����ǰ�͵�֪��size�Ƕ���
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