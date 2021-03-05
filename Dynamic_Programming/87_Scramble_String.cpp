#include <iostream>
#include <vector>
using namespace std;

/**
 * 87 扰乱字符串即可
 * 给定一个字符串然后用二叉树来表示，然后挑选一个叶子节点翻转，
 * 翻转之后组成新的字符串即可
 * 判断s1是不是干扰之后产生的字符串s2
*/

/**
 * 方法 1，使用递归来做
*/
bool isScramble(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    if (s1 == s2)
        return true;
    string bs1 = s1, bs2 = s2;
    sort(bs1.begin(), bs1.end()), sort(bs2.begin(), bs2.end());
    if (bs1 != bs2)
        return false;

    for (int i = 1; i <= n - 1; i++)
    {
        // s1的前i个字符和s2的前i个字符
        if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
            return true;
        // s1的前i个字符和s2的后i个字符来做
        if (isScramble(s1.substr(0, i), s2.substr(m - i)) && isScramble(s1.substr(i), s2.substr(0, m - i)))
            return true;
    }
    return false;
}
