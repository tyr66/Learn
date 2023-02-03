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

void makeconvertBST(TreeNode *node, int& sum)
{
    if (node == nullptr)
        return ;

    makeconvertBST(node->right, sum);
    sum += node->val;
    node->val = sum;
    makeconvertBST(node->left, sum);
}

TreeNode *convertBST(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    int sum = 0;
    makeconvertBST(root, sum);

    return root;
}