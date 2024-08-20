#include <iostream>
using namespace std;

void print_subset(int n, int *A, int cur)
{
    for (int i = 0; i < cur; i++) cout << A[i] << " ";
    cout << endl;

    int s = cur ? A[cur - 1] + 1 : 0;
    for (int i = s; i < n; i++)
    {
        A[cur] = i;
        print_subset(n, A, cur + 1);
    }
}

int main()
{
    int A[] = {1, 2, 3};

    print_subset(3, A, 0);

    return 0;
}
