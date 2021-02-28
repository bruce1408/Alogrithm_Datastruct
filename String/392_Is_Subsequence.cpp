#include <iostream>
using namespace std;

/**
 * 392 求两个字符串的是否是另一个的子序列
*/

/**
 * 方法 1，使用双指针算法来做
*/
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        // 判断最长公共子序列
        if (s.size() > t.size())
            return false;
        int index1 = 0, index2 = 0;
        while (index2 < t.size())
        {
            if (s[index1] == t[index2])
            {
                index1++;
                index2++;
            }
            else
                index2++;
        }
        return index1 == s.size();
    }
};

/**
 * 方法 2，使用双指针算法来做,写法更加简洁
*/
bool isSubsequence(string s, string t)
{
    int k = 0;
    for (auto c : t)
    {
        if (s[k] == c)
            k++;
    }
    return k == s.size();
}

int main()
{
    string s = "abcf", t = "dfghdfsa";
    Solution ss;
    cout << ss.isSubsequence(s, t) << endl;
}