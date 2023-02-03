#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *deleteNode(ListNode *head, int val)
{
    if(head == nullptr)
    return nullptr;

    ListNode tmp_node(-1);
    ListNode*node = head;
    ListNode*prev_node = &tmp_node;
    tmp_node.next = head;

    while(node!=nullptr&&node->val!=val)
    {
        prev_node = node;
        node = node->next;
    }

    if(node!=nullptr)
    {
        prev_node->next = node->next;
        node->next = nullptr;
    }

    return tmp_node.next;
}

int main()
{

    return 0;
}