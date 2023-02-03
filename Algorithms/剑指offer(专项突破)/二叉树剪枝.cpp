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

bool cut_pruneTree(TreeNode *node)
{
    if (node == nullptr)
        return true;

    bool cut_left = cut_pruneTree(node->left);
    bool cut_right = cut_pruneTree(node->right);

    if (cut_left)
        node->left = nullptr;
    if (cut_right)
        node->right = nullptr;

    return node->val == 0 && cut_left && cut_right;
}

TreeNode *pruneTree(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    return cut_pruneTree(root)?nullptr:root;
}

int main()
{

    return 0;
}