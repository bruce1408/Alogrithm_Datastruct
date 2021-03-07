#include <iostream>
#include <vector>
using namespace std;
/**
 * 213 打家劫舍II
 * 打家劫舍II，这里考虑环，给定一个数组，然后取数组中最大的数字之和，
 * 要求是相邻的数组不可以取值，比如，取1，就不能取2。例子中，取1，然后取3，
 * 中间不可以取相邻的数字，且考虑首位环的情况
*/

/**
 * 方法 1，使用动态规划。一列数组中取出一个或多个不相邻数，使其和最大。
 * 那么对于这类求极值的问题首先考虑动态规划 Dynamic Programming 来解，
 * 维护一个一位数组 dp，其中 dp[i] 表示 [0, i] 区间可以抢夺的最大值，
 * 对当前i来说，有抢和不抢两种互斥的选择，不抢即为 dp[i-1]（等价于去掉 nums[i] 只抢 [0, i-1] 区间最大值），
 * 现在房子排成了一个圆圈，则如果抢了第一家，就不能抢最后一家，因为首尾相连了，
 * 所以第一家和最后一家只能抢其中的一家，或者都不抢，那这里变通一下，
 * 如果把第一家和最后一家分别去掉，各算一遍能抢的最大值，
 * 然后比较两个值取其中较大的一个即为所求
*/
int robcheck(vector<int> &nums, int start, int n)
{
    if (n - start <= 1)
        return nums[start];
    vector<int> f(n);
    f[start] = nums[start], f[start + 1] = max(nums[start], nums[start + 1]);
    for (int i = start + 2; i < n; i++)
    {
        f[i] = max(f[i - 1], f[i - 2] + nums[i]);
    }
    return f.back(); // 或者用f[n-1]代替都可以
}

int rob(vector<int> &nums)
{
    if (nums.size() <= 1)
        return nums.empty() ? 0 : nums[0];
    return max(robcheck(nums, 0, nums.size() - 1), robcheck(nums, 1, nums.size()));
}

int main()
{
    vector<int> res = {2, 1, 1, 2};
    cout << rob(res) << endl;
}