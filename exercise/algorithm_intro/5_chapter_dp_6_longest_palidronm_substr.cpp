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
 * d[i][j]表示从s[i]到s[j] 是否是回文串
 * 如果s[i]==s[j]: d[i][j] = 
*/
void palindromic2()
{
    string s = "abcba";

}

int main()
{
    palindromic1();
    // string a = "redivider";
    // cout << a.size() << endl;
    // cout << a.substr(0, 3) << endl;
}