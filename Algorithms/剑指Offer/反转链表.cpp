#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

ListNode *ReverseList(ListNode *pHead)
{
    if (pHead == nullptr || pHead->next == nullptr)
        return pHead;
    
    ListNode* prev = nullptr;
    ListNode* node = pHead;
    ListNode* next = pHead->next;

    while(node!=nullptr)
    {
        node->next = prev;
        prev = node;
        node = next;
        next =node!=nullptr? node->next:nullptr;
    }

    return prev;
}

int main()
{
    return 0;
}