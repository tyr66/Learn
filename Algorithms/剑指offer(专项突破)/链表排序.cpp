#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int getLength(ListNode* head)
{
    if (head == nullptr)
        return 0;

    int res = 0;
    while (head != nullptr)
    {
        res++;
        head = head->next;
    }

    return res;
}

ListNode* getNextNode(ListNode* node, int step)
{
    if (node == nullptr)
        return nullptr;

    for (int i = 0; i < step; i++)
    {
        if (node->next == nullptr)
            break;

        node = node->next;
    }

    return node;
}

void mergeList(ListNode* lhs, ListNode* rhs, ListNode*& head, ListNode*& tail)
{
    if (lhs == nullptr && rhs == nullptr)
    {
        head = nullptr;
        tail = nullptr;
        return;
    }

    ListNode res;
    ListNode* mergeNext = &res;

    while (lhs != nullptr || rhs != nullptr)
    {
        if (lhs == nullptr)
        {
            mergeNext->next = rhs;
            rhs = rhs->next;
        }
        else if (rhs == nullptr)
        {
            mergeNext->next = lhs;
            lhs = lhs->next;
        }
        else if (lhs->val < rhs->val)
        {
            mergeNext->next = lhs;
            lhs = lhs->next;
        }
        else
        {
            mergeNext->next = rhs;
            rhs = rhs->next;
        }

        mergeNext = mergeNext->next;
    }

    head = res.next;
    tail = mergeNext;
}

ListNode* sortList(ListNode* head)
{
    if (head == nullptr)
        return nullptr;

    ListNode thead = ListNode();
    thead.next = head;
    ListNode* prev = &thead;

    int length = getLength(head);

    for (int i = 1; i < length; i <<= 1)
    {
        int remain = length;
        prev = &thead;
        while (remain > i)
        {
            ListNode* first_head = prev->next;
            ListNode* first_tail = getNextNode(first_head, i - 1);
            ListNode* second_head = first_tail->next;
            ListNode* second_tail = getNextNode(second_head, i - 1);
            ListNode* next = second_tail->next;
            ListNode* nextPrev = nullptr;
            first_tail->next = nullptr;
            second_tail->next = nullptr;

            mergeList(first_head, second_head, prev->next, nextPrev);
            nextPrev->next = next;
            prev = nextPrev;
            remain -= i * 2;
        }
    }

    return thead.next;
}

ListNode* createList(vector<int>& arr)
{
    ListNode head;
    ListNode* res = &head;
    for (auto n : arr)
    {
        res->next = new ListNode(n);
        res = res->next;
    }

    return head.next;
}

void print_list(ListNode* head)
{
    if (head == nullptr)
        return;

    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

void test1()
{
    vector<int> arr = { 4,2,1,3,5 };
    ListNode* list = createList(arr);
    list = sortList(list);
    print_list(list);
}

void test2()
{
    vector<int> arr = { -1,5,3,4,0 };
    ListNode* list = createList(arr);
    list = sortList(list);
    print_list(list);
}

int main()
{
    test1();
    test2();
    return 0;
}