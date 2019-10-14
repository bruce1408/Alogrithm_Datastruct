#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

/**
 * Given an unsorted integer array, find the smallest missing positive integer.
 * 
 * Example 1:
 * Input: [1,2,0]
 * Output: 3
 * 
 * Example 2:
 * Input: [3,4,-1,1]
 * Output: 2
 *  
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 无序的整数数组，然后找到第一个缺失的正整数；O(n) time, O(1) space;
 * */

/**
 * 方法 1，分情况讨论，如果这个数组不存在1，那么返回1，如果数组存在1，那么再分若干情况讨论
 * 情况有一类没有办法区分，例如1，2，4，5 和 1，2，3，4.
 * 这个方法有问题,没有考虑所有的情况；
*/
int firstMissingPositive(vector<int> &nums)
{
    int minNum = INT_MAX, maxNum = INT_MIN;
    bool oneEx = false;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
            oneEx = true;
        if (nums[i] > 1 && nums[i] < minNum)
        {
            minNum = nums[i];
        }
        if (nums[i] > maxNum)
        {
            maxNum = nums[i];
        }
    }
    cout << "the min num: " << minNum << endl;
    cout << "the max nums is: " << maxNum << endl;
    if (oneEx)
    {
        if (minNum == maxNum && maxNum - 1 == 1)
        {
            return maxNum + 1;
        }
        else if (minNum == maxNum && maxNum - 1 != 1)
        {
            return 2;
        }
        else if (maxNum != minNum && minNum - 1 != 1) //缺乏2
        {
            return 2;
        }
        else if (maxNum != minNum && minNum - 1 == 1 && (minNum + 1 == maxNum || minNum + 1 != maxNum))
        {
            return maxNum + 1;
        }
    }
    else
        return 1;
    return -1;
}

/**
 * 方法 2，利用hash_set来做，把所有大于等于0的整数存放到set中，同时找出该数组的最大值；
 * 然后开始从1到最大值之间对set集合遍历，查找当前的i是否存在，如果存在，继续遍历，否则输出当前i
 * 最后，要是都存在的话返回最大值+1即可
 * 空间复杂度是O(n)
*/
int firstMissingPositive2(vector<int> &nums)
{
    int maxNum = 0;
    unordered_set<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= 0)
            continue;
        res.insert(nums[i]);
        maxNum = max(nums[i], maxNum);
    }
    for (int i = 1; i < maxNum; i++)
    {
        if (!res.count(i))
            return i;
    }
    return maxNum + 1;
}

/**
 * 方法 3，不用额外的空间，使用的是O(1)的空间复杂度，O(n)时间复杂度
 * 按照下标把元素放到对应的下标中去，然后开始遍历，如果当前的元素和下标不相等，那么就返回
 * 下标加1，从0开始计数，如果遍历结束之后，都满足条件，那么就返回的是元素长度加1即可；
*/
int firstMissingPositive3(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}

/**
 * 方法 4，不用额外的空间，对上面的方法做一个优化，不再利用两重循环
 * 但是思路都是一样的；
*/
int firstMissingPositive4(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int cur = nums[i];
        if (cur == i + 1 || cur <= 0 || cur > nums.size())
            continue;
        swap(nums[i], nums[cur - 1]);
        if (nums[i] != nums[cur - 1])
            i--;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return nums.size() + 1;
}

int main()
{
    vector<int> nums = {1, 3, 2, 4, 5};
    cout << firstMissingPositive4(nums) << endl;
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
