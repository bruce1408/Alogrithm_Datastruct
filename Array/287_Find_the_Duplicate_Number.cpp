#include<iostream>
#include<vector>

using namespace std;
// 方法1 使用类似二分查找的方式；
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
 * 数组不是有序的，不能排序，时间复杂度少于O(n^2),空间复杂度是O(1);
 * 找到第一个不重复的数，数的范围限定在1--n之间，利用快慢指针，由于是
 * 重复的数，肯定会形成闭环，用快慢指针找到环的起始位置，用两次while，第一次
 * 找到相交的入口处。
 * 第二次就是找重复数的过程。
 * */
int findDuplicate(vector<int>&nums)
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
int main()
{
    vector<int> a = {2,3,5,4,3,2,6,7};
    cout<<findDuplicate1(a)<<endl;
}