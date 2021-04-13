#include <iostream>
#include <vector>
using namespace std;

/**
 * 53, 最大子序列和
 * Given an integer array nums, 
 * find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 * 
 * Example:
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 求数组中的子数组的最大和
 * 利用kadane 算法
*/

/**
 * 刚开始是想使用滑窗来做，每次改变窗口的大小，然后设置变量ans保存结果，
 * 计算窗口内的元素和，然后只要大于ans就不断更新
 * 但是时间复杂度很高，超时了
*/
int maxSubArray_(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int n = nums.size(), ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            int res = 0;
            for (int k = j; k < i + j; k++)
            {
                res += nums[k];
            }
            ans = max(res, ans);
        }
    }
    return ans;
}

/**
 * 方法 1，给定一个数组，求出数组中元素相加的和是最大的那个连续子数组
 * 利用brute-force 两重for循环来做即可，时间复杂度O(n^2);
*/
int maxSubArray1(vector<int> &nums)
{
    int n = nums.size(), maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int tempSum = 0;
        for (int j = i; j < n; j++)
        {
            // tempSum += nums[j];
            maxSum = max(maxSum, tempSum + nums[j]);
        }
    }
    return maxSum;
}

/**
 * 方法 2, 动态规划来做 kadane's algorithm 求子序列最大值问题，
 * 设置当前最大值和全局最大值的初始值都是第一个元素，
 * 遍历数组，每次找到最大的：
 * 当前最大值 = max(nums[i],当前最大值 + nums[i])，
 * 最后保留最大的给global_sum
 * https://afshinm.name/2018/06/24/why-kadane-algorithm-works/
 * */
int maxSubArray2(vector<int> &nums)
{

    int global_sum = nums[0], current_sum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        current_sum = max(nums[i], current_sum + nums[i]);
        if (current_sum > global_sum)
            global_sum = current_sum;
    }
    return global_sum;
}

/**
 * 方法 3，分治法来求解，二分搜索，
 * 需要把数组一分为二，分别找出左边和右边的最大子数组之和，然后还要从中间开始向左右分别扫描，
 * 求出的最大值分别和左右两边得出的最大值相比较取最大的那一个
 * */
int dfs(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return nums[left];
    // 找到区间中点
    int mid = (left + right) >> 1;

    // 找到左区间的最大字段和
    int lmax = dfs(nums, left, mid - 1);

    // 找到右区间的最大字段和
    int rmax = dfs(nums, mid + 1, right);

    // 设置当前区间的中点
    int midMax = nums[mid], t = midMax;

    // 然后开始从右往左累加左半部分的
    for (int i = mid - 1; i >= left; i--)
    {
        t += nums[i];
        midMax = max(t, midMax);
    }

    // 从左往右累加右边的区间
    t = midMax;
    for (int i = mid + 1; i <= right; i++)
    {
        t += nums[i];
        midMax = max(t, midMax);
    }

    // 比较中间区间和左右两个子区间的最大字段和到底是多少
    return max(midMax, max(lmax, rmax));
}

int maxSubArray3(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    // 分治的思路
    return dfs(nums, 0, nums.size() - 1);
}

/**
 * 方法 4，使用dp动态规划这个算法，推荐做法
 * 1.设 f(i) 表示以第i个数字为结尾的最大连续子序列的总和是多少。
 * 2.初始化 f(0)=nums[0]f(0)=nums[0]。
 * 3.转移方程 f(i)=max(f(i−1)+nums[i], nums[i]); 
 * f(i)=max(f(i−1)+nums[i],nums[i])。可以理解为当前有两种决策，一种是将第i个数字和前边的数字拼接起来；
 * 另一种是第i个数字单独作为一个新的子序列的开始。
 * 4.最终答案为 ans=max(f(k)), 0≤k<nans=max(f(k)), 0≤k<n 。
*/
int maxSubArray4(vector<int> &nums)
{
    int n = nums.size();
    vector<int> f(n);
    f[0] = nums[0];
    int maxNum = nums[0];
    for (int i = 1; i < n; i++)
    {
        f[i] = max(f[i - 1] + nums[i], nums[i]);
        maxNum = max(f[i], maxNum);
    }
    return maxNum;
}

/**
 * 方法 4的优化,使用滚动数组来做，不用开额外的数组，时间O(n)，空间O(1)
 * 使用线段树来扩展，动态的求解某个区间内的最大字段和:acm245
 * */
int maxSubArray5(vector<int> &nums)
{
    if (nums.empty())
        return -1;
    int last = nums[0];
    int res = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        last = nums[i] + max(last, 0);
        res = max(last, res);
    }
    return res;
}

vector<int> maxSum(vector<int> &nums)
{
    if (nums.empty())
        return {};
    int res = nums[0], n = nums.size();
    int l = 0, r = n - 1;
    vector<int> f(n);
    f[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (f[i - 1] + nums[i] < nums[i])
            l = i;
        f[i] = max(f[i - 1] + nums[i], nums[i]);
        if (res < f[i])
            r = i;
        res = max(res, f[i]);
    }
    cout << l << " " << r << endl;
    return vector<int>(nums.begin() + l, nums.begin() + (r + 1));
}

int main()
{
    vector<int> nums = {0, 0, 0, 0, 0};
    // cout << maxSubArray3(nums) << endl;
    cout << maxSubArray5(nums) << endl;

    for (auto x : maxSum(nums))
    {
        cout << x << " ";
    }
    return 0;
}
