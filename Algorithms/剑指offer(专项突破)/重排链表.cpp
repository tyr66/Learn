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

void make_sperate_list(ListNode *head, ListNode **left, ListNode **right)
{
    if (head == nullptr)
        return;

    ListNode mask(0, head);
    ListNode *par = &mask;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != nullptr)
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

ListNode *get_reverse_list(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    ListNode *par = head;
    ListNode *node = head->next;
    par->next = nullptr;

    while (node != nullptr)
    {
        ListNode *tmp = node->next;
        node->next = par;
        par = node;
        node = tmp;
    }

    return par;
}

void print_list(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void reorderList(ListNode *head)
{
    if (head == nullptr)
        return;

    ListNode *left_list;
    ListNode *right_list;
    make_sperate_list(head, &left_list, &right_list);

    if (left_list == right_list)
        return;

    ListNode *reverse_list = get_reverse_list(right_list);
    // print_list(left_list);

    // print_list(reverse_list);
    while (left_list != nullptr && reverse_list != nullptr)
    {
        ListNode *tmp = left_list->next;
        left_list->next = reverse_list;
        left_list = tmp;

        if (left_list == nullptr)
            break;

        tmp = reverse_list->next;
        reverse_list->next = left_list;
        reverse_list = tmp;
    }
}
