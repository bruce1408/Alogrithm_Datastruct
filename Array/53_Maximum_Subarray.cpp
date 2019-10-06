#include <iostream>
#include <vector>
using namespace std;

/**
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
*/

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
 * 方法 2；kadane's algorithm 求子序列最大值问题，
 * 设置当前最大值和全局最大值的初始值都是第一个元素，
 * 遍历数组，每次找到最大的：当前最大值 = max(nums[i],当前最大值 + nums[i])，
 * 最后保留最大的给global_sum
 * */
// int MaxSubArray2(vector<int>&nums)
// {
//     int global_sum = nums[0], current_sum=nums[0];
//     int Maxsum = 0;
//     for(int i=1;i<nums.size();i++)
//     {
//         current_sum = max(nums[i],current_sum+nums[i]);
//         if(current_sum>global_sum) global_sum = current_sum;
//     }
//     return global_sum;
// }

int main()
{
    vector<int> nums = {-1};
    cout << maxSubArray1(nums) << endl;
    return 0;
}
