#include <iostream>
#include <unordered_map>
using namespace std;


int main()
{
    int a, b;

    while (cin >> a && cin >> b)
    {
  
        printf("%d/%d = ", a, b);

        do{
            cout << a / b;
            a = a >= b ? a % b : a;
        }while(a >= b);

        int n = a;
        int count = 1;
        unordered_map<int, int> records;

        while (n != 0) {

            if (records[n] != 0)
                break;

            records[n] = count++;

            n = n * 10;
            if (n >= b) n = n % b;
        }

        int length = n == 0 ? 1 : count - records[n];
        int pos = n == 0 ? count : records[n];
        count = 1;
        n = a;

        if (pos + length - 1 <= 50) {

            cout << ".";
            while (count < pos + length)
            {
                if (count++ == pos) cout << '(';
                n = n * 10;
                cout << n / b;
                if (n >= b) n = n % b;
            }
            cout << ')' << endl;

        } else {
            cout << ".";
            while (count <= 50)
            {
                if (count++ == pos) cout <<'(';
                n = n * 10;
                cout << n / b;
                if (n >= b) n = n % b;
            }
            cout << "...)" << endl;
        }

        printf("   %d = number of digits in repeating cycle\n\n", length);

    }

    return 0;
}
