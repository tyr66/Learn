#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*Manacher 算法 https://zhuanlan.zhihu.com/p/515049974
时间复杂度：O(n) 需要使用均摊分析的思维才能想明白为什么是n
空间复杂度：O(n)
*/

int countSubstrings(string s)
{
    int n = s.size();
    string t = "$#";
    for (const char &c : s)
    {
        t += c;
        t += '#';
    }
    n = t.size();
    t += '!';

    auto f = vector<int>(n);
    int iMax = 0, rMax = 0, ans = 0;
    for (int i = 1; i < n; ++i)
    {
        // 初始化 f[i]
        f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
        // 中心拓展
        while (t[i + f[i]] == t[i - f[i]])
            ++f[i];
        // 动态维护 iMax 和 rMax
        if (i + f[i] - 1 > rMax)
        {
            iMax = i;
            rMax = i + f[i] - 1;
        }
        // 统计答案, 当前贡献为 (f[i] - 1) / 2 上取整
        ans += (f[i] / 2);
    }

    return ans;
}


int main()
{
    return 0;
}