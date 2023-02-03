#include <iostream>
#include <stack>
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

class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        if (st.empty()) {
            throw;
        }

        auto resNode = st.top();
        int res = resNode->val;
        resNode = resNode->right;
        st.pop();
        
        while (resNode != nullptr) {
            st.push(resNode);
            resNode = resNode->left;
        }

        return res;
    }

    bool hasNext()
    {
        return !st.empty();
    }

private: 
    stack<TreeNode*> st;
};