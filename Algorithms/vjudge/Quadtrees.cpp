#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void count_black(string& tree, int& idx, int& cnt, int step, bool isset)
{

	if (idx >= tree.size()) {
		return;
	}

	if (tree[idx] != 'p') {
		cnt = isset && tree[idx] == 'f' ? cnt + step : cnt;
		idx++;
		return;
	}

	idx++;
	// 四叉树的结构确保了每一个p节点都必然有四个子节点
	for (int i = 0; i < 4; i++) {
		count_black(tree, idx, cnt, step / 4, isset);
	}

}

bool is_leaf(char c)
{
	return c == 'f' || c == 'e';
}

void merge_tree(string& s1, string& s2, int& idx1, int& idx2, int& cnt, int step)
{
	if (idx1 >= s1.size() || idx2 >= s2.size()) {
		return;
	}

	char c1, c2;
	c1 = s1[idx1]; c2 = s2[idx2];
	// s1 >> c1; s2 >> c2;

	//cout << c1 << " " << c2 <<" " <<  step << endl;

	if (c1 == c2 && c1 == 'p') {
		idx1++; idx2++;
		merge_tree(s1, s2, idx1, idx2, cnt, step / 4);
		merge_tree(s1, s2, idx1, idx2, cnt, step / 4);
		merge_tree(s1, s2, idx1, idx2, cnt, step / 4);
		merge_tree(s1, s2, idx1, idx2, cnt, step / 4);
	}
	else if (is_leaf(c1) && is_leaf(c2)) {
		cnt = c1 == 'f' || c2 == 'f' ? cnt + step : cnt;
		idx1++; idx2++;
	}
	else if (c1 == 'p') {
		cnt = c2 == 'f' ? cnt + step : cnt; idx2++;
		count_black(s1, idx1, cnt, step, c2 != 'f');
	}
	else if (c2 == 'p') {
		cnt = c1 == 'f' ? cnt + step : cnt; idx1++;
		count_black(s2, idx2, cnt, step, c1 != 'f');
	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string s1;
	string s2;
	int N;

	cin >> N;

	while (N-- > 0)
	{
		int cnt = 0;
		int idx1 = 0, idx2 = 0;
		int step = 1024;
		cin >> s1 >> s2;

		merge_tree(s1, s2, idx1, idx2, cnt, step);

		cout << "There are " << cnt << " black pixels." << endl;
	}

	return 0;
}
