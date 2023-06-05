#include <iostream>
#include <set>
#include <string>
#include <sstream>
using namespace std;

int sequence[20];
stringstream ss;

int main()
{
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    while (T-- > 0)
    {
        int N;
        cin >> N;
        set<string> sequenceSet;
        string zero;

        for (int i = 0; i < N; i++)
        {
            cin >> sequence[i];
            ss << sequence[i] << ' ';
            zero += "0 ";
        }

        sequenceSet.insert(ss.str());

        while (zero != ss.str()) {

            ss.str("");

            for (int i = 0, fir = sequence[0]; i < N; i++) {

                if (i != N-1)
                    sequence[i] = abs(sequence[i] - sequence[i + 1]);
                else 
                    sequence[i] = abs(sequence[i] - fir);

                ss << sequence[i];
                ss << ' ';
            }

            if (sequenceSet.count(ss.str()))
                break;

            sequenceSet.insert(ss.str());
        }

        if (zero == ss.str()) {
            cout << "ZERO" << endl;
        } else {
            cout << "LOOP" << endl; 
        }
        
    }

    return 0;
}