#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

/**
 * 153 和 81 和 33 都类似，使用二分来组找到边界，然后判断边界
*/

/**
 * 方法 1，使用二分来做，这样做出来的话是边界的前一个值
*/
int findMin(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (nums[mid] >= nums[0])
            l = mid; // 边界的前一个值
        else
            r = mid - 1;
    }
    int s = 0;
    if (l + 1 < nums.size())
        return nums[l + 1];
    else
        return nums[s];
}

/**
 * 方法 2，思路一样优化，这样做的是边界的下一个值
*/
int findMin2(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    if (nums[0] < nums[r])
        return nums[0];
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (nums[mid] >= nums[0])
            l = mid + 1; // 边界的下一个值
        else
            r = mid;
    }
    return nums[l];
}

/**
 * 方法 3，使用二分查找，推荐算法
 * 使用二分，这里考虑就是如果旋转之后前后可能会有相同的元素的情况。
 * 在这种情况下，我们去掉后面旋转后的元素的重复值即可
*/
int findMin(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    // 如果有前后相同的元素，直接去掉后面的元素避免二分失效
    while (l < r && nums[l] == nums[r])
        r--;
    if (nums[l] <= nums[r])
        return nums[l];

    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (nums[mid] < nums[0])
            r = mid;
        else
            l = mid + 1;
    }
    return nums[l];
}

int main()
{
    vector<int> res = {4, 5, 6, 7, 0, 1, 2};
    int k = findMin(res);
    int k = findMin1(res);
    cout << k << endl;
}