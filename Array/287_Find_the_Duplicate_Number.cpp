#include<iostream>
#include<vector>

using namespace std;
/**
 * 题目： n+1个数的范围是 [1, n] 之间，
 * 方法1 使用类似二分查找的方式
 * 思路：
 * 先求出数组的长度的中位数，中位数把数组分成两部分，然后判断两部分是否大于这个中位数的数组的个数，如果是，那么说明重复的数就在大于中位数的那一部分，举例如下
 * [2,3,5,4,3,2,6,7],8个数，那么中位数是4，把这个数组分成两部分，一部分是1~4，5~7，数组在第一部分0~4内出现的小于中位数的个数总和大于中位数，说明就在第一部分，同理，第二部分也
 * 按照这种方法判断，如果是在第一部分，那么继续用二分的思想，求中位数，然后继续下去，直到左端大于等于右端，判断终止；
 * 
 * [2,3,5,4,3,2,6,7], mid=4, 数组分成1~4, 5~7两部分，统计每一部分mid的个数，1~4部分，1：0，2：2，3：2，4：1，总共出现了5次，大于mid，说明重复的数就在这一部分，然后接着使用二分查找
 * 继续搜索
 * 
*/

int findDuplicate1(vector<int>&nums)
{
    int left=0, right=nums.size();
    while(left<right) // 这个只有一个数那么不返回，所以是<号
    {
        int mid = left + (right - left)/2;
        int countNum = 0;
        for(auto i:nums)
        {
            if(i<=mid) ++countNum;
        }
        if(countNum > mid)
        {
            right = mid;
        }
        else left = mid + 1;
    }
    return right;
}

/**
 * 方法2 快慢指针的办法
 * 思路：
 * 数组不是有序的，不能排序，时间复杂度少于O(n^2),空间复杂度是O(1);
 * 找到第一个不重复的数，数的范围限定在1--n之间，利用快慢指针，由于是
 * 重复的数，肯定会形成闭环，用快慢指针找到环的起始位置，用两次while，第一次
 * 找到相交的入口处。
 * 第二次就是找重复数的过程。
 */

int findDuplicate2(vector<int>&nums)
{
    int slow=0, fast=0;
    while(true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(slow==fast) break;
    }
    int t=0;
    while(true)
    {
        slow = nums[slow];
        t = nums[t];
        if(slow==t) break;
    }
    return slow;
}

/**
 * 和方法2是一个思路，只不过我这里没有用到t，少用了一个变量，代码按照思路更加直观一点
 */

int findDuplicate3(vector<int>&nums)
{
    int slow = 0, fast = 0;
    while(true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(slow==fast) break;   
    }
    slow = 0;
    while(fast!=slow)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

/**
 * 方法3 利用位操作
 * 思路：
 * 从0~31范围内，遍历每一个数，从 0~31 中分别和每一个数组中的数进行与运算，结果大于0就累加一次cn1，和每一个数组中的数对应的下标进行与运算，
 * 结果大于0就累加一次cn2，遍历完整个数组之后，正常情况是所有数字的1是固定的，如果cn1>cn2的话，说明有重复的数，累加这个bit的数
 * 
 * 补充，关于负数的移位看c++_code移位相关代码说明；
 */

int findDuplicate4(vector<int>& nums) {
    int res = 0, n = nums.size();
    for (int i = 0; i < 32; ++i) {
        int bit = (1 << i), cnt1 = 0, cnt2 = 0;
        for (int k = 0; k < n; ++k) {
            if ((k & bit) > 0) // 和下标运算
            {
                ++cnt1;
            }
            if ((nums[k] & bit) > 0) // 和对应下标的数运算
            {
                ++cnt2;
            } 
        }
        if (cnt2 > cnt1) res += bit;
    }
    return res;
}
int main()
{
    vector<int> a = {2,3,5,4,3,2,6,7};
    cout<<findDuplicate4(a)<<endl;
}

