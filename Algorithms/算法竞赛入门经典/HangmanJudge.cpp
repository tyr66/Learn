#include <iostream>
#include <string>
#include <string.h>
using namespace std;

bool puzzleHash[128];
bool answerHash[128];

int main()
{
    string puzzle;
    string answer;
    int N;

    while (cin >> N && N != -1)
    {
        cin >> puzzle >> answer;

        int count = 0;

        memset(puzzleHash + 'a', 0, sizeof(bool) * 26);
        memset(answerHash + 'a', 0, sizeof(bool) * 26);

        for (int i = 0; i < puzzle.size(); i++)
        {
            if (!puzzleHash[puzzle[i]])
            {
                count++;
                puzzleHash[puzzle[i]] = true;
            }
        }

        for (int i = 0; i < answer.size(); i++)
        {
            answerHash[answer[i]] = true;
        }

        int success = 0, failed = 0;

        for (int i = 0; i < answer.size() && failed < 7 && success < count; i++)
        {
            if (!answerHash[answer[i]])
                continue;

            if (puzzleHash[answer[i]]) {

                //猜对
                puzzleHash[answer[i]] = false;
                answerHash[answer[i]] = false;
                success++;
            } else {

                // 猜错
                failed++;
            }
        }

        if (success == count)
            cout << "Round " << N << endl << "You win." << endl;
        else if (failed >= 7)
            cout << "Round " << N << endl << "You lose." << endl;
        else 
            cout << "Round " << N << endl << "You chickened out." << endl;

    }

    return 0;
}
