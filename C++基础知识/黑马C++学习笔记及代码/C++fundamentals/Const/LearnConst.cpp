/*------------------------------------------------------------------------------
 * @file    LEARNCONST.CPP
 * @author  ZhouRongTao
 * @date    2023/12/05 12:52:32
------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

class Entity
{
public:
    int m_X, m_Y;
    mutable int var; // ���Ըı�����Ա����

private:
    int Get() const // ���Ա������const�÷��������ڳ�Ա�����в����޸���ĳ�Ա����
    {
        m_X = 2; // ���󣬲����޸���ĳ�Ա����
        var = 3;
        return m_X;
    }
};

void PrintEntity(const Entity &e)
{
    cout << e.m_X << endl;
}

int main()
{
    const int MAX_AGE = 90;
    const int *a = new int(5); // a��ָ����ڴ����洢�����ݲ��ܸı䣬�����Ըı�a��ָ��
    //*a = 2;                    // ���󣬲��ܸı�aָ����ڴ�������
    a = (int *)&MAX_AGE;       // ��ȷ�����Ըı�a��ָ��

    int *const b = new int(5); // a��ָ���ܸı䣬�����Ըı�aָ����ڴ������
    //b = &MAX_AGE;              // ���󣬲��ܸı�a��ָ��
    *b = 30;                   // ��ȷ�����Ըı�bָ����ڴ������

    Entity e;
    PrintEntity(e);
}
