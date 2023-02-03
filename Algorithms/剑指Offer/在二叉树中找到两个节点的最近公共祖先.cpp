#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

TreeNode* get_lowestCommonAncestor(TreeNode *node,int o1,int o2)
{
    if(node == nullptr||node->val == o1||node->val == o2)
    return node;

    TreeNode* left = get_lowestCommonAncestor(node->left,o1,o2);
    TreeNode* right = get_lowestCommonAncestor(node->right,o1,o2);

    if(left == nullptr)
    return right;

    if(right == nullptr)
    return left;

    return nullptr;
}

int lowestCommonAncestor(TreeNode *root, int o1, int o2)
{
    TreeNode*res = get_lowestCommonAncestor(root, o1, o2);

    return res!=nullptr?res->val:-1;
}