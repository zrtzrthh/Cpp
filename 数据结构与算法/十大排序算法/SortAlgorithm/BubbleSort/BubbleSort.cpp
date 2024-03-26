/*------------------------------------------------------------------------------
 * @file    BUBBLESORT.CPP
 * @author  ZhouRongTao
 * @date    2023/12/07 12:42:31
------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

void Swap(int *a, int *b);         // 交换两个元素
void BubbleSort1(int *arr, int n); // 冒泡排序，循环实现
void BubbleSort2(int *arr, int n); // 递归实现
void Print(int *arr, int n);       // 打印整个数组

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort1(int *arr, int n)
{
    if (n < 2)
        return;
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        int k = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                Swap(arr + j, arr + j + 1);
                k++;
            }
        }
        if (!k)
            break;
    }
}

void BubbleSort2(int *arr, int n)
{
    if (n < 2)
        return;
    int i, temp, k = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (*(arr + i) > *(arr + i + 1))
        {
            Swap(arr + i, arr + i + 1);
            k++;
        }
    }
    cout << n <<endl;
    if (!k)
        return;
    else
        BubbleSort2(arr, --n);
}

void Print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " ";
    }
}

int main()
{
    int arr[10] = {1, 5, 3, 6, 9, 62, 2, 53, 25, 56};
    BubbleSort2(arr, 10);
    Print(arr, 10);
}
