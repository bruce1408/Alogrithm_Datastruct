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
 * 状态计算：选择f[i] 和不选择f[i] = f[i-1][j]
 * 选择f[i-1][j-1]
*/

int numDistinct(string s, string t)
{
    int n = s.size(), m = t.size();
    s = ' ' + s, t = ' ' + t;
    vector<vector<long long> > f(n + 1, vector<long long>(m + 1));

    // 如果原字符串不是空，但是子字符串是空的话，那么返回1，因为空串也是任意一个字符串的子串
    for (int i = 0; i <= n; i++)
        f[i][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            // 不选择s[i]
            f[i][j] = f[i - 1][j];
            // 选择s[i]
            if (s[i] == t[j])
                f[i][j] += f[i - 1][j - 1];
        }
    return f[n][m];
}
