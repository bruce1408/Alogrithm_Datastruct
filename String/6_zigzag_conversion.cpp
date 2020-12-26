#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 方法 1，直接把之字形的字符保存进去，推荐做法
 * 首先竖列的字母就是n行，遍历从0到n行， 
 * 然后再遍历之字形的中间行数是： 总行数 - 首行 - 尾行 =  n - 2； 最后合并即可
*/
string convert1(string s, int numRows)
{
    if (numRows <= 1)
        return s;
    string res;
    int i = 0, n = s.size();
    vector<string> vec(numRows);
    while (i < n)
    {
        for (int pos = 0; pos < numRows && i < n; ++pos)
            vec[pos] += s[i++];
        for (int pos = numRows - 2; pos >= 1 && i < n; --pos)
            vec[pos] += s[i++];
    }
    for (auto &a : vec)
        res += a;
    return res;
}

/**
 * 按照等差数列来做，每行是一个2n-2的等差数列，n表示行数。
*/
string convert2(string s, int n)
{
    if (n == 1)
        return s;
    // 规律就是2n-2 的等差数列
    string res;
    int step = 2 * n - 2;
    for (int i = 0; i < n; i++) // 遍历每行
    {
        if (i == 0 || i == n - 1) // 先处理第一行和最后一行
        {
            for (int j = i; j < s.size(); j += step)
                res += s[j];
        }
        else // 再处理中间几行
        {
            for (int j = i, k = 2 * n - 2 - i; j < s.size() || k < s.size(); j += step, k += step)
            {
                if (j < s.size())
                    res += s[j];
                if (k < s.size())
                    res += s[k];
            }
        }
    }
    return res;
}

int main()
{
    string s = "LEETCODEISHIRING";
    cout << convert1(s, 3) << endl;
}