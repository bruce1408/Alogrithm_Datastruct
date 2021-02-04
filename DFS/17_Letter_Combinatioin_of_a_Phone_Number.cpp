#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 17 电话号码组合
 * 给定一个数字字符串，然后输出代表的所有字符组合
 * 
 * 比如2是abc, 3是def; 23 就是abc 和 def 的两两组合结果如下
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
*/

/**
 * 方法 1，使用DFS深度优先遍历来做
*/
void letterStr(string digits, vector<string> &dict, int num, string s, vector<string> &res);
vector<string> letterCombinations(string digits)
{
    if (digits.empty())
        return {};
    vector<string> res;
    vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    letterStr(digits, dict, 0, "", res);
    return res;
}

void letterStr(string digits, vector<string> &dict, int num, string s, vector<string> &res)
{
    if (num == digits.size())
    {
        res.push_back(s);
        return;
    }
    string t = dict[digits[num] - '0']; // 'abc'
    for (int i = 0; i < t.size(); i++)
    {
        letterStr(digits, dict, num + 1, s + t[i], res);
    }
}

/**
 * 方法 2，使用迭代算法
*/
vector<string> letterCombinations2(string digits)
{
    vector<string> res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for (int i = 0; i < digits.size(); i++)
    {
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        for (int c = 0; c < chars.size(); c++)
            for (int j = 0; j < res.size(); j++)
            {
                string s = res[j] + chars[c];
                tempres.push_back(res[j] + chars[c]);
            }
        // tempres.push_back(res[j] + chars[c]);
        res = tempres;
    }
    return res;
}

int main()
{
    string digits = "2345";
    for (auto i : letterCombinations2(digits))
    {
        cout << i << " ";
    }
    cout << endl;
}