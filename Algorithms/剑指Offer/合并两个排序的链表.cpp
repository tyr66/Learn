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

ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr || pHead2 == nullptr)
        return pHead1 == nullptr ? pHead2 : pHead1;

    ListNode tmp_node(INT_MIN);
    ListNode *node = &tmp_node;

    while (pHead1 != nullptr || pHead2 != nullptr)
    {
        if (pHead1 == nullptr)
        {
            node->next = pHead2;
            pHead2 = pHead2->next;
        }
        else if (pHead2 == nullptr)
        {
            node->next = pHead1;
            pHead1 = pHead1->next;
        }
        else if (pHead1->val > pHead2->val)
        {
            node->next = pHead2;
            pHead2 = pHead2->next;
        }
        else
        {
            node->next = pHead1;
            pHead1 = pHead1->next;
        }

        node = node->next;
    }

    return tmp_node.next;
}

int main()
{
    return 0;
}