#include <iostream>
#include <sstream>
using namespace std;

#define NUM(x) ((x) - '0')
const int MAX_N = 1000;
int indices[MAX_N];
int arr[MAX_N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    stringstream ss;
    string str, leaf, res, path;

    int N, cnt = 1; char c;
    while (cin >> N && N != 0)
    {
        getchar(); getline(cin, str); ss << str;

        for(int i = 1, idx; i <= N; i++) {
            ss >> c; ss >> idx;
            indices[idx] = i;
        }

        cin >> leaf;
        int M; cin >> M;

        for (int i = 1, j; i <= M; i++) {
            j = 1; cin  >> path;
            for(auto n : path) {
                arr[indices[j]] = NUM(n);
                j++;
            }

            int idx = 0, step = 1;
            for (int k = N; k > 0; k--) {
                idx += step * arr[k]; step = step << 1;
            }

            res.push_back(leaf[idx]);
        }

        cout << "S-Tree #" << cnt++ <<":" << endl;
        cout << res << endl << endl;

        res.clear(); ss.clear();leaf.clear(); path.clear();

    }


    return 0;
}
