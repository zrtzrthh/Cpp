/*------------------------------------------------------------------------------
 * @file    LINKEDLIST.CPP
 * @author  ZhouRongTao
 * @date    2023/11/10 20:29:27
------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;                                // �ڵ��ϴ洢��Ԫ��
    ListNode *next;                         // ָ����һ���ڵ��ָ��
    ListNode(int x) : val(x), next(NULL) {} // �ڵ�Ĺ��캯��
};

ListNode *insertNode(ListNode *head, int val)
{
    ListNode *newNode = new ListNode(0);
    newNode->val = val;
    newNode->next = head;
    return newNode;
};

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head != nullptr && head->val == val)
        {
            ListNode *temp;
            temp = head;
            head = head->next;
            delete temp;
        }
        ListNode *cur = head;
        while (cur != nullptr)
        {
            if(cur->next != nullptr && cur->next->val == val)
            {
                ListNode *temp;
                temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else
            {
                cur = cur->next;
            } 
        }
        
        return head;
    }
};

int main()
{
    ListNode *head = nullptr;
    head = insertNode(head, 10);
    head = insertNode(head, 9);
    head = insertNode(head, 8);
    head = insertNode(head, 7);
    printList(head);

    Solution solution;
    ListNode *result;
    result = solution.removeElements(head, 10);
    cout << "ɾ���������Ϊ��" ;
    printList(result);
    return 0;
    system("pause");
}
