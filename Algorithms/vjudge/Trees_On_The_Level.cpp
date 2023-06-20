#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;

struct Node {
  string val;
  Node* left{nullptr};
  Node* right{nullptr};
};

Node nodes[256];
int node_id = 0;
int nodes_cnt = 0;

Node* create_node(string&& val)
{
  Node* node = &nodes[node_id++];
  node->val = std::move(val);
  return node;
}

void print_tree(map<string, Node*>&treeMap, int cnt)
{
  if (treeMap.count("") == 0 || treeMap.size() != cnt)
  {
    cout << "not complete" << endl;
    //cout << "dont have root" << endl;
    return;
   }
  queue<string> tree_patterns; tree_patterns.push("");
  queue<Node*> res; 

  while (!tree_patterns.empty())
  {
    string pattern = tree_patterns.front();tree_patterns.pop();
    Node* node = treeMap[pattern];

    pattern += 'L';

    if (treeMap.count(pattern)) {
      node->left = treeMap[pattern];
      tree_patterns.push(pattern);
    }

    pattern.pop_back();pattern+='R';

    if (treeMap.count(pattern)) {
      node->right = treeMap[pattern];
      tree_patterns.push(pattern);
    }

    res.push(node);
  }

  if (res.size() != treeMap.size()) {
    cout << "not complete" << endl;
    // cout <<" res = " << res.size() << " treeMap = " << treeMap.size()<< endl;
    return;
  }

  while (!res.empty())
  {
    cout << res.front()->val ;
    if (res.size() != 1) cout << " ";
    res.pop();
  }

  cout << endl;
}

void reset_state(map<string, Node*>& tree)
{
  node_id = 0;
  tree.clear();
  nodes_cnt = 0;
}


int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  string str;
  map<string, Node*> treeMap;

  while (cin >> str)
  {
    if (str == "()") {
      print_tree(treeMap, nodes_cnt);
      reset_state(treeMap);
      continue;
    }
    
    int pos = str.find(',') + 1;
    string val = str.substr(1, pos - 2);
    string pattern = str.substr(pos, str.size() - pos - 1);
    Node* node = create_node(std::move(val));
    treeMap[pattern] = node;
    nodes_cnt++;

    // cout << node->id << " " << node->val << endl;

  }
  return 0;
}
