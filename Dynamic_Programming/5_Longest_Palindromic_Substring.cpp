#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * Given a string s, find the longest palindromic substring in s.
 * You may assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
*/

/**
 * 方法 1,查找字符子串的最长回文串长度, 两层for循环来做.babad
*/
string longestPalindrome(string s)
{
    int len = s.size(), left = 0, right = len - 1;
    if (len == 1)
        return s;
    return s;
}
/**
 * 方法 2，动态规划
*/

string longestPalindrome2_1(string s)
{
    //最长的回文子串
    const int N = 1010;
    int ans = 0;
    string temp = "", res = "";
    vector<vector<int>> d(N, vector<int>(N, 0)); // res[i][j]表示a i-j之间是否是回文串
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        d[i][i] = 1;
        temp = s[i];
        if (i < n - 1)
        {
            if (s[i] == s[i + 1])
            {
                d[i][i + 1] = 1;
                ans = 2;
                temp = s.substr(i, 2);
                if (temp.size() > res.size())
                {
                    res = temp;
                    cout << res << endl;
                }
            }
        }
    }

    for (int L = 3; L <= n; L++) // 枚举子串的长度
    {
        for (int i = 0; i + L - 1 < n; i++)
        {
            int j = i + L - 1;
            if (s[i] == s[j] && d[i + 1][j - 1] == 1)
            {
                d[i][j] = 1;
                if (L > ans)
                {
                    temp = s.substr(i, L);
                }
                ans = L;
            }
        }
    }
    return res.size() > temp.size() ? res : temp;
}

/**
 * 方法 2，思路和上面一样，写法更加简单
 * dp[i][j] 表示区间i到j之间是否是回文串
*/
string longestPalindrome2_2(string s)
{
    if (s.empty())
        return "";
    int n = s.size();
    int dp[n][n] = {0}; // 初始化dp数组为0
    int left = 0, len = 1;
    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = 1; // 长度为1的字符是回文
        for (int j = 0; j < i; ++j)
        {
            // 如果s[i] == s[j] 并且 i和j相邻
            if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]))
            {
                dp[j][i] = 1;
            }
            if (dp[j][i] && len < i - j + 1) // 如果i和j区间的个数大于1不相邻的话且i和j是回文串，那么回文串长度是i-j+1
            {
                len = i - j + 1;
                left = j;
            }
        }
    }
    return s.substr(left, len);
}
/**
 * 方法 3，字符串哈希+二分
 * 
*/

/**
 * 方法 4，马拉车算法，最偏算法且只适合这个题目
*/

string longestPalindrome4(string s)
{
    string t = "$#";
    for (int i = 0; i < s.size(); ++i)
    {
        t += s[i];
        t += '#';
    }
    int p[t.size()] = {0}, id = 0, mx = 0, resId = 0, resMx = 0;
    for (int i = 1; i < t.size(); ++i)
    {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]])
            ++p[i];
        if (mx < i + p[i])
        {
            mx = i + p[i];
            id = i;
        }
        if (resMx < p[i])
        {
            resMx = p[i];
            resId = i;
        }
    }
    return s.substr((resId - resMx) / 2, resMx - 1);
}

int main()
{
    string s = "babad";
    cout << longestPalindrome(s) << endl;
}