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

void sperate_list(ListNode *head, ListNode **left, ListNode **right)
{
    if (head == nullptr)
    {
        *left = nullptr;
        *right = nullptr;
        return;
    }

    ListNode mark(0, head);
    ListNode *par = &mark;
    ListNode *slow = head;
    ListNode *fast = head;

    while (true)
    {
        slow = slow->next;
        par = par->next;
        fast = fast->next;
        fast = fast == nullptr ? nullptr : fast->next;

        if (fast == nullptr || fast->next == nullptr)
        {
            par->next = nullptr;
            break;
        }
    }

    *left = head;
    *right = slow;
}

ListNode *reverse_list(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    ListNode *node = head;
    ListNode *next_node = head->next;
    node->next = nullptr;

    while (next_node != nullptr)
    {
        ListNode *tmp = next_node->next;
        next_node->next = node;
        node = next_node;
        next_node = tmp;
    }

    return node;
}

bool isPalindrome(ListNode *head)
{
    if (head == nullptr)
        return true;

    ListNode *left_list = nullptr;
    ListNode *right_list = nullptr;

    sperate_list(head, &left_list, &right_list);

    if (left_list == right_list)
        return true;

    right_list = reverse_list(right_list);

    while (left_list != nullptr && right_list != nullptr)
    {
        if (left_list->val != right_list->val)
            return false;
        left_list = left_list->next;
        right_list = right_list->next;
    }

    return true;
}

int main()
{

    return 0;
}