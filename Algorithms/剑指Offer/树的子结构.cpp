#include <iostream>
#include <vector>
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

bool check(TreeNode *t1, TreeNode *t2)
{
    if (t1 == nullptr || t2 == nullptr)
        return t2 == nullptr;
    if (t1->val != t2->val)
        return false;
    return check(t1->left, t2->left) && check(t1->right, t2->right);
}

bool hasSubTree(TreeNode *t1, TreeNode *t2)
{
    if (t1 == nullptr)
        return false;

    bool res = t1->val == t2->val && check(t1, t2);

    return res || hasSubTree(t1->left, t2) || hasSubTree(t1->right, t2);
}

bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if (pRoot1 == nullptr || pRoot2 == nullptr)
        return false;

    return hasSubTree(pRoot1, pRoot2);
}

int main()
{

    return 0;
}