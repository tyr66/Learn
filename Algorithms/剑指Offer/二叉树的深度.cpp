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

int TreeDepth(TreeNode *pRoot)
{
    if(pRoot == nullptr)
    return 0;

    int left_height = TreeDepth(pRoot->left);
    int right_height = TreeDepth(pRoot->right);

    return left_height>right_height?left_height+1:right_height+1;
}

int main()
{

    return 0;
}