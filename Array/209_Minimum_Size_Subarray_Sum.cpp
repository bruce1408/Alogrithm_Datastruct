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
 * 给定一个正数的数组，和一个目标值s，然后找到数字里面相加子数组相加的和大于等于s的最小的序列即可；
*/

/**
 * 方法 1，利用暴力解法来做；
 * */
int minSubArrayLen(int s, vector<int> &nums)
{
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
    return lengthSum;
}

int main()
{

    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(7, nums) << endl;
    return 0;
}
