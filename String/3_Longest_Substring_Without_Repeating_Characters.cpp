#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * 3. Longest Substring Without Repeating Characters
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 给一个字符串，输出的是没有重复的最长的子串的长度。
 * 输入：abcabcbb
 * 输出：3
*/

/**
 * 方法 1，双指针算法或者是滑动窗口算法都可以做
 * */
int lengthOfLongestSubstring1(string s)
{
    int m[256] = {0}, res = 0, left = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (m[s[i]] == 0 || m[s[i]] < left)
            res = max(res, i - left + 1);
        else
            left = m[s[i]];
        m[s[i]] = i + 1;
    }
    return res;
}

/**
 * 方法 2，和方法 1思路类似，使用两个指针，这里j和i指的是字符串区间，写法略有区别，推荐写法
 * 参考 845trie树
*/
int lengthOfLongestSubstring2(string s)
{
    int res = 0; // 不重复总长度
    // 设置一个哈希表来记录每个字符出现次数
    unordered_map<char, int> heap;
    // 从头开始遍历该字符,i表示不重复字符串结尾，j表示开头
    for (int i = 0, j = 0; i < s.size(); i++)
    {
        heap[s[i]]++;
        while (heap[s[j]] > 1)
        {
            heap[s[j]]--; // 回归到只出现一次
            j++;
        }
        res = max(res, i - j + 1);
    }
    return res;
}

/**
 * 方法 3，使用双指针，暴力做法，首先从i开始遍历，然后设置一个数组，保存每个字符出现的次数
 * 每次遍历当前字符串，然后从当前字符开始，只要之前没有出现过，那么就长度加1，而且当前出现的次数也加1
 * 如果当前出现过，那么设置长度为0，从头开始并且直接退出
 * 
*/
int lengthOfLongestSubstring3(string s)
{
    int n = s.size(), maxlen = 0;
    for (int i = 0; i < n; i++) // 每次遍历当前字符
    {
        int length = 0;   // 当前不重复的总长度是0
        int m[256] = {0}; // 初始化一个哈希数组，记录次数
        for (int j = i; j < n; j++)
        {
            if (m[s[j]] == 0) // 如果之前没有出现该字符
                length++;     // 不重复总长度+1
            else
            {
                length = 0; // 如果之前出现重复字符了，长度置0且直接退出当前循环
                break;
            }
            m[s[j]]++;
            maxlen = max(maxlen, length);
        }
    }
    return maxlen;
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring2(s) << endl;
    return 0;
}
