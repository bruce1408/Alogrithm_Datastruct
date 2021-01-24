#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 33, 给一个数组，然后数组本来是升序的，但是在未知的某点进行旋转之后不是升序的
 * 现在给出一个目标值，找到目标值的位置索引，不存在就返回-1；
 * 排序数组中查找数字,二分法查找 和 153 很类似
 * 
 * 中间还是有一个分割，分成两种情况，mid在分割线的左侧和分割线的右侧分别讨论两种情况！
 * 1： start < target < mid target只能在左侧，left移到mid；否则，在右侧
 * 2:  mid < target <end;
*/

/**
 * 方法 1，就是遍历一遍，但是时间复杂度O(n)，就不写了，方法 2，使用二分，时间复杂度是O(logn)
 * 使用两次二分查找就可以做出来，
 * 第一个二分是来找到这个数组的端点，
 * 第二个二分是在严格单调的区间端点内进行查找即可
*/
int search(vector<int> &nums, int t)
{
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (nums[mid] >= nums[0]) // 如果mid大于位置0的数，说明在这一段，那么区间端点就不再这个中间，所以l = mid
        {
            l = mid;
        }
        else
            r = mid - 1;
    }

    // 确定目标数所在的区间的边界
    if (t >= nums[0]) // 如果目标数大于nums[0],说明在第一段区间内
        l = 0;
    else                                // 说明在第二段区间内，l = r+1,r = nums.size()-1
        l = l + 1, r = nums.size() - 1; // 这里要注意如果只有1个数的话，那么不进行第一个二分，所以 l= 1, r =0,最后的二分要取r端点，否则越界
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (nums[mid] >= t)
            r = mid;
        else
            l = mid + 1;
    }
    return nums[r] == t ? l : -1; // nums要取右端点，否则越界
}

int main()
{
    vector<int> res = {1};
    cout << search(res, 0) << endl;
}
