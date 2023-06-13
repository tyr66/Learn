#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

double mass[128];

int main()
{
    int N;
    string str;

    mass['C'] = 12.01;
    mass['H'] = 1.008;
    mass['O'] = 16.00;
    mass['N'] = 14.01;

    cin >> N;

    while (N-- > 0)
    {
        cin >> str;

        double sum = 0;
        int subscript = 0;
        char atomic = 0;

        for (char c : str)
        {
            if (isalpha(c)) {

                sum += subscript == 0 ? mass[atomic] : subscript * mass[atomic];
                atomic = c;
                subscript = 0;

            } else {
                subscript =  subscript * 10 + (c - '0');
            }
        }

        if (atomic != 0)
            sum += subscript == 0 ? mass[atomic] : subscript * mass[atomic];

        printf("%.3f\n", sum);
    }
    return 0;
}
