#include <string>
#include <iostream>
#include <vector>

using namespace std;
/*
思路：使用 前缀树来保存单词，并且通过在节点中添加额外字段来保存从该节点到它所有叶子节点的开销
*/
#define MAX_CHILD_COUNT 26
#define INDEXOF(x) (x) - 'a'

struct Node
{
    bool isWord;
    Node *next[MAX_CHILD_COUNT];
    int sum;
    int value;

    Node() : isWord(false), value(0), sum(0)
    {
        memset(next, 0, sizeof(next));
    }

    Node(bool isWord) : isWord(isWord)
    {
        memset(next, 0, sizeof(next));
    }
};

class MapSum
{
public:
    MapSum()
    {
        root = new Node();
    }

    void insert(const string &key, int val)
    {
        insert(root, key, 0, val);
    }

    int sum(const string &prefix)
    {
        return sum(root, prefix, 0);
    }

private:
    int insert(Node *node, const string &key, int idx, int val)
    {
        if (idx >= key.size())
        {
            node->isWord = true;
            node->sum = node->sum - node->value + val;
            node->value = val;
            return node->sum;
        }

        if (node->next[INDEXOF(key[idx])] == nullptr)
        {
            node->next[INDEXOF(key[idx])] = new Node();
        }
        int childSum = node->next[INDEXOF(key[idx])]->sum;
        node->sum = node->sum - childSum + insert(node->next[INDEXOF(key[idx])], key, idx + 1, val);

        return node->sum;
    }

    int sum(Node *node, const string &prefix, int idx)
    {

        if (node == nullptr)
            return 0;
        if (idx < prefix.size())
        {
            return sum(node->next[INDEXOF(prefix[idx])], prefix, idx + 1);
        }
        else
        {
            return node->sum;
        }
    }
    Node *root;
};