#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 521 给定两个字符串，然后判断最长公共子序列是多少
 * Input: a = "aba", b = "cdc"
 * Output: 3
 * Explanation: One longest uncommon subsequence is "aba" because "aba" is a subsequence of "aba" but not "cdc".
 * Note that "cdc" is also a longest uncommon subsequence
*/

/**
 * 方法 1，两个字符串，如果长度不等，那么返回较长的那个，如果长度相同但是字符串不同，返回长度，否则返回-1；
*/
int findLUSlength(string a, string b)
{
    int n = a.size(), m = b.size();
    if (n != m)
        return n > m ? n : m;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                return n;
        }
        return -1;
    }
    return -1;
}
/**
 * 方法 2，两个字符串要是不等，那么就返回最长的那个，否则返回-1
*/
int findLUSlength(string a, string b)
{
    return a == b ? -1 : max(a.size(), b.size());
}

int main()
{
    string a = "aba", b = "cba";
    cout << findLUSlength(a, b);
}