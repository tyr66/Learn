#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
时间复杂度O(n)，空间复杂度O(n)
此处使用了深度优先遍历的方法，但是使用广度优先遍历的方式会让代码更加的简洁易懂
并且编码后的字符串更短
*/


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "";

        stack<TreeNode *> st;
        TreeNode *node = root;
        string res = to_string(root->val);
        st.push(root);

        while (!st.empty())
        {

            node = node->left;

            if (node == nullptr)
            {
                res += ",n";
                while (!st.empty() && st.top()->right == nullptr)
                {
                    res += ",n";
                    st.pop();
                }

                if (!st.empty())
                {
                    node = st.top()->right;
                    st.pop();
                    st.push(node);
                    res += "," + to_string(node->val);
                }
            }
            else
            {
                res += "," + to_string(node->val);
                st.push(node);
            }
        }

        return res;
    }

    TreeNode *deserialize(string data)
    {
        cout << data << endl;
        if (data.empty())
            return nullptr;

        int idx = 0;
        stack<TreeNode *> st;
        TreeNode *root = get_node(data, idx);
        st.push(root);

        while (!st.empty() && idx < data.size())
        {
            TreeNode *node = st.top();
            node->left = get_node(data, idx);

            if (node->left != nullptr)
            {
                st.push(node->left);
                continue;
            }

            while (!st.empty())
            {
                st.top()->right = get_node(data, idx);

                if (st.top()->right != nullptr)
                    break;

                st.pop();
            }

            if (!st.empty())
            {
                node = st.top()->right;
                st.pop();
                st.push(node);
            }
        }

        return root;
    }

private:
    int get_number(const string &data, int &idx)
    {
        int res = 0;

        while (idx < data.size() && data[idx] != ',')
        {
            res = res * 10 + (data[idx++] - '0');
        }

        idx++;
        return res;
    }

    TreeNode *get_node(const string &data, int &idx)
    {
        if (data[idx] == 'n')
        {
            idx += 2;
            return nullptr;
        }

        int sign = 1;
        if (data[idx] == '-')
        {
            sign = -1;
            idx++;
        }

        int val = get_number(data, idx);
        return new TreeNode(val * sign);
    }
};

int main()
{
    return 0;
}