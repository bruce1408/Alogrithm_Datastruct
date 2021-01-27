#include <iostream>
#include <vector>

using namespace std;
/**
 * 287 
 * 题目： n+1个数的范围是 [1, n] 之间，找到重复数字,不能修改原来的数组
 */

/**
 * 方法 1, 使用类似二分查找的方式
 * 二分的时候，如果这个值在l和mid之间，那么计算s+1，然后统计s和l到mid区间的个数，如果s大于这个数
 * 说明重复的数字在这个区间内，所以r更新为mid，否则l更新为mid+1
 * 最后返回r
*/
int findDuplicate1(vector<int> &nums)
{
    int l = 1, r = nums.size() - 1;
    while (l < r)
    {

        int s = 0, mid = (l + r) >> 1;
        for (auto x : nums)
        {
            if (x >= l && x <= mid)
                s++;
        }
        if (s > mid - l + 1)
            r = mid;
        else
            l = mid + 1;
    }
    return r;
}

/**
 * 方法2 使用147链表环的思路一样，推荐算法
 * 找到第一个不重复的数，数的范围限定在1--n之间，利用快慢指针，由于是
 * 重复的数，肯定会形成闭环，用快慢指针找到环的起始位置，用两次while，第一次找到相交的入口处，第二次就是找重复数的过程。
 */
int findDuplicate2(vector<int> &nums)
{
    int a = 0, b = 0;
    while (true)
    {
        a = nums[a];       // 慢指针走一步
        b = nums[nums[b]]; // 快指针走两步
        if (a == b)        // 如果当前a和b相同
        {
            a = 0; // a从0开始，a和b每次走一步，如果再次相遇就是环的入口，也就是重复数字
            while (a != b)
            {
                a = nums[a];
                b = nums[b];
            }
            return a;
        }
    }
    return -1;
}

/**
 * 方法3 利用位操作
 * 从0~31范围内，遍历每一个数，从 0~31 中分别和每一个数组中的数进行与运算，结果大于0就累加一次cn1，和每一个数组中的数对应的下标进行与运算，
 * 结果大于0就累加一次cn2，遍历完整个数组之后，正常情况是所有数字的1是固定的，如果cn1>cn2的话，说明有重复的数，累加这个bit的数
 * 补充，关于负数的移位看c++_code移位相关代码说明；
 */
int findDuplicate3(vector<int> &nums)
{
    int res = 0, n = nums.size();
    for (int i = 0; i < 32; ++i)
    {
        int bit = (1 << i), cnt1 = 0, cnt2 = 0;
        for (int k = 0; k < n; ++k)
        {
            if ((k & bit) > 0) // 和下标运算
            {
                ++cnt1;
            }
            if ((nums[k] & bit) > 0) // 和对应下标的数运算
            {
                ++cnt2;
            }
        }
        if (cnt2 > cnt1)
            res += bit;
    }
    return res;
}

/**
 * 方法 4，因为数据范围在1-n之间，所以使用每个数字乘以负数，判断如果这个数字大于0说明是重复数字
 * 但是会改变原数组的值。
*/
int findDuplicate4(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        if (nums[abs(nums[i]) - 1] > 0)
            return abs(nums[i]);
    }
    return 0;
}

int main()
{
    vector<int> a = {2, 3, 5, 4, 3, 2, 6, 7};
    cout << findDuplicate4(a) << endl;
}
