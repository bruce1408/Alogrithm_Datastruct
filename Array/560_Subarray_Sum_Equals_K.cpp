#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 给定一个数组，找到和是k的连续子数组的总个数
*/

/**
 * 方法 1，使用暴力解法，时间复杂度是O(n^2)
*/
int subarraySum(vector<int> &nums, int k)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                count++;
            }
        }
    }
    return count;
}

/**
 * 方法 2，使用累加和数组来做，有点点绕
*/
int subarraySum2(vector<int> &nums, int k)
{
    int count = 0;
    vector<int> temp(nums);
    for (int i = 1; i < nums.size(); i++)
    {
        temp[i] = temp[i - 1] + nums[i];
    }

    for (int i = 0; i < temp.size(); i++)
    {
        int sum = temp[i];
        if (sum == k)
            count++;
        for (int j = i - 1; j >= 0; j--)
        {
            if (temp[i] - temp[j] == k)
                count++;
        }
    }
    return count;
}

/**
 * 方法 3，使用哈希表来做，降低时间复杂度为O(n)
 * 使用哈希表来记录前n项和的次数，初始值是(0, 1)
*/
int subarraySum3(vector<int> &nums, int k)
{
    int count = 0, sum = 0;
    unordered_map<int, int> res{{0, 1}};
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        count += res[sum - k];
        res[sum]++;
    }
    return count;
}

int main()
{
    vector<int> res = {1, 1, 1};
    int k = 2;
    cout << subarraySum3(res, k) << endl;
}