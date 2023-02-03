#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

void treeToList(TreeNode *node, TreeNode **left, TreeNode **right)
{
    if (node == nullptr)
    {
        *left = nullptr;
        *right = nullptr;
        return;
    }

    TreeNode *l_left = nullptr;
    TreeNode *l_right = nullptr;

    treeToList(node->left, &l_left, &l_right);

    if (l_left != nullptr && l_right != nullptr)
    {
        node->left = l_right;
        l_right->right = node;
    }
    else
    {
        l_left = l_right = node;
    }

    TreeNode *r_left = nullptr;
    TreeNode *r_right = nullptr;

    treeToList(node->right, &r_left, &r_right);

    if (r_left != nullptr && r_right != nullptr)
    {
        node->right = r_left;
        r_left->left = node;
    }
    else
    {
        r_left = r_right = node;
    }

    *left = l_left;
    *right = r_right;
}

TreeNode *Convert(TreeNode *pRootOfTree)
{
    if (pRootOfTree == nullptr)
        return pRootOfTree;

    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    treeToList(pRootOfTree, &left, &right);

    return left;
}


int main()
{
    return 0;
}