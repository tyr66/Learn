#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void getTree(vector<int>&res,ListNode*node)
{
    if(node == nullptr)
    return;

    getTree(res,node->next);
    res.push_back(node->val);
}

vector<int> printListFromTailToHead(ListNode *head)
{
    vector<int> res;
    getTree(res,head);
    return res;
}

int main()
{
    return 0;
}