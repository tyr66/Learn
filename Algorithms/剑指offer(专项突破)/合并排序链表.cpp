#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    auto cmp = [](ListNode *lhs, ListNode *rhs)
    { return lhs->val > rhs->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
    ListNode tmpHead;
    ListNode *node = &tmpHead;

    for (auto node : lists)
    {
        if (node != nullptr)
            pq.push(node);
    }

    while (!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();

        if (tmp->next != nullptr)
        {
            pq.push(tmp->next);
        }
        node->next = tmp;
        node = node->next;
    }

    return tmpHead.next;
}