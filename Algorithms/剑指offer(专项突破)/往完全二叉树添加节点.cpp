#include <iostream>
#include <queue>
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

class CBTInserter
{
public:
    CBTInserter(TreeNode *root)
    {
        saveLeaf(root);
        this->root = root;
    }

    int insert(int v)
    {
        TreeNode *node = new TreeNode(v);
        TreeNode *leaf = leaf_que.front();

        if (leaf->left == nullptr)
            leaf->left = node;
        else if (leaf->right == nullptr)
            leaf->right = node;

        if (leaf->left != nullptr && leaf->right != nullptr)
            leaf_que.pop();

        leaf_que.push(node);

        return leaf->val;
    }

    TreeNode *get_root()
    {
        return this->root;
    }

private:
    void saveLeaf(TreeNode *root)
    {
        if (root == nullptr)
            return;

        queue<TreeNode*> que;
        TreeNode *node = nullptr;
        que.push(root);

        while (!que.empty())
        {
            node = que.front();
            que.pop();

            if (node->left != nullptr)
                que.push(node->left);
            if (node->right != nullptr)
                que.push(node->right);

            if (node->left == nullptr || node->right == nullptr)
                leaf_que.push(node);
        }
    }

private:
    queue<TreeNode *> leaf_que;
    TreeNode *root;
};

int main()
{
    return 0;
}