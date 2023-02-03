#include <iostream>
#include<queue>
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

int get_sum(TreeNode*node,int number)
{
    if(node == nullptr)
    return 0;

    number = number*10+node->val;

    if(node->left==nullptr&&node->right==nullptr)
    return number;

    
    return get_sum(node->left,number)+get_sum(node->right,number);
}

int sumNumbers(TreeNode *root)
{
    return get_sum(root,0);
}