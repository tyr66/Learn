#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
#define MAX_CHILD_COUNT 26
#define INDEXOF(x) (x) - 'a'
#define INTTOCHAR(x) (x) + 'a'


/*思路：使用字典树
    时间复杂度：
        1. 建立字典树需要 O(d) 的时间复杂度, 其中d为所有前缀的字符数
        2. 查找前缀需要 O(w*m), 其中w为句子中的单词数量，m 为 字典树中最长前缀的字符数
        3. 因此最坏情况下时间复杂度为 O(d + w*m)
*/

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
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        insert(root, word, 0);
    }

    bool getPrefix(const string &word, string &res)
    {
        if (getPrefix(root, word, 0, res))
        {
            return true;
        }

        res.clear();

        return false;
    }

    ~Trie()
    {
        if (root != nullptr)
            destory(root);
    }

private:
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

    bool getPrefix(Node *node, const string &word, int idx, string &res)
    {
        if (node == nullptr)
            return false;

        if (node->isWord)
            return true;

        if (idx >= word.size())
            return false;

        res.push_back(word[idx]);

        return getPrefix(node->next[INDEXOF(word[idx])], word, idx + 1, res);
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

string replaceWords(vector<string> &dictionary, string sentence)
{
    Trie trie;
    string res;
    for (auto &prefix : dictionary)
    {
        trie.insert(prefix);
    }

    int startWordIdx = 0;
    string prefix;
    bool findStartChar = true;
    for (int i = 0; i < sentence.size(); i++)
    {

        if (!findStartChar && sentence[i] != ' ')
        {
            startWordIdx = i;
            findStartChar = true;
        }
        if ((i + 1 == sentence.size() || sentence[i + 1] == ' ') && findStartChar)
        {
            if (!res.empty())
                {
                    res.push_back(' ');
                }
            if (trie.getPrefix(sentence.substr(startWordIdx, i - startWordIdx), prefix))
            {
                res.append(prefix);
            }else {
                res.append(sentence.substr(startWordIdx, i - startWordIdx + 1));
            }
            findStartChar = false;
            prefix.clear();
            i++;
        }

    }

    return res;
}

int main()
{
    vector<string> prefixs = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the aattery";

    cout << replaceWords(prefixs, sentence);

    return 0;
}