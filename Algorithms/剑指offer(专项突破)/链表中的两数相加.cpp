#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr || l2 == nullptr)
        return l1 == nullptr ? l2 : l1;

    stack<int> l1_stack;
    stack<int> l2_stack;

    while (l1 != nullptr)
    {
        l1_stack.push(l1->val);
        l1 = l1->next;
    }

    while (l2 != nullptr)
    {
        l2_stack.push(l2->val);
        l2 = l2->next;
    }

    ListNode *node = new ListNode(0,nullptr);
    int carry = 0;

    while (!l1_stack.empty() || !l2_stack.empty()||carry!=0)
    {

        int val = carry;
        val += l1_stack.empty() ? 0 : l1_stack.top();
        val += l2_stack.empty() ? 0 : l2_stack.top();

        node->val = val % 10;
        carry = val / 10;

        if (!l1_stack.empty())
        {
            l1_stack.pop();
        }
        if (!l2_stack.empty())
        {
            l2_stack.pop();
        }

        if (!l1_stack.empty() || !l2_stack.empty()||carry!=0)
        {
            ListNode *tmp = new ListNode(0,node);
            node = tmp;
        }

    }

    return node;
}

int main()
{

    return 0;
}