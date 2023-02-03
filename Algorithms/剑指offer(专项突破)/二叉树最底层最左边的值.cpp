#include <iostream>
#include<queue>
#include <vector>
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

int findBottomLeftValue(TreeNode *root)
{
    if(root == nullptr)
    return -1;

    queue<TreeNode*> que;
    que.push(root);
    int count = 1;
    int res = root->val;

    while(!que.empty())
    {
        TreeNode* node = que.front();
        que.pop();

        if(node->left!=nullptr)
        que.push(node->left);
        if(node->right!=nullptr)
        que.push(node->right);

        if(--count == 0)
        {
            count  = que.size();
            res = que.empty()?res:que.front()->val;
        }
    }

    return res;
}

int main()
{
    return 0;
}