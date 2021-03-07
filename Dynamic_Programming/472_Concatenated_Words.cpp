#include <isotream>
#include <vector>
using namespace std;

/**
 * 472 给定一个单词数组，然后里面的单词都不重复，然后输出这个单词中所有的连接词语即可
 * 连接词 的定义为：一个字符串完全是由至少两个给定数组中的单词组成的。
 * 输入：words = ["cat","dog","catdog"]
 * 输出：["catdog"]
*/

/**
 * 方法 1，和139-140题目类似
*/
vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
{
    unordered_set<string> res(words.begin(), words.end());
    vector<string> word;
    if (words.size() <= 2)
        return {};
    for (auto str : words)
    {
        res.erase(str);
        int len = str.size();
        if (len == 0)
            continue;
        vector<bool> v(len + 1, false);
        v[0] = true;
        for (int i = 0; i < len + 1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (v[j] && dict.count(word.substr(j, i - j)))
                {
                    v[i] = true;
                    break;
                }
            }
        }
        if (v.back())
            res.push_back(word);
        dict.insert(word);
    }
    return res;
}
