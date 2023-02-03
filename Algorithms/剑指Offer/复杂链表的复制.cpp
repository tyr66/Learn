#include <iostream>
using namespace std;

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL)
    {
    }
};

RandomListNode *Clone(RandomListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;

    RandomListNode *node = pHead;

    while (node != nullptr)
    {
        RandomListNode *newNode = new RandomListNode(node->label);
        RandomListNode *nextNode = node->next;
        node->next = newNode;
        newNode->next = nextNode;
        node = newNode->next;
    }

    node = pHead;
    RandomListNode *expandNode = node->next;

    while (node != nullptr)
    {
        if (node->random != nullptr)
            expandNode->random = node->random->next;

        node = expandNode->next;
        if (node != nullptr)
            expandNode = node->next;
    }

    RandomListNode *result = pHead->next;

    node = pHead;
    expandNode = node->next;

    while (node != nullptr)
    {
        node->next = expandNode->next;
        node = expandNode->next;
        if (node != nullptr)
            expandNode->next = node->next;
        expandNode = expandNode->next;
    }

    return result;
}