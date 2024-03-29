# 十大排序算法

## 冒泡排序

**最优时间复杂度：**O(n)（数组元素都是有序的）

**最坏时间复杂度：**O(n^2) （数组元素都是倒序，每次都要交换）

**平均时间复杂度：**O(n^2)（数组元素都是无序的）

1. 循环实现

   ```cpp
   void BubbleSort1(int *arr, int n)
   {
       if (n < 2)
           return;
       int i, j, temp;
       for (i = 0; i < n - 1; i++)
       {
           for (j = 0; j < n - i - 1; j++)
           {
               if (*(arr + j) > *(arr + j + 1))
               {
                   Swap(arr + j, arr + j + 1); //交换元素
               }
           }
       }
   }
   ```

2. 递归实现

   ```cpp
   void BubbleSort2(int *arr, int n)
   {
       if(n < 2) 
           return;
       int i, temp;
       for(i = 0; i < n-1; i++)
       {
           if(*(arr + i) > *(arr + i + 1))
           {
               Swap(arr + i, arr + i + 1); //交换元素
           }
       }
       BubbleSort2(arr, --n);
   }
   ```

注：Swap函数如下定义：

```cpp
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

冒泡排序的优化：如果进行i次排序后，数组已经有序，原始的冒泡排序还要继续比较下去，浪费时间，则可采用下列优化的冒泡排序：

1. 循环实现

   ```cpp
   void BubbleSort1(int *arr, int n)
   {
       if (n < 2)
           return;
       int i, j, temp;
       for (i = 0; i < n - 1; i++)
       {
           int ifSwap = 0; //设置一个ifSwap变量，记录是否发生过元素交换
           for (j = 0; j < n - i - 1; j++)
           {
               if (*(arr + j) > *(arr + j + 1))
               {
                   Swap(arr + j, arr + j + 1);
                   ifSwap = 1;
               }
           }
           if (!ifSwap) //如果没发生元素交换，说明前面的n-i个元素都是有序的，跳出循环
               break;
       }
   }
   ```

2. 递归实现：

   ```cpp
   void BubbleSort2(int *arr, int n)
   {
       if (n < 2)
           return;
       int i, temp, ifSwap = 0; //设置一个ifSwap变量，记录是否发生过元素交换
       for (i = 0; i < n - 1; i++)
       {
           if (*(arr + i) > *(arr + i + 1))
           {
               Swap(arr + i, arr + i + 1);
               ifSwap++;
           }
       }
       cout << n <<endl;
       if (!ifSwap) //如果没发生元素交换，说明前面的n-i个元素都是有序的，不用继续递归
           return;
       BubbleSort2(arr, --n);
   }
   ```

## 选择排序

从第一个元素开始，选后面最小的元素与第一个元素交换

```cpp
void ChooseSort1(int *arr, int n) //循环实现
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
```



**优化**：同时将最小的元素放在前面，而把最大的元素放在后面

```cpp
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
        if (maxIndex == i)  //注意这一步的处理！！！
        {
            maxIndex = miniIndex;
        }
        if (maxIndex != n - 1 - i)
        {
            Swap(arr + maxIndex, arr + n - 1 - i);
        }
        
    }
}
```

## 堆排序

1. 将待排序数组转化为一个堆，堆顶元素就是最大
2. 将堆顶元素与最后一个元素交换，并维护除最后一个元素之前的堆
3. 最后得到的数组就是从小到大排序的数组

```cpp
#include<iostream>
using namespace std;

void maxHeapfiy(int* arr, int start, int end) //维护堆
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
	for (int i = len / 2 - 1; i >= 0; i--) //将数组构造为一个最大堆
	{
		maxHeapfiy(arr, i, len - 1);
	}
	for (int i = len - 1; i >0; i--) //调整首尾元素，并维护最大堆
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
```

