#include <iostream>
#include <vector>
#include<queue>
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

vector<int> PrintFromTopToBottom(TreeNode *root)
{
    queue<TreeNode*> que;
    vector<int> res;

    if(root == nullptr)
    return res;

    que.push(root);

    while(que.size()!=0)
    {
        TreeNode* node = que.front();
        que.pop();

        if(node->left!=nullptr)
        {
            que.push(node->left);
        }

        if(node->right!=nullptr)
        {
            que.push(node->right);
        }

        res.push_back(node->val);
    }

    return res;
}

int main()
{

    return 0;
}