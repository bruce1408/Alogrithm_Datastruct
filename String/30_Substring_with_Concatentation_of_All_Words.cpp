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
vector<int> findSubstring1(string s, vector<string> &words)
{
    unordered_map<string, int> hash;
    vector<int> res;
    int n = s.size(), m = words.size();           // n是字符串长度，m是单词数量
    if (n == 0 || m == 0)                         // 如果字符串或者是数组为空，那么直接返回{};
        return res;                               // 字符串或者是字符串数组为空，那么返回空{}
    int len = words[0].size(), end = n - m * len; // 暴力枚举不用遍历完整个数组，只要到end即可，剩下的长度不足 m*len 就停止遍历，是个tricks
    if (n < m * len)                              // n 长度小于 m*word[0].size,返回{}
        return res;
    for (auto word : words) // hash表统计每个单词出现的次数
        hash[word]++;
    for (int i = 0; i <= end; i++)
    {
        unordered_map<string, int> cur_hash;
        int sa = 0;
        for (int j = i; j <= n - len; j += len) // 每次取长度为len的子串, 类似于一个滑窗，步长为1，窗口大小是len
        {
            string cur = s.substr(j, len);    // 找到长度是 len 的子串；
            if (hash.find(cur) == hash.end()) // 如果hash里面找不到，直接退出当前循环
                break;                        // 找不到这个单词直接退出
            else
            {
                cur_hash[cur]++;               // 如果找到了，直接cur_hash当前词语+1;
                if (cur_hash[cur] > hash[cur]) // 如果在cur_hash里面的单词数目大于hash出现的次数，那么直接退出
                    break;
                else if (cur_hash[cur] == hash[cur]) //如果cur_hash 里面的单词和hash里面的单词出现的次数一样的话，sa自加一次
                    sa++;                            // sa表示满足当前words出现1次且在s的子串中出现
                if (sa == hash.size())               // 最后，如果这sa长度等于hash长度，那么记录当前i，表示开始位置
                {
                    res.push_back(i);
                    break;
                }
            }
        }
    }
    return res;
}

/**
 * 方法 2，优化上面代码
*/
vector<int> findSubstring2(string s, vector<string> &words)
{
    vector<int> res;
    int n = s.size(), m = words.size();
    if (n == 0 || m == 0)
        return res;
    int len = words[0].size();
    unordered_map<string, int> hash; // hash表示每个单词出现的次数
    for (auto word : words)
        hash[word]++;

    for (int i = 0; i < len; i++) // 遍历每个单词的长度
    {
        int cnt = 0;
        unordered_map<string, int> cur_hash;
        for (int j = i; j <= n - len; j += len) // j是每一个单词的起始位置
        {
            if (j >= i + m * len) // 如果当前j超过了m个单词长度，那么减去长度跨度为len, 开头是m*len单词
            {
                auto word = s.substr(j - m * len, len);
                cur_hash[word]--;
                if (cur_hash[word] < hash[word]) // 如果cur_hash中word这个单词小于总数，说明当前单词有效，cnt--
                    cnt--;
            }
            auto word = s.substr(j, len);
            cur_hash[word]++;
            if (cur_hash[word] <= hash[word])
                cnt++;
            if (cnt == m)
                res.push_back(j - (m - 1) * len);
        }
    }
    return res;
}

int main()
{
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    for (auto i : findSubstring2(s, words))
    {
        cout << i << endl;
    }
}