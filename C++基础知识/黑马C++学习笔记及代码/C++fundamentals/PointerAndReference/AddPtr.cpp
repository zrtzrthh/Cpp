#include <iostream>
using namespace std;

// ��������
double getAverage(int *arr, int size);

int main()
{
  // ���� 5 ��Ԫ�ص���������
  int balance[5] = {1000, 2, 3, 17, 50}; //balanceʵ�����Ǹ�ָ�룬ָ��������׵�ַ��sizeof(balance)��ʾ����������ռ�ֽ���
  double avg;
  cout << sizeof(balance)/sizeof(balance[0]) << endl;
  // ����һ��ָ�������ָ����Ϊ����
  avg = getAverage(balance, 5);

  // �������ֵ
  cout << "Average value is: " << avg << endl;

  return 0;
}

double getAverage(int *arr, int size)
{
  int i, sum = 0;
  double avg;

  for (i = 0; i < size; ++i)
  {
    sum += arr[i];
  }

  avg = double(sum) / size;

  return avg;
}