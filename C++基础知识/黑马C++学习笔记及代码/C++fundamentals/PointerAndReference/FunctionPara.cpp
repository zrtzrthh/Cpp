#include <iostream>
#include <typeinfo> //���Ϳ⣬�жϱ���������

using namespace std;

int Swap1(int num1, int num2); // ��ֵ����
int Swap2(int *num1, int *num2); //ָ�����
int Swap3(int &num1, int &num2); //���õ���

int Swap1(int num1, int num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
    return num1, num2;
}

int Swap2(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    return *num1, *num2;
}

int Swap3(int &num1, int &num2) //����ʱʹ��Swap3(a, b)���൱��int &num1 = a, int &num2 = b;����������������ס������ָ����ô������ࡣ
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
    return num1, num2;
}

int main()
{
    int *c, *d;

    int a = 100, b = 200;
    cout << a << endl;
    cout << b << endl;
    Swap3(a, b);
    cout << a << endl;
    cout << b << endl;

    /*
    c = &a, d = c;
    // cout << typeid(c).name();
    cout << *c << typeid(d).name() << endl;
    */
}