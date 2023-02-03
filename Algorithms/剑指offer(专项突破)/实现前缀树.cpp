#include <iostream>
#include <vector>
using namespace std;

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
    /** Initialize your data structure here. */
    Trie() : root(nullptr)
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        if (root == nullptr)
        {
            root = new Node();
        }

        insert(root, word, 0);
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        return search(root, word, 0);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return startWith(root, prefix, 0);
    }

    ~Trie()
    {
        destory(root);
    }

private:
    bool search(Node *node, const string &word, int idx)
    {

        if (node == nullptr)
        {
            return false;
        }

        if (idx >= word.size())
        {
            return node->isWord;
        }

        return search(node->next[INDEXOF(word[idx])], word, idx + 1);
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

    bool startWith(Node *node, const string &word, int idx)
    {
        if (node == nullptr)
            return false;

        if (idx >= word.size())
            return true;

        return startWith(node->next[INDEXOF(word[idx])], word, idx + 1);
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

int main()
{

    return 0;
}