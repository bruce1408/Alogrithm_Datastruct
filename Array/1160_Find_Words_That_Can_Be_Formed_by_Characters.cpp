#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * You are given an array of strings words and a string
 * chars.A string is good if it can be formed by 
 * characters from chars (each character can only be 
 * used once).Return the sum of lengths of all good 
 * strings in words.
 * 
 * Example 1:
 * Input: words = ["cat","bt","hat","tree"], 
 * chars = "atach"
 * 
 * Output: 6
 * Explanation: 
 * The strings that can be formed are "cat" and 
 * "hat" so the answer is 3 + 3 = 6.
 * 
 * 
 * 这道题目就是给一个字符串数组words和一个字符串chars，
 * 看能不能通过字符串chars组成words里面的单词，如果可以的话，
 * 每个单词的长度加和返回即可。
 * 
*/

/**
 * 方法 1利用hashmap的思路，新建一个数组存放chars的字符次数
 * 遍历words中每个单词，如果这个单词每个字符在chars里面，那么
 * chars相应的字符减一，否则直接退出循环，最后判断word个数和i的
 * 个数是否相同，相同的话就直接加上该word的长度即可。
*/
int countCharacters(vector<string> &words, string chars)
{
    vector<int> res(26, 0);
    int count = 0;
    for (int i = 0; i < chars.size(); i++)
    {
        res[chars[i] - 'a']++;
    }

    for (auto word : words)
    {
        vector<int> temp(res.begin(), res.end());
        int i = 0;
        for (i = 0; i < word.size();)
        {
            if (temp[word[i] - 'a'] > 0)
            {
                temp[word[i] - 'a']--;
                i++;
            }
            else
                break;
        }
        if (i == word.size())
            count += word.size();
    }
    return count;
}

/**
 * 方法 2,和上面的方法一样，但是在84行非常简洁，可以替换方法 1
 * 50行到55行代码，主要利用运算符的优先级
*/
class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int count = 0;
        vector<int> res(26, 0);

        for (char &c : chars)
            res[c - 'a']++;

        for (auto &word : words)
        {
            vector<int> temp = res;
            bool match = true;
            for (char &c : word)
            {
                if (--temp[c - 'a'] < 0) // 先减后判断
                {
                    match = false;
                    break;
                }
            }

            if (match)
                count += word.length();
        }
        return count;
    }
};

int main()
{
    vector<string> res = {"cat", "bt", "hat", "tree"};
    string chars = "atach";
    // Solution s;

    // cout << s.countCharacters(res, chars) << endl;
    cout << countCharacters(res, chars) << endl;
}