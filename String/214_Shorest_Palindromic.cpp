#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 214 最短回文串
 * 给定一个字符串，然后返回这个字符串的最短回文串，如果不是回文串，那么就在前面添加几个
 * 字符成为最短的回文串
 * 比如输入：s = "abc"
 * 返回结果："bcabc"
*/

/**
 * 方法 1，这个题目要求最短的回文串，思路非常巧妙
 * 就是如果是非回文串的话，那么前面添加最短的字符构成一个回文串
 * 比如： abc，前面添加bc可以构成，那么 原来的串对应去掉添加的这个字符也肯定是一个回文串
 * 所以把这个字符串翻转一下,翻转之后再求最长的前缀和后缀是回文串的字符
*/
string shortestPalindrome(string s)
{
    int n = s.size();
    string t(s.rbegin(), s.rend());
    s = ' ' + s + '#' + t;     // 下表从1开始的ne数组
    vector<int> ne(n * 2 + 2); // 不能初始化为-1
    for (int i = 2, j = 0; i <= n * 2 + 1; i++)
    {
        while (j && s[i] != s[j + 1])
            j = ne[j];
        if (s[i] == s[j + 1])
            j++;
        ne[i] = j;
    }
    int len = ne[2 * n + 1];                                            // 长度是len的字符串最长回文长度是ne[len]
    string left = s.substr(1, len), right = s.substr(len + 1, n - len); // 原串的左边、右边
    return string(right.rbegin(), right.rend()) + left + right;
}

int main()
{
    string a = "aacecaaa";
    cout << shortestPalindrome(a) << endl;
}