#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == nullptr)
        return nullptr;

    int list_length = 0;
    ListNode *node = head;

    while (node != nullptr)
    {
        list_length++;
        node = node->next;
    }

    if (n > list_length)
        return head->next;

    ListNode mark(0, head);
    ListNode *fir_parent = &mark;
    ListNode *slow_node = fir_parent;

    for (int i = 0; i < n; i++)
        slow_node = slow_node->next;

    while (slow_node->next != nullptr)
    {
        slow_node = slow_node->next;
        fir_parent = fir_parent->next;
    }

    fir_parent->next = fir_parent->next==nullptr?nullptr:fir_parent->next->next;

    return mark.next;
}