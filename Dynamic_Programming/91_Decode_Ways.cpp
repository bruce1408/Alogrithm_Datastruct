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
 * 方法 2， 使用动态规划来做
 * 状态表示：dp[i]表示前i个字符组成的有效解码方法的个数
 * dp[0] = 1;
 * dp[i]最后可以划分最后一位数字要么是1位数字满足1-9，要么是两位数字满足11-26才可以
 * dp[i] = dp[i-1] + dp[i-2]
*/
int numDecodings(string s)
{
    int n = s.size();
    s = ' ' + s;
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // 如果1个数都没有的话那么就是空，就是1种方案
    for (int i = 1; i <= n; i++)
    {
        if (s[i] >= '1' && s[i] <= '9')
            dp[i] += dp[i - 1];
        if (i > 1)
        {
            // 判断两位数是不是在10-26之间
            int t = (s[i - 1] - '0') * 10 + s[i] - '0';
            if (t >= 10 && t <= 26)
                dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}

int main()
{
    string s = "1226";
    cout << numDecodings(s) << endl;
}