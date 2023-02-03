#include <vector>
#include <string>
#include <iostream>
using namespace std;

/*
思路： 逆序的将单词插入到字典序中，然后统计每个叶子节点的深度即可
优化：我们可以在生成前缀树的时候就把叶子节点与其深度记录下来，就不需要遍历前缀树了
时间复杂度： O(w) , 其中w为字典中所有单词的字符总数
空间 复杂度： O(c * w) 其中c表示字符集，w表示字典中所有单词的字符总数
*/

#define MAX_CHILD_COUNT 26
#define INDEXOF(x) (x) - 'a'

struct Node
{
    bool isWord;
    Node *next[MAX_CHILD_COUNT];

    Node() : isWord(false)
    {
        memset(next, 0, sizeof(next));
    }

    Node(bool isWord) : isWord(isWord)
    {
        memset(next, 0, sizeof(next));
    }
};

class Trie
{
public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        insert(root, word, word.size() - 1);
    }

    int findLeafDist()
    {
        int res = 0;
        findLeafDist(root, 1, res);
        return res;
    }
    ~Trie()
    {
        destory(root);
    }

private:
    void findLeafDist(Node* node, int depth, int& res)
    {
        bool isLeaf = true;

        for (int i = 0; i < MAX_CHILD_COUNT; i++)
        {
            if (node->next[i] != nullptr)
            {
                isLeaf = false;
                findLeafDist(node->next[i], depth + 1, res);
            }
        }

        if (isLeaf){
            res += depth;
        }
    }
    void insert(Node *node, const string &word, int idx)
    {
        if (idx < 0)
        {
            node->isWord = true;
            return;
        }

        if (node->next[INDEXOF(word[idx])] == nullptr)
        {
            node->next[INDEXOF(word[idx])] = new Node();
        }

        insert(node->next[INDEXOF(word[idx])], word, idx - 1);
    }

    void destory(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        for (int i = 0; i < MAX_CHILD_COUNT; i++)
        {

            if (node->next[i] != nullptr)
                destory(node->next[i]);
        }

        delete node;
    }

private:
    Node *root;
};

int minimumLengthEncoding(vector<string> &words)
{
    Trie trie;
    for (auto &str : words)
    {
        trie.insert(str);
    }
    return trie.findLeafDist();
}