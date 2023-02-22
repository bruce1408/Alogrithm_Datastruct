#include <iostream>
#include <string>
using namespace std;

/**
 * 最长回文子串
 * 给定一个字符串，然后返回这个最长回文串的长度
 * 输入：
 * patzjujztaccbcc
 * 输出：
 * atzjujzta
*/

/**
 * 方法 1，使用暴力搜索来做
 * 枚举端点i和j两个端点，然后判断i和j区间字符串是不是回文子串
 * 从复杂度上看，枚举端点属于O(n^2)，然后判断回文属于O(n),总的复杂度是O(n^3)
 * 
*/
bool pard(int i, int j, string a)
{
    while (i <= j)
    {
        if (a[i] == a[j])
        {
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}

void palindromic1()
{
    string a = "redivider";
    int n = a.size();
    string res;
    for (int i = 0; i < n; i++)
    {
        string temp;
        for (int j = i; j < n; j++)
        {
            if (pard(i, j, a))
            {
                temp = a.substr(i, j + 1);
                // cout << i << " " << j << " " << temp << endl;

                if (temp.size() > res.size())
                {
                    res = temp;
                }
            }
        }
    }
    cout << res << endl;
}

/**
 * 方法 2，使用动态规划来做
 * d[i][j]表示从s[i]到s[j]这个子串是否是回文串
 * 如果s[i]==s[j]: d[i][j] = d[i+1][j-1] 
 * 如果s[i]!-s[j]: 0
 * 边界是：d[i][i] = 1; dp[i][i+1] = s[i]==s[i+1] ? 1:0
*/
const int N = 200;
int d[N][N];
void palindromic2()
{
    string s = "redivider";
    int len = s.size(), ans = 1;
    // 边界问题
    for (int i = 0; i < len; i++)
    {
        d[i][i] = 1;
        if (i < len - 1)
        {
            if (s[i] == s[i + 1])
            {
                d[i][i + 1] = 1; // 从i到i+1是回文串，长度是2
                ans = 2;
            }
        }
    }

    // 状态转移方程
    for (int L = 3; L <= len; L++)
    {
        for (int i = 0; i + L - 1 < len; i++) // i表示左端点，i+L-1表示右端点
        {
            int j = i + L - 1; // 子串的右端点
            if (s[i] == s[j] && d[i + 1][j - 1] == 1)
            {
                d[i][j] = 1;
                ans = L;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    palindromic1(); // 方法 1
    palindromic2(); // 方法 2
}