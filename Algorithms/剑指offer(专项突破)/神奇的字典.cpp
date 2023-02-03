#include <iostream>
#include <vector>
using namespace std;

#define MAX_CHILD_COUNT 26
#define INDEXOF(x) (x) - 'a'

struct Node
{
    Node *next[MAX_CHILD_COUNT];
    bool isWord;

    Node() : isWord(false)
    {
        memset(next, 0, sizeof(next));
    }
};

class MagicDictionary
{
public:
    /** Initialize your data structure here. */
    MagicDictionary()
    {
        root = new Node();
    }

    void buildDict(vector<string> dictionary)
    {

        for (auto &str : dictionary)
        {
            insert(root, str, 0);
        }
    }

    bool search(string searchWord)
    {
        return search(root, searchWord, 0, true);
    }

private:
    bool search(Node *node, const string &word, int idx, bool hasChance)
    {
        if (node == nullptr)
            return false;

        if (idx >= word.size())
            return node->isWord && !hasChance;

        bool res = search(node->next[INDEXOF(word[idx])], word, idx + 1, hasChance);

        if (hasChance && !res)
        {
            for (int i = 0; i < MAX_CHILD_COUNT; i++)
            {
                if (node->next[i] != nullptr && i != INDEXOF(word[idx]))
                    res |= search(node->next[i], word, idx + 1, false);
            }
        }

        return res;
    }
    void insert(Node *node, const string &word, int idx)
    {
        if (idx >= word.size())
        {
            node->isWord = true;
            return;
        }

        if (node->next[INDEXOF(word[idx])] == nullptr)
        {
            node->next[INDEXOF(word[idx])] = new Node();
        }

        insert(node->next[INDEXOF(word[idx])], word, idx + 1);
    }

private:
    Node *root;
};