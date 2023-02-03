#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
证明 https://leetcode.cn/problems/c32eOV/solution/lian-biao-zhong-huan-de-ru-kou-jie-dian-vvofe/
*/

ListNode *detectCycle(ListNode *head)
{
    if (head == nullptr)
        return head;

    ListNode *slow = head->next;
    ListNode *fast = head->next==nullptr?nullptr:head->next->next;

    while (fast!=nullptr&&fast != slow)
    {
        slow = slow->next;
        fast = fast->next;

        if (fast == slow)
            break;
        
        fast = fast == nullptr ? nullptr : fast->next;
    }

    if (fast != slow||fast == nullptr )
        return nullptr;

    ListNode *res = head;
    while (res != slow)
    {
        res = res->next;
        slow = slow->next;
    }

    return res;
}

int main()
{
    return 0;
}