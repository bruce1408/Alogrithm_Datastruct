#include <iostream>
#include <vector>
using namespace std;

/**
 * 312 戳破气球
 * 给定一个数组，然后戳破气球，现在要求你戳破所有的气球。
 * 戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 
 * 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。
 * 如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球
*/

/**
 * 方法 1，使用动态规划来做
 * 状态表示f[i][j]表示的是从区间i+1到区间j-1之间的气球的所有方案
 * 不考虑i和j是因为最后一个气球的分数，用到左右边界考虑最后的时候需要边界值，
 * 状态划分：
 * 最后一个打气球的位置可以是i+1到j-1
 * 
*/
int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int> > f(n + 2, vector<int>(n + 2, 0));
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1; // 区间长度
            for (int k = i; k <= j; k++)
            {
                f[i][j] = max(f[i][j], nums[i - 1] * nums[j + 1] * nums[k] + f[i][k - 1] + f[k + 1][j]);
            }
        }
    }
    return f[1][n];
}
