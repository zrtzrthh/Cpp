#include <iostream>

using namespace std;

double nums[] = {10, 23.2, 25.3, 23.1, 0.2};

double &setValues(int i) //���ص���nums[i]������
{
    double &ref = nums[i];
    return ref;
}

int main()
{
    setValues(1) = 20.23; // �ı�� 2 ��Ԫ��
    setValues(3) = 70.8;  // �ı�� 4 ��Ԫ��

    cout << "�ı���ֵ" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "nums[" << i << "] = ";
        cout << nums[i] << endl;
    }
    return 0;
}
