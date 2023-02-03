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

bool is_symmetrical(TreeNode *left_node, TreeNode *right_node)
{
    if (left_node == nullptr || right_node == nullptr)
        return left_node == nullptr && right_node == nullptr;

    return left_node->val == right_node->val
     && is_symmetrical(left_node->left, right_node->right) 
     && is_symmetrical(left_node->right, right_node->left);
}

bool isSymmetrical(TreeNode *pRoot)
{
    if(pRoot == nullptr)
    return true;

    return is_symmetrical(pRoot->left,pRoot->right);
}

int main()
{

    return 0;
}