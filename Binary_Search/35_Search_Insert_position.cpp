#include <iostream>
#include <vector>
using namespace std;
/**
 * 35 插入位置选择
 * 题目描述：
 * 给定一个数字，插入到原来的数组中，返回插入位置，如果是有这个数字，
 * 那么直接返回位置下标，否则，返回插入的位置，
 * 当前的数组的数大于你插入的数字的话，肯定插在当前的位置
 * */

/**
 * 方法 1，如果数组中的数字大于等于要插入的数字，那么直接插入该位置。
 * 只要是大于的，肯定是插入第一个位置
 * */
int searchInsert1(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= target)
            return i;
    }
    return nums.size();
}

/**
 * 方法 2，推荐做法。由于是排好序的，利用二分查找方法来做
 * 返回第一个大于等于这个数的位置即可，时间复杂度logn
 * */
int searchInsert(vector<int> &nums, int target)
{
    int l = 0, r = nums.size();
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (nums[mid] >= target)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    vector<int> nums = {1, 3, 5, 8};
    cout << searchInsert(nums, 4) << endl;
    return 0;
}