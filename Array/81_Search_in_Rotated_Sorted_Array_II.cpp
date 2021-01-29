#include <iostream>
#include <vector>
using namespace std;

/**
 * 81 找到旋转数组中的某个数，和33题目类似
*/

/**
 * 方法 1，和上面33题目类似，使用二分来做
*/
bool search(vector<int> &nums, int t)
{
    if (nums.empty())
    {
        return false;
    }
    int l = 0, s = nums.size() - 1;
    // 删除前后相同的数字
    while (s > 0 && nums[s] == nums[0])
        s--;
    // s 是新的数组长度
    int r = s;
    // 二分查找边界
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (nums[mid] >= nums[0]) // mid大于这个数，说明区间不在这一段，l要等于mid
            l = mid;
        else
            r = mid - 1;
    }
    if (t >= nums[0])
        l = 0;
    else
        l = l + 1, r = s;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (nums[mid] >= t)
            r = mid;
        else
            l = mid + 1;
    }
    return nums[r] == t;
}
