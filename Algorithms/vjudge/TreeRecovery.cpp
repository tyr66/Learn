#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


struct Node{
    Node* left{nullptr};
    Node* right{nullptr};
    char v;
};

const int MAX_N = 1000;
string preOrder, inOrder;
Node nodes[MAX_N];
int idx = 0;

Node* get_node(char c)
{
    Node* node = &(nodes[idx++]);
    node->v = c;
    return node;
}

Node* build_tree(int lo, int hi, int n)
{
    if (lo > hi) return nullptr;

    int i = lo;
    for (; i <= hi; i++) {
        if (inOrder[i] == preOrder[n]) break;
    }

    if (i > hi)
        throw std::runtime_error("wrong string");

    Node* res = get_node(preOrder[n]);
    res->left = build_tree(lo, i - 1, n + 1);
    res->right = build_tree(i + 1, hi, n + i - lo + 1);

    return res;
}

void print_backorder(Node* node)
{
    if (node == nullptr)
        return ;

    print_backorder(node->left);
    print_backorder(node->right);
    cout << node->v;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Node* tree = nullptr;

    while (cin >> preOrder >> inOrder)
    {
        tree = build_tree(0, inOrder.size() - 1, 0);
        print_backorder(tree);
        cout<<endl;
    }

    return 0;
}
