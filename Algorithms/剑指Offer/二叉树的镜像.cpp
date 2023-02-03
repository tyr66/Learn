#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void make_mirror(TreeNode *node)
{
    if (node == nullptr)
        return;

    swap(node->left, node->right);
    make_mirror(node->left);
    make_mirror(node->right);
}

TreeNode *Mirror(TreeNode *pRoot)
{
    if (pRoot == nullptr)
        return nullptr;

    make_mirror(pRoot);
    return pRoot;
}

int main()
{

    return 0;
}