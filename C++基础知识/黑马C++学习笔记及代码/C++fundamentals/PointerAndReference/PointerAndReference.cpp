#include <iostream>

using namespace std;

int main()
{
    int b = 100;
    int &a = b; //���ò��ܸı䣬ֻ��������ʱ�Ͷ��塣
    cout << &a << endl;
    cout << &b << endl;
    a++;
    cout << a << ' ' << b << endl;
}