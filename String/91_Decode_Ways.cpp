#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法 1，使用滑窗，分别对长度为1，和长度为2的长度进行累加他们的有效解码方式，但是这个题目做错了
 * 1226按照这个方法的解码方案是：
 * [1 2 2 6] [12 22 26] [1 22 26] [1 2 26]
*/
int numDecodings(string s)
{

    bool flag = false;
    int n = s.size();
    int res = 0, k = 0;

    for (int i = 0; i < n; i++)
    {
        int t = s[i] - '0';
        if (t >= 1 && t <= 26)
            flag = true;
        else
            flag = false;
        k = k * 10 + t;
    }
    for (int j = 0; j <= n - 2; j++)
    {
        string temp = s.substr(j, 2);
        int ans = (temp[0] - '0') * 10 + temp[1] - '0';

        if (ans > 0 && ans <= 26)
            res++;
        else
            break;
    }

    if (flag)
        res += 1;
    return res;
}

/**
 * 方法 2， 使用动态规划，dp[i]表示前i个字符组成的有效解码方法的个数
 * dp[0] = 1;
*/
int numDecodings2(string s)
{
    int res = 0;
    vector<int> dp(s.size() + 1, 0);
    if (s.empty() || s[0] == '0')
        return 0;
    for (int i = 1; i < s.size(); i++)
    {
        dp[i] = (s[i - 1] == '0') ?
    }
}
int main()
{
    string s = "1226";
    cout << numDecodings(s) << endl;
}