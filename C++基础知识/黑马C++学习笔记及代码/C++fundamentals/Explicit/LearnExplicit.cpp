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
    explicit Entity(int age) // 只能使用Entity a(22)创建类的实例
        : m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity &entity){

};

int main()
{
    Entity a = 22; // 这里隐式的将int型转换为Entity型，并且默认只能转换一次
    Entity b = string("zhou");
    Entity c(string("zhou"));
    PrintEntity(22);
}