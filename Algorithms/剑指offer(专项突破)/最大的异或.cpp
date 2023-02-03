#include <iostream>
#include <vector>

/*
思路： 前缀树 + 贪心
        对于结果res ，对于res中的每一个位如果可以的话，我们都想取1，将nums中的数字按位存入到前缀树中，如果
        因为每一位只能为1或0，所以该前缀树实质上是一颗二叉树。建立了前缀树之后我们遍历nums 中的每一个数字n
        对于每一个数字我们去遍历前缀树，如果数字n当前位位1 那么我们想要该位位0的数字，因此往节点的zero子节点走
        如果数字n当前位为0，那么我们想要该位为1的话，就需要该位为1的数字，因此往节点的one子节点走.
*/
using namespace std;

struct Node
{
    Node *zero;
    Node *one;
    Node()
    {
        zero = nullptr;
        one = nullptr;
    }
};

int findMaximumXOR(vector<int> &nums)
{
    Node *root = new Node();
    int res = INT_MIN;
    for (auto n : nums)
    {
        Node *node = root;
        int mask = 0x40000000;
        for (int i = 0; i < 31; i++)
        {
            if ((mask & n) != 0)
            {
                node->one = node->one == nullptr ? new Node() : node->one;
                node = node->one;
            }
            else
            {
                node->zero = node->zero == nullptr ? new Node() : node->zero;
                node = node->zero;
            }

            mask = mask >> 1;
        }
    }

    for (auto n : nums)
    {
        Node *node = root;
        int mask = 0x40000000;
        int val = 0;
        for (int i = 0; i < 31; i++)
        {
            if ((mask & n) == 0)
            {
                if (node->one != nullptr)
                {
                    node = node->one;
                    val = val | mask;
                }
                else
                {
                    node = node->zero;
                }
            }
            else
            {
                if (node->zero != nullptr)
                {
                    node = node->zero;
                    val = val | mask;
                }
                else
                {
                    node = node->one;
                }
            }

            mask = mask >> 1;
        }

        if (val > res)
        {
            res = val;
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    cout << findMaximumXOR(arr);
}