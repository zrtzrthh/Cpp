/*------------------------------------------------------------------------------
 * @file    CHOOSESORTOPTIMAL.CPP
 * @author  ZhouRongTao 
 * @date    2024/03/07 20:57:52
------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

void Swap(int *a, int *b);
void ChooseSort1(int *a, int n);
void Print(int *arr, int n);

void ChooseSort1(int *arr, int n)
{
    if (n < 2)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int miniIndex = i;
        int maxIndex = n - 1 - i; 
        for (int j = i; j < n - i; j++)
        {
            if (arr[j] < arr[miniIndex])
            {
                miniIndex = j;
            }
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }
        if (miniIndex != i)
        {
            Swap(arr + i, arr + miniIndex);
        }
        if (maxIndex == i)
        {
            maxIndex = miniIndex;
        }
        if (maxIndex != n - 1 - i)
        {
            Swap(arr + maxIndex, arr + n - 1 - i);
        }
        
    }
}

void ChooseSort2(int *arr, int n) //递归实现
{
    if (n < 2)
    {
        return;
    }
    int miniIndex = 0; 
    int maxIndex = n - 1;
    for (int j = 0; j < n; j++) 
    {
        if (arr[j] < arr[miniIndex])
        {
            miniIndex = j;
        }
        if (arr[j] > arr[maxIndex])
        {
            maxIndex = j;
        }
    }
    if (miniIndex != 0) //如果miniIndex不是第一个数组的元素，则交换
    {
        Swap(arr, arr + miniIndex);
    }
    if (maxIndex != n-1)
    {
        Swap(arr + n - 1, arr + maxIndex);
    }
    
    ChooseSort2(arr + 1, n - 2); //arr+1表示从下一个元素开始的数组
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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
    ChooseSort1(arr, 10);
    Print(arr, 10);
}