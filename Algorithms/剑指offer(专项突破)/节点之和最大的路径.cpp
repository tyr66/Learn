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

/*
暴力算法：
时间复杂度:O(n^2)
*/
int maxValue = INT_MIN;

int getMax(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    int max_value = max(getMax(node->left), getMax(node->right)) + node->val;

    if (max_value <= 0)
    {
        return 0;
    }

    return max_value;
}

void caluate(TreeNode *node)
{
    if (node == nullptr)
        return;

    int value = getMax(node->left) + getMax(node->right) + node->val;

    maxValue = max(value, maxValue);

    caluate(node->left);
    caluate(node->right);
}
/*
优化版本
    时间复杂度：O(n)
*/
int caluate_fast(TreeNode* node)
{
    if (node == nullptr)
        return 0;
    
    int left = max(caluate_fast(node->left), 0) ;
    int right = max(caluate_fast(node->right), 0);

    maxValue = max(maxValue, left + right + node->val);

    return max(left, right) + node->val;
}

int maxPathSum(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    caluate_fast(root);

    return maxValue;
}