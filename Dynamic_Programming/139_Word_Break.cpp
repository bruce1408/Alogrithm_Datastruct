#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * 139 单词拆分；
 * 给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 说明：
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 示例 1：
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"
*/

/**
 * 方法 1，拆分单词，然后在字典中逐个查找即可
 * 然后设置一个新的数组visited来保存这个i位置是不是可以进行拆分。
*/
bool check(string s, unordered_set<string> &wordSet, int start, vector<int> &memo)
{
    if (start >= s.size())
        return true;
    if (memo[start] != -1)
        return memo[start];
    for (int i = start + 1; i <= s.size(); ++i)
    {
        // 从start开始，i-start长度的单词和从i开始的单词进行判断
        if (wordSet.count(s.substr(start, i - start)) && check(s, wordSet, i, memo))
        {
            return memo[start] = 1;
        }
    }
    return memo[start] = 0;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<int> memo(s.size(), -1);
    return check(s, wordSet, 0, memo);
}

/**
 * 方法 2，使用动态规划来做
 * 状态表示：f[i]表示字符串s的0~i内子串是否拆分方案。因为空串也可以拆分，所以f[0] = true
 * 且f数组的长度要比s串的长度要大于1，就是因为空串的情况。
 * 状态划分：如果最后一个单词是否可以划分。设置k划分成两段，1~k-1 和 k-i
 * 1~k-1表示f[k-1]且后面是不是在字典中出现过，那么k-i是不是在字典中出现过的情况，
 * 如果用hash表来做的话，那么和字符长度成正比的，所以这里可以进行优化。
 * 一种是trie，或者是自己实现字符串哈希本质是字符串变成数字即可，或者是kmp。
 * 字符串哈希就是字符串看成n为的p进制数字即可；
 * p是13331，或者是131，q是2^64
*/
bool wordBreak(string s, vector<string> &w)
{
    typedef unsigned long long ULL;
    const int p = 131;
    unordered_set<ULL> hash;
    for (auto c : w)
    {
        ULL h = 0;
        for (int i = 0; i < c.size(); i++)
            h = h * p + c[i];
        hash.insert(h);
    }

    int n = s.size();
    vector<bool> f(n + 1);
    f[0] = true;
    s = ' ' + s;
    // 遍历前0~i开始
    for (int i = 0; i < n; i++)
    {
        // 如果f[i]是true，那么看后面那段k-i是不是存在
        if (f[i])
        {
            ULL h = 0;
            // 后面这段是不是存在进行判断，如果存在就是true
            for (int j = i + 1; j <= n; j++)
            {
                h = h * p + s[j];
                if (hash.count(h))
                    f[j] = true;
            }
        }
    }
    return f[n];
}