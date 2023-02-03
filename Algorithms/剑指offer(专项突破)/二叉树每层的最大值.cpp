#include <iostream>
#include<vector>
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

vector<int> largestValues(TreeNode *root)
{
    if(root== nullptr)
    return {};

    queue<TreeNode*> que;
    que.push(root);
    vector<int> res;
    int count = 1;
    int max_value = INT_MIN;

    while(!que.empty())
    {
        TreeNode* node = que.front();
        max_value = max(max_value,node->val);
        que.pop();

        if(node->left!=nullptr)
        {
            que.push(node->left);
        }

        if(node->right!=nullptr)
        {
            que.push(node->right);
        }

        if(--count == 0)
        {
            count = que.size();
            res.push_back(max_value);
            max_value = INT_MIN;
        }

    }

    return res;

}

int main()
{

    return 0;
}