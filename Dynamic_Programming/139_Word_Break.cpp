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
*/
bool check(string s, unordered_set<string> &wordSet, int start, vector<int> &memo)
{
    if (start >= s.size())
        return true;
    if (memo[start] != -1)
        return memo[start];
    for (int i = start + 1; i <= s.size(); ++i)
    {
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
 * 状态表示：f[i]表示字符串s的0~i内地子串是否可以拆分。因为空串也可以拆分，所以f[0] = true
 * 且f数组的长度要比s串的长度要大于1，就是因为空串的情况。
 * 状态划分：
*/