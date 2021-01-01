#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 30 串联所有单词的子串
 * 给定一个字符串a，然后和一个字符串数组b，b里面所有的组合是否是a的一个子串
 * 返回是子串的起始位置即可
 * 
 * s = "barfoothefoobarman",
 * words = ["foo","bar"]
 * Output: [0,9]
 * 
*/

/**
 * 方法 1，暴力解法
*/

vector<int> findSubstring(string s, vector<string> &words)
{
    unordered_map<string, int> hash;
    vector<int> res;
    int n = s.size(), m = words.size();
    if (n == 0 || m == 0)
        return res;                               // 字符串或者是字符串数组为空，那么返回空{}
    int len = words[0].size(), end = n - m * len; // 暴力枚举不用遍历完整个数组，只要到end即可，剩下的长度不足 m*len 就停止遍历，是个tricks
    if (n < m * len)
        return res;
    for (auto word : words)
        hash[word]++; // hash表统计每个单词出现的次数
    for (int i = 0; i <= end; i++)
    {
        unordered_map<string, int> cur_hash;
        int sa = 0;
        for (int j = i; j <= n - len; j += len) // 每次取长度为n的子串
        {
            string cur = s.substr(j, len); // 类似于一个滑窗，步长为1，窗口大小是len
            if (hash.find(cur) == hash.end())
                break; // 找不到这个单词
            else
            {
                cur_hash[cur]++;
                if (cur_hash[cur] > hash[cur])
                    break;
                else if (cur_hash[cur] == hash[cur])
                    sa++;
                if (sa == hash.size())
                {
                    res.push_back(i);
                    break;
                }
            }
        }
    }
    return res;
}

int main()
{
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    for (auto i : findSubstring(s, words))
    {
        cout << i << endl;
    }
}