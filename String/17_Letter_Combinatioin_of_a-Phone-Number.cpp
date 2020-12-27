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

int main()
{
    string digits = "2345";
    for (auto i : letterCombinations(digits))
    {
        cout << i << " ";
    }
    cout << endl;
}