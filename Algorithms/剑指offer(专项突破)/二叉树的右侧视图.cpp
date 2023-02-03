#include <iostream>
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

void get_rightSideView(TreeNode *node, vector<int> &res,int cur_height)
{
    if (node == nullptr)
        return;

    if(cur_height>=res.size())
    res.push_back(node->val);
    
    get_rightSideView(node->right,res,cur_height+1);
    get_rightSideView(node->left,res,cur_height+1);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    get_rightSideView(root,res,0);
    return res;
}

int main()
{
    return 0;
}