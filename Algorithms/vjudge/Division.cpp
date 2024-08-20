#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 10;
int number[MAX_N];
bool has_select[MAX_N];
int N;
bool has_solution = false;

bool is_ok()
{
    int denominator = 0;
    bool selected[MAX_N];
    memset(selected, 0, sizeof(selected));

    for (int i = 0; i < 5; i++) {
        denominator = denominator * 10 + number[i];
        selected[number[i]] = true;
    }

    int numerator = denominator * N;
    int cnt = 5;

    while (numerator != 0) {
        if (selected[numerator % 10])
            return false;
        selected[numerator % 10] = true;
        numerator = numerator / 10;
        cnt--;
    }

    if (cnt > 1 || (cnt == 1 && selected[0]))
        return false;

    if (denominator * N < 10000)
        cout << 0 ;
    cout << denominator * N << " / ";
    for (int i = 0; i < 5; i++)
        cout << number[i];
    cout << " = " << N << endl;

    return true;
}

void slove(int d, int k)
{
    if (d == 5) {
        if (is_ok()) {
            has_solution = true;
        }
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if (!has_select[i]) {
            has_select[i] = true;
            number[k] = i;
            slove(d + 1, k + 1);
            has_select[i] = false;
        }

    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int cnt = 0;

    while (cin >> N && N != 0)
    {
        if (cnt != 0)
            cout << endl;
        has_solution = false;
        for (int i = 0; i < 10; i++)
            number[i] = i;
        slove(0, 0);

        if (!has_solution)
            printf("There are no solutions for %d.\n", N);
        cnt++;
    }
    return 0;
}
