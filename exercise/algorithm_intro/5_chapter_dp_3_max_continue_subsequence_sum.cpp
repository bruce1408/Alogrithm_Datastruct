#include <iostream>
#include <vector>
using namespace std;

/**
 * 给定一个数字序列
 * a1, a2, a3....an求i到j使得ai + ...aj最大，并输出这个最大和
 * -2, 11, -4, 13, -5, -2 最大和是 20
 * 用dp[i]表示i作为最大和最后的节点
 * dp[0] = -2;
 * dp[1] = 11;
 * dp[2] = 11-4 = 7;
 * ...
 * 
*/
const int N = 20;
int dp[N], maxnum = 0;
int main()
{
    vector<int> res = {-2, 11, -4, 13, -5, -2};
    dp[0] = -2;
    for (int i = 1; i < res.size(); i++)
    {
        dp[i] = max(dp[i - 1] + res[i], res[i]);
        maxnum = max(dp[i], maxnum);
    }
    cout << maxnum << endl;
}