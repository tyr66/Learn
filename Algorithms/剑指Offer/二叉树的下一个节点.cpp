#include <iostream>
#include <vector>
using namespace std;

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

TreeLinkNode *GetNext(TreeLinkNode *pNode)
{
    if (pNode == nullptr)
        return nullptr;

    TreeLinkNode *node = nullptr;

    if (pNode->right != nullptr)
    {
        node = pNode->right;
        while (node->left != nullptr)
        {
            node = node->left;
        }
    }
    else
    {
        TreeLinkNode *parent = pNode->next;
        node = pNode;
        while (node != nullptr)
        {
            if (parent != nullptr && parent->left == node)
            {
                node = parent;
                break;
            }
            node = parent;
            parent = node != nullptr ? node->next : nullptr;
        }
    }

    return node;
}

int main()
{
    return 0;
}