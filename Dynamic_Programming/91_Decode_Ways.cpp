#include <iostream>
#include <vector>
using namespace std;

/**
 * 91 解码字符方式
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。题目数据保证答案肯定是一个 32 位的整数。
 * 
 * 示例 1：
 * 输入：s = "12"
 * 输出：2
 * 解释：它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 示例 2：
 * 输入：s = "226"
 * 输出：3
 * 解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
*/

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