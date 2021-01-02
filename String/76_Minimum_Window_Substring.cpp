#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/**
 * 76_最小窗口子串
 * 给定一个字符串a和b，然后看a中是否含有构成b的子串，且子串长度最小，那么就输出这个子串
 * 比如
 * 输入: a = "ADOBECODEBANC", b = "ABC"
 * 输出: "BANC"
*/

/**
 * 方法 1，超时了，使用滑动窗口+哈希来做，比较暴力，窗口的最小长度是b字符串的长度~a串的长度，如果满足条件就返回最小串的长度
 * 这里使用哈希来判断窗口子串和b字符串是否相同，如果不相同就返回false，相同就直接返回当前窗口的子串
 * */
bool compare(string a, string b)
{
    unordered_map<char, int> hash;
    for (auto str : a)
        hash[str]++;
    for (auto str : b)
    {
        if (--hash[str] < 0)
            return false;
    }
    return true;
}

string minWindow1(string s, string t)
{
    int n = s.size(), m = t.size();
    string res;
    if (n < m) // 如果文本串s大于匹配串t，那么就直接返回空串即可
        return res;
    for (int i = m; i <= n; i++) // 设置为滑窗的长度，从m-n
    {
        for (int j = 0; j <= n - m; j++) // 滑窗步长为1，最大到n-m
        {
            string temp = s.substr(j, i); // 如果滑窗子串和b串相同，那么就返回当前滑窗子串
            if (compare(temp, t))
                return temp;
        }
    }
    return res;
}

/**
 * 方法 2，使用滑窗+哈希，两个指针扫描整个字符串，哈希来统计字符出现的次数
*/
string minWindow2(string s, string t)
{
    unordered_map<char, int> hs, ht; // 设置两个哈希表，一个存放s串，一个存放t串的次数
    for (auto i : t)                 // 统计每一个t字符出现的次数
        ht[i]++;
    string res;
    int cnt = 0;                              // 设置cnt用来记录是否匹配到
    for (int i = 0, j = 0; i < s.size(); i++) // 设置两个指针，i和j，j指向起始位置，i是结束位置
    {
        hs[s[i]]++;               // s当前字符的个数
        if (hs[s[i]] <= ht[s[i]]) // 如果s当前字符小于等于t当前字符，那么cnt加1，是有效的字符
            cnt++;

        while (hs[s[j]] > ht[s[j]]) // 如果起始位置j在s的位置次数大于t的次数，那么j向后移动
        {
            hs[s[j]]--; // 次数减一
            j++;
        }
        if (cnt == t.size()) // cnt如果和t串长度相同，那么保存当前s中的位置
        {
            if (res.empty() || i - j + 1 < res.size()) // s串有效字符的长度是i-j+1
                res = s.substr(j, i - j + 1);
        }
    }
    return res;
}

/**
 * 方法 3，思路一样，就是空间上不用哈希，该用数组来降低空间消耗,更加高效
*/
string minWindow3(string s, string t)
{
    vector<int> letterCnt(128, 0);
    int j = 0, cnt = 0, minLeft = -1, minLen = INT_MAX;
    for (char c : t)
        ++letterCnt[c];
    for (int i = 0; i < s.size(); ++i)
    {
        if (--letterCnt[s[i]] >= 0)
            ++cnt;
        while (cnt == t.size())
        {
            if (minLen > i - j + 1)
            {
                minLen = i - j + 1;
                minLeft = j;
            }
            if (++letterCnt[s[j]] > 0)
                --cnt;
            ++j;
        }
    }
    return minLeft == -1 ? "" : s.substr(minLeft, minLen);
}

int main()
{
    string a = "ADOBECODEBANC", b = "ABC";
    cout << minWindow2(a, b) << endl;
    // cout << compare(a, b) << endl;
}