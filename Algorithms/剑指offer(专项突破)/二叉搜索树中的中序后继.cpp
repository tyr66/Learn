#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findNextInorder(TreeNode *node, TreeNode *target, TreeNode *&next, TreeNode *&res)
{
    if (node == nullptr)
        return;

    findNextInorder(node->left, target, next, res);

    if (next == nullptr)
    {
        next = node;
    }
    else if (next == target)
    {
        res = node;
    }

    next = node;

    if (res == nullptr)
    {
        findNextInorder(node->right, target, next, res);
    }
}

TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
{
    if (root == nullptr || p == nullptr)
        return nullptr;

    TreeNode* next = nullptr;
    TreeNode* res = nullptr;

    findNextInorder(root, p, next, res);

    return res;
}