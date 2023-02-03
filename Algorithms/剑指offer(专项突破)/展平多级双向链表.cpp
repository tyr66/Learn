#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

Node *make_flatten(Node *node)
{
    if (node == nullptr)
        return nullptr;

    while (node != nullptr)
    {
        Node *sub_list_head = node->child;
        Node *next_node = node->next;

        Node *sub_list_last = make_flatten(sub_list_head);

        if (sub_list_last != nullptr)
        {
            sub_list_last->next = next_node;

            if (next_node != nullptr)
                next_node->prev = sub_list_last;

            node->child = nullptr;
            node->next = sub_list_head;
            sub_list_head->prev = node;
        }

        if (sub_list_last == nullptr && next_node == nullptr)
            return node;

        node = next_node == nullptr ? sub_list_last : next_node;
    } 

    return nullptr;
}

Node *flatten(Node *head)
{
    if (head == nullptr)
        return nullptr;

    make_flatten(head);

    return head;
}