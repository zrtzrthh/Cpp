/*------------------------------------------------------------------------------
 * @file    FUNCTIONTEMPLATE.CPP
 * @author  ZhouRongTao 
 * @date    2024/02/28 18:00:04
------------------------------------------------------------------------------*/
#include <iostream>
#include <string>

template <class T>
void swap(T &a, T &b)
{
    T temp;
    temp = b;
    b = a;
    a = temp;

}

int main()
{
    int a = 10, b = 20;
    std::string a1 = "nihao", b1 = "haoni";
    swap(a,b);
    swap(a1, b1);
    std::cout << a << b;
    std::cout << a1 << b1;
}