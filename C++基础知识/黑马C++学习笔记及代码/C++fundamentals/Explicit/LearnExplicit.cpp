/*------------------------------------------------------------------------------
 * @file    LEARNEXPLICIT.CPP
 * @author  ZhouRongTao
 * @date    2023/12/12 15:54:55
------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

class Entity
{
private:
    int m_Age;
    string m_Name;

public:
    Entity(const string &name)
        : m_Name(name), m_Age(-1) {}
    explicit Entity(int age) // ֻ��ʹ��Entity a(22)�������ʵ��
        : m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity &entity){

};

int main()
{
    Entity a = 22; // ������ʽ�Ľ�int��ת��ΪEntity�ͣ�����Ĭ��ֻ��ת��һ��
    Entity b = string("zhou");
    Entity c(string("zhou"));
    PrintEntity(22);
}