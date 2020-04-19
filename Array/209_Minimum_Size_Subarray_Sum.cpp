#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * Given an array of n positive integers and a positive integer s, 
 * find the minimal length of a contiguous subarray of which the sum ≥ s. 
 * If there isn't one, return 0 instead.
 * 
 * Example: 
 * Input: s = 7,
 * nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: 
 * the subarray [4,3] has the minimal length under the problem constraint.
 * 
 * 给定一个正数的数组，和一个目标值s，然后找到数字里面子数组相加的和大于等于s的最小的序列即可；
*/

/**
 * 方法 1，利用暴力解法来做；时间复杂度较高，应该是O(n!)
 * */
int minSubArrayLen1(int s, vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int lengthSum = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int sumMax = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sumMax += nums[j];
            if (sumMax >= s)
            {
                lengthSum = min(j - i + 1, lengthSum);
            }
        }
    }
    return (lengthSum == INT_MAX) ? 0 : lengthSum;
}

/**
 * 方法 2，使用两个指针来做，时间复杂度是O(n)，就是按照逻辑算法来做
*/
int minSubArrayLen2(int s, vector<int> &nums)
{
    int len = nums.size(), left = 0, right = 0, sum = 0, res = len + 1;
    while (right < len)
    {
        while (sum < s && right < len)
        {
            sum += nums[right];
            right += 1;
        }
        while (sum >= s)
        {
            res = min(res, right - left);
            sum -= nums[left];
            left++;
        }
    }
    return res == len + 1 ? 0 : res;
}

/**
 * 方法 3，同样的思路，另外一种写法
*/
int minSubArrayLen3(int s, vector<int> &nums)
{
    int res = INT_MAX, left = 0, sum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        while (left <= i && sum >= s)
        {
            res = min(res, i - left + 1);
            sum -= nums[left++];
        }
    }
    return res == INT_MAX ? 0 : res;
}
int main()
{

    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen3(7, nums) << endl;
    return 0;
}
