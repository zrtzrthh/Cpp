#include<iostream>
using namespace std;

void maxHeapfiy(int* arr, int start, int end) //Î¬»¤¶Ñ
{
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end)
	{
		if (son + 1 <= end && arr[son + 1] > arr[son]) 
		{
			son++;
		}
		if(arr[dad] > arr[son])
		{
			return;
		}
		else
		{
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heapSort(int* arr, int len)
{
	for (int i = len / 2 - 1; i >= 0; i--) 
	{
		maxHeapfiy(arr, i, len - 1);
	}
	for (int i = len - 1; i >0; i--)
	{
		swap(arr[0], arr[i]);
		maxHeapfiy(arr, 0, i - 1);
	}
}

int main()
{
	int arr[] = { 2,5,6,9,10,35,65,95,20,10 };
	heapSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
}