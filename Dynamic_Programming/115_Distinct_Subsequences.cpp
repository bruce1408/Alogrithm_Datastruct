#include <iostream>
#include <vector>
using namespace std;

/**
 * 115 不同的序列
 * 给定字符s和t，计算s的子序列中t出现的次数
*/

/**
 * 方法 1，使用动态规划来做
 * f[i][j]表示s的1到i的所有子序列和t的[1-j]相等的子序列
*/

int numDistinct(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<vector<long long> > f(n + 1, vector<long long>(m + 1));

    for (int i = 0; i <= n; i++)
        f[i][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (s[i - 1] == t[j - 1])
                f[i][j] += f[i - 1][j - 1];
        }
    return f[n][m];
}
