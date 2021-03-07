#include <iostream>
#include <vector>
using namespace std;

/**
 * 140 单词拆分2
 * 给定一个字符串和一个单词字典；
 * 输出所有的可能组成单词s的单词字典情况
*/

/**
 * 方法 1，使用深度优先搜索来做
 * 可以使用一个HashMap，来建立二者之间的映射，那么在递归函数中，
 * 我们首先检测当前s是否已经有映射，有的话直接返回即可，如果s为空了，我们如何处理呢，
 * 题目中说了给定的s不会为空，但是我们递归函数处理时s是会变空的，这时候我们是直接返回空集吗，
 * 这里有个小trick，我们其实放一个空字符串返回，为啥要这么做呢？我们观察题目中的Output，
 * 发现单词之间是有空格，而最后一个单词后面没有空格，所以这个空字符串就起到了标记当前单词是最后一个，
 * 那么我们就不要再加空格了。接着往下看，我们遍历wordDict数组，如果某个单词是s字符串中的开头单词的话，
 * 我们对后面部分调用递归函数，将结果保存到rem中，然后遍历里面的所有字符串，和当前的单词拼接起来，
 * 这里就用到了我们前面说的trick。for循环结束后，记得返回结果res之前建立其和s之间的映射
*/
vector<string> wordBreak(string s, vector<string> &word)
{
    unordered_map<string, vector<string> > m;
    return dfs(s, word, m);
}

vector<string> dfs(string s, vector<string> &word, unordered_map<string, vector<string> > &m)
{
    // 如果m中有映射的单词直接返回映射即可
    if (m.count(s))
        return m[s];
    // 如果s是空的话，那么返回空字符串
    if (s.empty())
        return {""};
    vector<string> res;
    // 遍历每个单词表中的单词，然后再递归找到剩余的单词的映射
    for (auto str : word)
    {
        if (s.substr(0, str.size()) != str)
            continue;
        // 剩余的单词映射是rem，然后遍历这个映射，和前面部分的单词组合起来即可
        vector<string> rem = dfs(s.substr(str.size()), word, m);
        for (auto str1 : rem)
        {
            res.push_back(str + (str1.empty() ? "" : " ") + str1);
        }
    }
    // 让这个s单词的映射为res
    return m[s] = res;
}
