/*------------------------------------------------------------------------------
 * @file    LEARNVIRTUAL.CPP
 * @author  ZhouRongTao
 * @date    2023/11/26 11:18:49
------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

class Printable
{
public:
    virtual string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    virtual string GetName() { return "Entity"; }
    string GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
private:
    string m_Name;

public:
    Player() {}
    Player(const string &name) : m_Name(name) {}
    string GetName() override { return m_Name; }
    string GetClassName() override { return "player"; } // ������������д�麯����Ĭ�Ϸ��ʸ�����麯��
};

void PrintName(Entity *entity)
{
    cout << entity->GetName() << endl;
}

void PrintClassName(Printable *obj)
{
    cout << obj->GetClassName() << endl;
}

int main()
{
    Player e("rong"); //�麯�������ɻ���ָ����з��ʣ��������ӵ�����������麯��ʱ��̬���ã������õ��麯��������
    cout << e.GetName() << endl;
    
    // Player p("zhou");
    // Entity *e = &p; // ����ָ��Player����Ļ���ָ�룬��������չ�ֳ��麯�����ص㣬����eָ����Ȼֻ�ܷ���Entity��ķ���
    // cout << e->GetName() << endl;

    Entity *e0 = new Entity();
    PrintClassName(e0);

    /*
    ������ָ��Player�����Entity��ָ��e1��ֻ�ܷ���Entity������Ժͷ���
    �����������Player����д��Entity��ĳ�Ա�������Ϳ���ʵ�ֶ�̬������д���ĳ�Ա����
    */
    Entity *e1 = new Player("zhou"); 
    PrintClassName(e1);

    Player *p = new Player("tao"); //ָ��Player�����Player��ָ�룬ֻ�ܷ���Player������Ժͷ���
    PrintClassName(p);
}