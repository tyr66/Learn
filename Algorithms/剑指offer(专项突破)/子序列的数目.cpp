#include <iostream>
#include <vector>

using namespace std;

// 解法：动态规划
// 时间复杂度：O(nm), 空间复杂度 O(n)
class Solution {
public:
    int numDistinct(string s, string t) {

        vector<int> predp;
        vector<int> curdp;
        curdp.resize(t.size() + 1, 0);
        predp.resize(t.size() + 1, 0);
        curdp[0] = 1;
        predp[0] = 1;
        
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                curdp[j] = predp[j] + (t[j -1] == s[i - 1] ? predp[j - 1] : 0);
            }
            
            swap(curdp, predp);
        }
        
        return predp[t.size()];
    }
};
// 9223372036854775807 
// 5516694892996182896 
// 4472995859186094240 