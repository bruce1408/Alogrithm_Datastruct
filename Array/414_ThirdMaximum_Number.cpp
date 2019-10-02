#include <iostream>
#include <vector>
#include <set>
using namespace std;

/**
 * Given a non-empty array of integers, 
 * return the third maximum number in this array. 
 * If it does not exist, return the maximum number. 
 * The time complexity must be in O(n).
 * 
 * Example 1:
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * Explanation: The third maximum is 1.
 * 
 * 求数组中最大的第三个数字，先求出数组中最大的第二个数字,
 * 然后依次求解数组中最大的第三个数字,
 * 主要是怎么求解最大的第二个数字，如果第二个数字求解出来了，那么第三个最大的数也可以求解    
 */

/**
 * 方法 1，
*/
int thirdMax1(vector<int> &nums)
{
    int len = nums.size();
    if (len < 3)
        return len == 1 ? nums[0] : max(nums[0], nums[1]);
    long maxNum = LONG_MIN, midNum = LONG_MIN, thirdNum = LONG_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > maxNum)
        {
            thirdNum = midNum;
            midNum = maxNum;
            maxNum = nums[i];
        }
        else if (nums[i] > midNum && nums[i] < maxNum)
        {
            thirdNum = midNum;
            midNum = nums[i];
        }
        else if (nums[i] > thirdNum && nums[i] < midNum)
        {
            thirdNum = nums[i];
        }
    }
    return (thirdNum == LONG_MIN || thirdNum == midNum) ? maxNum : thirdNum;
}

int thirdMax2(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    long max1 = LONG_MIN;
    long max2 = LONG_MIN;
    long max3 = LONG_MIN;
    for (auto i : nums)
    {
        if (i > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = i;
        }
        else if (i > max2 && i <= max1)
        {
            max3 = max2;
            max2 = i;
        }
        else if (i > max3 && i < max2)
        {
            max3 = i;
        }
    }
    return (max3 == LONG_MIN || max3 == max2) ? max1 : max3;
}

// 这个就是用数组来做，但是时间复杂度不满足O（n），了解即可
int thirdMax3(vector<int> &nums)
{
    set<int> s;
    for (int num : nums)
    {
        s.insert(num); // 自动的从小到大的排序
        if (s.size() > 3)
        {
            s.erase(s.begin()); // 永远是3的长度
        }
    }
    return s.size() == 3 ? *s.begin() : *s.end();
}

int main()
{
    vector<int> nums = {1, 2, -2147483648};
    cout << thirdMax1(nums);
    return 0;
}