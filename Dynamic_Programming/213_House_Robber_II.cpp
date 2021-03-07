#include <iostream>
#include <vector>
using namespace std;
/**
 * 213 打家劫舍II
 * Given a list of non-negative integers representing the amount of money of each house,
 * determine the maximum amount of money you can rob tonight without alerting the police.
 * Example 1:
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: 
 * Rob house 1 (money = 1) and then rob house 3 (money = 3). Total amount you can rob = 1 + 3 = 4.
 * 
 * 打家劫舍II，这里考虑环，给定一个数组，然后取数组中最大的数字之和，
 * 要求是相邻的数组不可以取值，比如，取1，就不能取2。例子中，取1，然后取3，
 * 中间不可以取相邻的数字
 * 
*/

/**
 * 方法 1，使用动态规划。一列数组中取出一个或多个不相邻数，使其和最大。
 * 那么对于这类求极值的问题首先考虑动态规划 Dynamic Programming 来解，
 * 维护一个一位数组 dp，其中 dp[i] 表示 [0, i] 区间可以抢夺的最大值，
 * 对当前i来说，有抢和不抢两种互斥的选择，不抢即为 dp[i-1]（等价于去掉 nums[i] 只抢 [0, i-1] 区间最大值），
 * 抢即为 dp[i-2] + nums[i]（等价于去掉 nums[i-1]）。再举一个简单的例子来说明一下吧，
 * 
 * 比如说 nums为{3, 2, 1, 5}，那么来看 dp 数组应该是什么样的，首先 dp[0]=3 没啥疑问，再看 dp[1] 是多少呢，
 * 由于3比2大，所以抢第一个房子的3，当前房子的2不抢，则dp[1]=3，那么再来看 dp[2]，由于不能抢相邻的，
 * 所以可以用再前面的一个的 dp 值加上当前的房间值，和当前房间的前面一个 dp 值比较，取较大值当做当前 dp 值，
 * 这样就可以得到状态转移方程 dp[i] = max(num[i] + dp[i - 2], dp[i - 1]), 且需要初始化 dp[0] 和 dp[1]，
 * 其中 dp[0] 即为 num[0]，dp[1] 此时应该为 max(num[0], num[1])，
*/
int rob2(vector<int> &nums)
{
    int n = nums.size();
    if (nums.empty())
        return 0;
    if (n <= 1)
        return nums.empty() ? 0 : nums[0];
    vector<int> f(n);
    f[0] = nums[0], f[1] = max(nums[1], nums[0]);
    for (int i = 2; i < nums.size()-1; ++i)
    {
        // 抢的话就是i-2再加上nums[i],如果不抢的话那么就是i-1
        f[i] = max(f[i-1], f[i-2] + nums[i]);
    }
    return f.back();
}

int main()
{
    vector<int> res = {2, 1, 1, 2};
    cout << rob2(res) << endl;
}