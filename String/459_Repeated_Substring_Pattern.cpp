#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 459 重复子字符串
 * 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。
 * 给定的字符串只含有小写英文字母，并且长度不超过10000。
 * 示例 1:
 * 输入: "abab"
 * 输出: True
 * 解释: 可由子字符串 "ab" 重复两次构成
 * 其实就是求解字符串的周期  n - next[n]就是源字符串中的最小周期
*/

/**
 * 方法 1，可以使用kmp算法来做，具体就是构造一个next指针
*/
bool repeatedSubstringPattern(string s)
{
    int n = s.size();
    s = ' ' + s;
    vector<int> next(n + 1);
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && s[i] != s[j + 1])
            j = next[j];
        if (s[i] == s[j + 1])
            j++;
        next[i] = j;
    }
    int t = n - next[n];
    return t < n && n % t == 0;
}

int main()
{
    string s = "aba";
    cout << repeatedSubstringPattern(s) << endl;
    ;
}
