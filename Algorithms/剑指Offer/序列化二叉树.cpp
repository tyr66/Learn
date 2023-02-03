#include <iostream>
#include <string>
#include <queue>
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

string res = "";

char *Serialize(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    queue<TreeNode *> que;
    que.push(root);
    res.clear();

    while (!que.empty())
    {
        TreeNode *node = que.front();
        que.pop();

        if (node == nullptr)
        {
            res.push_back(-1);
            continue;
        }

        res.push_back(1 + node->val);
        que.push(node->left);
        que.push(node->right);
    }

    return (char *)res.c_str();
}

TreeNode *Deserialize(char *str)
{
    if (str == nullptr)
        return nullptr;
    int len = strlen(str);
    if (len == 0)
        return nullptr;

    TreeNode *root = new TreeNode((unsigned char)str[0] - 1);
    queue<TreeNode *> que;
    que.push(root);

    for (int i = 1; i < len; i += 2)
    {
        TreeNode *node = que.front();
        if (str[i] != -1)
        {
            node->left = new TreeNode((unsigned char)str[i] - 1);
            que.push(node->left);
        }
        if (str[i + 1] != -1)
        {
            node->right = new TreeNode((unsigned char)str[i + 1] - 1);
            que.push(node->right);
        }
        que.pop();
    }
    return root;
}

int main()
{
}