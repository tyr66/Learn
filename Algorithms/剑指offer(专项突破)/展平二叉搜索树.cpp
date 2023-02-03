#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void unfoldBST(TreeNode *node, TreeNode*& next, TreeNode*& res)
{
    if (node == nullptr)
        return;
    
    unfoldBST(node->left, next, res);

    if (res == nullptr){
        res = node;
        next = node;
        next->left = nullptr;
    }else {
        next->right = node;
        next->left = nullptr;
        next = node;
    }

    unfoldBST(node->right, next, res);
}

TreeNode *increasingBST(TreeNode *root)
{
    TreeNode* next = nullptr;
    TreeNode* res = nullptr;
    
    unfoldBST(root, next, res);

    next->left = nullptr;
    next->right = nullptr;

    return res;
}