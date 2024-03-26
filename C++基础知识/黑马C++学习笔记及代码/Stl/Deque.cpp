/*------------------------------------------------------------------------------
 * @file    DEQUE.CPP
 * @author  ZhouRongTao 
 * @date    2024/03/01 11:30:04
------------------------------------------------------------------------------*/
#include <iostream>
#include <deque>
using namespace std;


int main()
{
    deque<int> d = {1, 2, 3, 4};
    deque<int>::iterator it; // 
    for (it = d.begin(); it != d.end(); it++)
        cout << *it << " ";
    cout << endl;
    
    d.push_front(10);
    for (it = d.begin(); it != d.end(); it++)
        cout << *it << " ";
    cout << endl;

    d.pop_back();
    for (it = d.begin(); it != d.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}