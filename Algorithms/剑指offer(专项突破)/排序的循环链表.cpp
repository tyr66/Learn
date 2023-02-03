#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val)
    {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next)
    {
        val = _val;
        next = _next;
    }
};

Node *insert(Node *head, int insertVal)
{
    if (head == nullptr)
    {
        Node *node = new Node(insertVal);
        node->next = node;
        return node;
    }

    Node *target_node = head;

    while (true)
    {

        if (target_node->val <= insertVal && insertVal <= target_node->next->val)
            break;
        // prev_node->val>target_node->val此时prev_node 指向最大节点而target_node指向最小节点
        if (target_node->val>target_node->next->val && 
        (insertVal <= target_node->next->val || insertVal >= target_node->val))
            break;
        
        target_node = target_node->next;

        if (target_node == head)
            break;
    }
    

    Node *node = new Node(insertVal);
    Node *next_node = target_node->next;
    target_node->next = node;
    node->next = next_node;
    return head;
}