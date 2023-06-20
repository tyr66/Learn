#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct Node
{
  int val;
  Node* left{nullptr};
  Node* right{nullptr};
};

const int MAX = 10000 + 5;
int node_id = 0;
Node nodes[MAX];
bool is_failed = false;

Node* get_node(int val)
{
  nodes[node_id].val = val;
  return &nodes[node_id++];
}

void generate_order(string&str, vector<int>& res)
{
  stringstream ss;
  int val;
  ss << str;

  while (ss >> val) {
    res.push_back(val);
  }
}

Node* generate_tree(vector<int>&in_order, int in_left, int in_right, vector<int>&post_order, int post_idx)
{
  if (in_left > in_right || is_failed)
    return nullptr;

  int tar = -1;

  for (int i = in_left; i <= in_right; i++) {
    if (in_order[i] == post_order[post_idx]) {
      tar = i; break;
    }
  }

  if (tar == -1) {
    is_failed = true;
    //cout << "is failed" << endl;
    return nullptr;
  }

  // int left_cnt = tar - in_left ;
  int right_cnt = in_right - tar;

  Node* node = get_node(in_order[tar]);

  node->left = generate_tree(in_order, in_left, tar - 1, post_order, post_idx - right_cnt - 1);
  node->right = generate_tree(in_order, tar + 1, in_right, post_order, post_idx - 1);

  return node;
}

void find_min_leaf(Node* node, int sum, int& min_sum, int &res)
{
  if (node == nullptr)
    return;

  if (node->left == nullptr && node->right == nullptr) {
    res = sum + node->val < min_sum ? node->val : sum + node->val == min_sum ? min(res, node->val) : res;
    min_sum = min(sum + node->val, min_sum);
    return;
  }

  find_min_leaf(node->left, sum + node->val, min_sum, res);
  find_min_leaf(node->right, sum +node->val, min_sum, res);
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  string in_str, post_str;
  vector<int> in_order;
  vector<int> post_order;

  while (getline(cin, in_str) && getline(cin, post_str))
  {
    generate_order(in_str, in_order);
    generate_order(post_str, post_order);

    Node* root = generate_tree(in_order, 0, in_order.size() - 1, post_order, post_order.size() - 1);

    int min_sum = 0x7FFFFFFFU;
    int res = root->val;

    find_min_leaf(root, 0, min_sum, res);

    cout << res << endl;

    in_order.clear();
    post_order.clear();
    node_id = 0;
    is_failed = false;
  }

  return 0;
}
