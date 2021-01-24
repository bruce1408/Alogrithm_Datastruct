#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 34 给定一个升序排列的数组和一个目标值，求出这个目标值所在的下标范围，如果不存在返回-1,-1
*/

/**
 * 方法 1，经典的二分查找来做。使用两个二分
 * 第一个二分找到第一个大于等于target的下标
 * 第二个二分找到最后一个小于等于target的小标
 * 这样就找到了
*/
vector<int> searchRange(vector<int> &nums, int t)
{
    // 第一个二分查找
    if (nums.empty())
        return {-1, -1};
    int start = -1;
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (nums[mid] >= t)
            r = mid;
        else
            l = mid + 1;
    }
    if (nums[l] != t)
        return {-1, -1};

    // 第二个二分查找
    start = l;
    l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (nums[mid] <= t)
            l = mid;
        else
            r = mid - 1;
    }
    return {start, l};
}

int main()
{
    vector<int> res = {1, 3};
    for (int i : searchRange(res, 1))
        cout << i << " ";

    return 0;
}