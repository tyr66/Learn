#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *FindKthToTail(ListNode *pHead, int k)
{
    if (pHead == nullptr || k <= 0)
        return nullptr;

    ListNode *kStep_node = pHead;

    for (int i = 0; i < k - 1; i++)
    {
        if (kStep_node->next != nullptr)
        {
            kStep_node = kStep_node->next;
        }
        else
            return nullptr;
    }

    ListNode *node = pHead;

    while (kStep_node->next != nullptr)
    {
        node = node->next;
        kStep_node = kStep_node->next;
    }

    return node;
}

int main()
{

    return 0;
}