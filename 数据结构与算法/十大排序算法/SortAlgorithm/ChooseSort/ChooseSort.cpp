/*------------------------------------------------------------------------------
 * @file    CHOOSESORT.CPP
 * @author  ZhouRongTao
 * @date    2024/03/07 20:11:43
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
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[miniIndex])
            {
                miniIndex = j;
            }
        }
        if (miniIndex != i)
        {
            Swap(arr + i, arr + miniIndex);
        }
    }
}

void ChooseSort2(int *arr, int n)
{
    if (n < 2)
    {
        return;
    }
    int miniIndex = 0; 
    for (int j = 0; j < n; j++)
    {
        if (arr[j] < arr[miniIndex])
        {
            miniIndex = j;
        }
    }
    if (miniIndex != 0)
    {
        Swap(arr, arr + miniIndex);
    }
    ChooseSort2(arr + 1, --n);
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
    ChooseSort2(arr, 10);
    Print(arr, 10);
}