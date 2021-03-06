#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法 1，拆分单词，然后在字典中逐个查找即可
*/
bool dfs(string s, unordered_set<string> &wordSet, int start, vector<int> &memo)
{
    if (start >= s.size())
        return true;
    if (memo[start] != -1)
        return memo[start];
    for (int i = start + 1; i <= s.size(); ++i)
    {
        if (wordSet.count(s.substr(start, i - start)) && dfs(s, wordSet, i, memo))
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
    return dfs(s, wordSet, 0, memo);
}
