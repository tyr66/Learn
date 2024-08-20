#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = 64;
int graph[MAX_N][MAX_N];
const int WHITE = 0;
const int BLACK = 1;
vector<int> numbers;
int image_id = 1;

enum NODE_TYPE
{
    BLACK_NODE = 1,
    WHITE_NODE = 2,
    NORMAL_NODE = 4,
};

void print_numbers()
{
    sort(numbers.begin(), numbers.end());

    if (image_id != 1)
        cout << endl;

    cout << "Image " << image_id++;
    if (numbers.size() > 0)
        cout << endl;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (i % 12 == 0 && i != 0)
            cout << endl << numbers[i];
        else if (i == 0)
            cout << numbers[i];
        else 
         cout << " " << numbers[i];
    }
    cout << endl << "Total number of black nodes = " << numbers.size() << endl ;
}

void print_graph(int N)
{
    if (image_id != 1)
        cout << endl;
    cout << "Image " << image_id++ << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] == 1) {
                cout << '*';
            }
            else {
                cout << '.';
            }
        }
        cout << endl;
    }

}

NODE_TYPE is_white(int r, int c, int sz)
{
    int white_cnt = 0;
    for (int i = r ; i < r + sz; i++)
    {
        for (int j = c; j < c + sz; j++)
        {
            if (graph[i][j] == WHITE) white_cnt++;
        }
    }

    if (white_cnt == sz * sz)
        return WHITE_NODE;
    else if (white_cnt == 0)
        return BLACK_NODE;
    return NORMAL_NODE;
}

void build_spatial_tree(int r, int c, int sz, int number, int base)
{
    int node_id = 1;
    int half_sz = sz >> 1 == 0 ? 1 : sz >> 1;

    for (int _r = r; _r < r + sz; _r+= half_sz)
    {
        for (int _c = c; _c < c + sz; _c+= half_sz)
        {
            auto node_type= is_white(_r, _c, half_sz);
            if (node_type == BLACK_NODE) {
                numbers.push_back(number + base * node_id);
            } else if (node_type == NORMAL_NODE){
                build_spatial_tree(_r, _c, sz >> 1, number + base * node_id, base * 5);
            }
            node_id++;
        }
    }
}

void slove_map(int N)
{
    numbers.clear();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char c; cin >> c;
            graph[i][j] = c - '0';
        }
    }

    if (is_white(0, 0, N) == BLACK)
        numbers.push_back(0);
    else 
        build_spatial_tree(0, 0, N, 0, 1);
    print_numbers();
}

void draw_graph(int r,int c, int sz)
{
    for (int i = r; i < r + sz; i++)
    {
        for (int j = c; j < c + sz; j++)
        {
            graph[i][j] = BLACK;
        }
    }
}


void slove_number(int N)
{
    int number;
    int black_cnt = 0;

    memset(graph, 0, sizeof(graph));

    while (cin >> number && number != -1)
    {
        vector<int> arr;

        while (number != 0) {
            arr.push_back(number % 5);
            number = number / 5;
        }

        int r = 0, c = 0;
        int sz = N >> 1;
        for (int j = 0; j < arr.size(); j++) {

            switch(arr[j]) {
                case 1:break;
                case 2: c += (sz); break;
                case 3: r += (sz); break;
                case 4: r += (sz); c += (sz); break;
            }

            sz = sz >> 1;
        }

        sz = sz << 1;
        sz = sz == 0 ? 1 : sz;
        black_cnt += sz * sz;
        draw_graph(r, c, sz);
    }

    print_graph(N);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    while (cin >> N && N != 0)
    {
        if (N > 0) {
            slove_map(N);
        } else if (N < 0) {
            slove_number(-N);
        }
    }

    return 0;
}
