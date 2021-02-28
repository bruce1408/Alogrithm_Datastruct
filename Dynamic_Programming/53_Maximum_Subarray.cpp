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
            tempSum += nums[j];
            maxSum = max(maxSum, tempSum);
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
int helper(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return nums[left];
    int mid = left + (right - left) / 2;
    int leftMax = helper(nums, left, mid - 1);
    int rightMax = helper(nums, mid + 1, right);
    int midMax = nums[mid], t = midMax;
    for (int i = mid - 1; i >= left; i--)
    {
        t += nums[i];
        midMax = max(midMax, t);
    }
    t = midMax;
    for (int i = mid + 1; i <= right; i++)
    {
        t += nums[i];
        midMax = max(midMax, t);
    }
    return max(midMax, max(leftMax, rightMax));
}

int maxSubArray3(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    return helper(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {-1};
    cout << maxSubArray3(nums) << endl;
    cout << maxSubArray_(nums) << endl;

    return 0;
}