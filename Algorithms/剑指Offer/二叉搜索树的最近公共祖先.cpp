#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int get_lowestCommonAncestor(TreeNode *node, int p, int q)
{
    if (node == nullptr)
        return -1;

    int left = -1;
    int right = -1;

    if (node->val > q)
        left = get_lowestCommonAncestor(node->left, p, q);
    if (node->val < p)
        right = get_lowestCommonAncestor(node->right, p, q);

    if (left != -1 || right != -1)
        return left != -1 ? left : right;

    return node->val;
}

int lowestCommonAncestor(TreeNode *root, int p, int q)
{
    if (root == nullptr)
        return -1;

    if (p > q)
        swap(p, q);

    return get_lowestCommonAncestor(root, p, q);
}