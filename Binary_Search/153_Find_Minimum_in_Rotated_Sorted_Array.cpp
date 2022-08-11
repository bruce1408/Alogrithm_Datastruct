#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

/**
 * 153 和 81 和 33 都类似，使用二分来组找到边界，然后判断边界
 * 33题目是没有重复数字进行二分，81题目是有重复数字，只要删除重复数字即可，153是寻找旋转数组最小值
*/

/**
 * 方法 1，推荐使用，因为和前面的题目类似，都是先查找分段点
*/
int findMin1(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    if(nums[l]<= nums[r]) return nums[l];
    
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (nums[mid] >= nums[0])
            l = mid; // 边界的前一个值
        else
            r = mid - 1;
    }
    return nums[l+1];
}

/**
 * 方法 2
 * 使用二分，这里考虑就是如果旋转之后前后可能会有相同的元素的情况。
 * 在这种情况下，我们去掉后面旋转后的元素的重复值即可
*/
int findMin(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    // 如果有前后相同的元素，直接去掉后面的元素避免二分失效
    while (l < r && nums[l] == nums[r]) r--;
    if (nums[l] <= nums[r])
        return nums[l];

    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (nums[mid] < nums[0]) r = mid;
        else l = mid + 1;
    }
    return nums[l];
}

int main()
{
    vector<int> res = {4, 5, 6, 7, 0, 1, 2};
    int k = findMin(res);
    int k1 = findMin1(res);
    cout << k << " "<<k1<< endl;
}