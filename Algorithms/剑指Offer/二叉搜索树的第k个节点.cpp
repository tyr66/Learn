#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isFind = false;
int idx = 0;

int KthNode(TreeNode *proot, int k)
{
    if (proot == nullptr)
        return -1;

    int tar = KthNode(proot->left, k);

    if (idx == k)
        return tar;
    
    idx++;

    if(idx == k)
    return proot->val;

    return KthNode(proot->right,k);
}