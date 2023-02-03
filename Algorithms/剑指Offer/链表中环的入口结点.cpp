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

int get_cycleLength(ListNode *fast, ListNode *slow)
{
    if (fast == nullptr || slow == nullptr)
        return 0;

    int res = 0;

    do
    {
        fast = fast->next;
        res++;
    } while (fast != slow);
    return res;
}

ListNode *EntryNodeOfLoop(ListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;

    ListNode *slow = pHead;
    ListNode *fast = pHead;

    while (fast!=nullptr&&fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast==nullptr||fast->next == nullptr)
        return nullptr;

    int length = get_cycleLength(fast, slow);

    ListNode *prev_node = pHead;
    ListNode*node = pHead;

    for (int i = 0; i < length - 1; i++)
        prev_node = prev_node->next;
    
    while(prev_node->next!=node)
    {
        prev_node = prev_node->next;
        node = node->next;
    }

    return node;
}

int main()
{

    return 0;
}