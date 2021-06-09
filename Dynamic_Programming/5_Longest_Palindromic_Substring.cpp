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
 * 方法 1,查找字符子串的最长回文串长度, 两层for循环来做, 肯定超时了
*/
class Solution
{
public:
    bool isPalidrome(string s)
    {
        if (s.size() == 0)
            return true;
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        if (s.empty())
            return s;
        string res;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                string temp = s.substr(i, j - i + 1);
                if (isPalidrome(temp) && temp.size() > ans)
                {
                    res = temp;
                    ans = temp.size();
                }
            }
        }
        return res;
    }
};

/**
 * 方法 2，双指针算法，每次找到这个字符串的中心点，然后左指针和右指针分别朝左右两个方向走，如果不同就停止，找到最大回文串。 
*/
string longestPalindrome2(string s)
{
    string res;
    for (int i = 0; i < s.size(); i++)
    {
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r])
            l--, r++;
        if (res.size() < r - l - 1)
            res = s.substr(l + 1, r - l - 1);

        l = i, r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r])
            l--, r++;
        if (res.size() < r - l - 1)
            res = s.substr(l + 1, r - l - 1);
    }
    return res;
}

/**
 * 方法 3，使用动态规划来做，思路和上面一样，写法更加简单，dp[i][j] 表示区间i到j之间是否是回文串
*/
string longestPalindrome2_2(string s)
{
    if (s.empty())
        return "";
    int n = s.size();
    vector<vector<int> > dp(n, vector<int>(n, 0)); // 初始化dp数组为0
    int left = 0, len = 1;
    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = 1; // 长度为1的字符是回文
        for (int j = 0; j < i; ++j)
        {
            // 如果s[i] == s[j] 并且 i和j相邻
            if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]))
                dp[j][i] = 1;

            // 如果i和j区间的个数大于1不相邻的话且i和j是回文串，那么回文串长度是i-j+1
            if (dp[j][i] && len < i - j + 1)
            {
                len = i - j + 1;
                left = j;
            }
        }
    }
    return s.substr(left, len);
}

/**
 * 方法 4，马拉车算法，偏门算法且只适合这个题目
*/
string longestPalindrome4(string s)
{
    string t = "$#";
    for (int i = 0; i < s.size(); ++i)
    {
        t += s[i];
        t += '#';
    }

    vector<int> p(t.size(), 0);
    int id = 0, mx = 0, resId = 0, resMx = 0;
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

// todo 字符串+哈希做法
int main()
{
    string s = "babad";
    Solution ss;
    cout << ss.longestPalindrome(s) << endl;
}