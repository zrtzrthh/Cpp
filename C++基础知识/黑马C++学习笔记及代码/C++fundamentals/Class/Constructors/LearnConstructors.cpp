/*------------------------------------------------------------------------------
 * @file    CONSTRUCTORS.CPP
 * @author  ZhouRongTao
 * @date    2023/11/23 13:47:17
------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

class Log //���Դ������ʵ������Ĭ�ϵĹ��캯��
{
public:
    static void print()
    {
    }
};

// class Log //���ɴ������ʵ�������캯������Ϊ˽����
// {
// private:
//     Log();
// public:
//     static void print()
//     {
//     }
// };

// class Log //���ɴ������ʵ����delete�˹��캯��
// {
// public:
//      Log() = delete;
//     static void print()
//     {
//     }
// };
int main()
{
    Log::print();
    Log l;
}