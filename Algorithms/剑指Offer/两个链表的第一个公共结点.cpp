#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

int get_list_length(ListNode *node)
{
    int length = 0;

    while (node != nullptr)
    {
        length++;
        node = node->next;
    }

    return length;
}

ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr || pHead2 == nullptr)
        return nullptr;

    int first_length = get_list_length(pHead1);
    int second_length = get_list_length(pHead2);

    if (second_length > first_length)
    {
        swap(pHead1, pHead2);
        swap(second_length,first_length);
    }

    ListNode *firNode = pHead1;
    ListNode *secNode = pHead2;

    for(int i = second_length;i<first_length;i++)
        firNode = firNode->next;

    while(firNode!=nullptr&&secNode!=nullptr)
    {
        if(firNode == secNode)
        {
            return firNode;
        }
        firNode = firNode->next;
        secNode = secNode->next;
    }

    return nullptr;
}

int main()
{
    return 0;
}