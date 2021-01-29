#include <iostream>
#include <vector>
using namespace std;

/**
 * 154 使用二分来判断边界
*/
int findMin(vector<int> &nums)
{
    int l = 0, s = nums.size() - 1;
    // 删除后面相同的数字相同的数字
    while (s > 0 && nums[s] == nums[0])
        s--;
    if (nums[0] <= nums[s])
        return nums[0];

    // s 是新的数组长度
    int r = s;
    // 二分查找边界
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (nums[mid] >= nums[0]) // mid大于这个数，说明区间不在这一段，l要等于mid
            l = mid + 1;
        else
            r = mid;
    }
    return nums[l];
}
