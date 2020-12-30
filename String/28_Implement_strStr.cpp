#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * 28 实现strStr()函数
 * 给定两个字符串，s和p，然后返回第一次匹配到p字符串的位置下标
 * s = hello, b = ll
 * return 2；
 */

/**
 * 方法 1，使用双指针，简化之后就是方法 2的写法
 * */
int strStr1(string s, string p)
{
    if (p.empty())
        return 0;
    int n = s.size(), m = p.size();
    if (m > n)
        return -1;
    /*
        for(int i=0;i<n;i++) // 原来的话是遍历整个n长度的字符串，但是现在我不是遍历那么长的
        我只要遍历 n-m + 1长度的即可，遍历到剩下的长度和子字符串相等的位置即可,因为可以提高运算效率.
    */
    for (int i = 0; i < n - m + 1; i++) // 这个是唯一我改的地方 就是i的取值范围
    {
        int j = i;
        int k = 0;
        while (s[j] == p[k] && k < m)
        {
            j++;
            k++;
        }
        if (k == p.size())
            return i;
    }
    return -1;
}

/**
 * 方法 2，优化算法，时间4ms, 推荐算法
 * 设两个字符串的长度分别是 n 和 m, n表示s文本串的长度，m表示匹配串的长度
 * 然后第一个指针从0开始到n-m+1遍历，因为只要遍历到剩下的字符长度大于第二个字符串长度位置
 * 即可，然后第二个指针j从0开始到m，如果两个指针指向的字符不相同就直接退出，否则，第一个字符起始位置是从i+j开始，增量指针用法。
*/
int strStr2(string s, string p)
{
    if (p.empty())
        return 0;
    int n = s.size(), m = p.size(); // 文本串和匹配串的长度
    if (n < m)                      // 如果匹配串长度大于文本串，直接返回-1
        return -1;
    for (int i = 0; i < n - m + 1; ++i) // i <= n-m
    {
        int j = 0; // j从0开始，i+j开始遍历
        for (j = 0; j < m; ++j)
        {
            if (s[i + j] != p[j]) // 如果当前不等，直接退出当前循环
                break;
        }
        if (j == m)
            return i;
    }
    return -1;
}

/**
 * 方法 3，kmp算法
*/

int main()
{
    cout << strStr2("hello", "ll") << endl;
    return 0;
}