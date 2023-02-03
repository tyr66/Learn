#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> pre, vector<int> vin, int lo, int hi, int n)
{
    if (lo > hi)
        return nullptr;
    if (lo == hi)
        return new TreeNode(pre[n]);

    TreeNode *node = new TreeNode(pre[n]);

    int tar = -1;
    for (int i = lo; i <= hi; i++)
    {
        if(pre[n] == vin[i])
        {
            tar = i;
            break;
        }
    }

    node->left = buildTree(pre,vin,lo,tar-1,n+1);
    node->right = buildTree(pre,vin,tar+1,hi,n+(tar - lo+1));
    return node;
}

TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    return buildTree(pre,vin,0,vin.size()-1,0);
}

int main()
{
    return 0;
}