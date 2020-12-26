#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法 1，最长公共前缀，定义两个变量i和j，然后开始查找
 * 首先i从0号字符串的第一个位置开始查找，然后遍历到这个字符串结束，之后j是每次遍历其他剩下的字符串
 * 如果当前的元素不相同或者是i号字符的下标大于其他串的长度，那么就直接返回res
 * 否则累加上当前字符的结果
*/
string longestCommonPrefix(vector<string> &strs)
{
    string res;                              // 记录结果的res
    for (int i = 0; i < strs[0].size(); i++) // 第一个字符串从头开始遍历
    {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); j++) // 开始遍历vector里面的其他子串
        {
            // 如果当前字符和其他子串的字符不相同或者是当前字符的下标大于等于其他字符长度不满足条件，直接返回
            if (strs[j][i] != strs[0][i] || i >= strs[j].size())
                return res;
        }
        res += c;
    }
    return res;
}

/**
 * 方法 2，闫总的这种写法很取巧，但是不容易想到
*/
string longestCommonPrefix(vector<string> &strs)
{
    string res;
    if (strs.empty())
        return res;

    for (int i = 0;; i++)
    {
        if (i >= strs[0].size())
            return res;
        char c = strs[0][i];
        for (auto &str : strs)
        {
            if (i >= str.size() || str[i] != c)
                return res;
        }
        res += c;
    }
    return res;
}

int main()
{
    vector<string> str = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(str) << endl;
}