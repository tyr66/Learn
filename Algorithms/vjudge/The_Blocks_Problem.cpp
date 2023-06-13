#include <iostream>
#include <string>
#include <vector>

using namespace std;


int N;
const char* end_of_cmd = "quit";

vector<int> arr[25];

void find_block(int n, int* block, int* idx)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == n)
            {
                *block = i;
                *idx = j;
                return;
            }
        }
    }
}

void printf_block()
{
    for (int i = 0; i < N; i++)
    {
        printf("%d:", i);

        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << " " << arr[i][j];
        }

        cout << endl;
    }
}


void move(int n_idx, int n, int tar)
{
    for (int i  = n; i < arr[n_idx].size(); i++)
    {
        arr[tar].push_back(arr[n_idx][i]);
    }

    arr[n_idx].resize(n);
}

void recover_block(int idx, int n)
{
    for (int i = n + 1; i < arr[idx].size(); i++)
    {
        int n = arr[idx][i];
        arr[n].push_back(n);

    }

    arr[idx].resize(n + 1);
}

void move_onto(int a_idx, int b_idx, int a, int b)
{
    recover_block(a_idx, a);
    recover_block(b_idx, b);

    move(a_idx, a, b_idx);
}

void move_over(int a_idx, int b_idx, int a, int b)
{
    recover_block(a_idx, a);

    move(a_idx, a, b_idx);
}

void pile_onto(int a_idx, int b_idx, int a, int b)
{
    recover_block(b_idx, b);

    move(a_idx, a, b_idx);
}

void pile_over(int a_idx, int b_idx, int a, int b)
{
    move(a_idx, a, b_idx);
}

int main()
{
    cin >> N;

    string s1,s2;
    int a, b;

    for (int i = 0; i < N; i++)
        arr[i].push_back(i);

    while (cin >> s1 && s1 != end_of_cmd)
    {
        cin >> a >> s2 >> b;

        int a_idx, an;
        int b_idx, bn;

        find_block(a, &a_idx, &an);
        find_block(b, &b_idx, &bn);

        if (a == b || a_idx == b_idx)
            continue;

        if (s1 == "move") {
            if (s2 == "onto") {
                move_onto(a_idx, b_idx, an, bn);
            } else {
                move_over(a_idx, b_idx, an, bn);
            }
        } else {
            if (s2 == "onto") {
                pile_onto(a_idx, b_idx, an, bn);
            } else {
                pile_over(a_idx, b_idx, an, bn);
            }
        }
    }

    printf_block();

    return 0;
}
