#include <iostream>
#include <vector>
using namespace std;

/**
 * 377 给定一个数组，和一个target，然后找出这个数组的所有满足条件的组合 
*/

/**
 * 方法 1，使用动态规划来做
 * f[i]表示目标为i的解的个数
 * 状态表示，当前数字可以用f[i] 和 f[i-x]表示，x不能大于i即可
*/
int combinationSum4(vector<int> &nums, int target)
{
    const int mod = INT_MAX;
    vector<long long> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= target; ++i)
    {
        for (auto a : nums)
        {
            if (i >= a)
                dp[i] = (dp[i] + dp[i - a]) % mod;
        }
    }
    return dp.back();
}