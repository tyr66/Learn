#include <iostream>
#include <cmath>
#include <map>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w" ,stdout);
    map<long long, int> sumMap;
    int K; cin >> K;getchar();

    while (K-- > 0)
    {
        string input;
        getline(cin, input);
        sumMap.clear();

        int depth = 0;
        long long weight = 0;
        int weight_cnt = 0;
        long long max_weight = 0;
        int max_weight_cnt = 0;

        for (int i = 0; i < input.size(); i++)
        {
            char c = input[i];
            if (c == '[') {
                depth++;
            } else if (c == ']') {
                depth--;
            } else if (isdigit(c)) {
                // get number
                weight = 0;
                while (isdigit(input[i]))
                {
                    weight = (input[i] - '0') + weight * 10; 
                    if (isdigit(input[i + 1])) 
                        i++;
                    else 
                        break;
                }

                long long total_weight = weight * pow(2, depth);
                sumMap[total_weight]++;
                weight_cnt++;
                // cout << "weight is :" << weight <<", total_weight is :" << total_weight << endl;

                if (max_weight_cnt < sumMap[total_weight]) {
                    max_weight_cnt = sumMap[total_weight];
                    max_weight = total_weight;
                }
            }
        }

        // cout << "weight_cnt :" << weight_cnt << " max_weight is :" << max_weight << " sumMap[ma_weight] is " << sumMap[max_weight] << endl; 
        cout << weight_cnt - sumMap[max_weight] << endl;

    }

    return 0;
}
