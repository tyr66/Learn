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

void findPath(vector<vector<int>> &res, vector<int> &path, TreeNode *root, int number)
{
    if (root == nullptr)
    {
        return;
    }

    number -= root->val;
    path.push_back(root->val);
    findPath(res, path, root->left, number);
    findPath(res, path, root->right, number);

    if (root->left == nullptr && root->right == nullptr && number == 0)
        res.push_back(path);

    path.pop_back();
}

vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
{
    vector<vector<int>> res;
    vector<int> path;

    findPath(res, path, root, expectNumber);

    return res;
}

int main()
{
    return 0;
}
