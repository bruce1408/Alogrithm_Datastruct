#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
    排序数组中查找数字,二分法查找 和 153 很类似
    中间还是有一个分割，分成两种情况，mid在分割线的左侧和分割线的右侧分别讨论两种情况！
    1： start < target < mid target只能在左侧，left移到mid；否则，在右侧
    2:  mid < target <end;
*/
int search(vector<int>& nums, int target) 
{
    if(nums.size()==0) return -1;
    int start = 0,end = nums.size()-1;
    while(start+1<end)
    {
        int mid = start + (end - start)/2;
        if(nums[mid]==target) return mid;
        if(nums[start]<nums[mid])
        {
            if(nums[start]<=target && target <= nums[mid]) end = mid;
            else start = mid;
        }
        else if(nums[mid]<nums[end])
        {
            if(nums[mid] <= target && target <= nums[end]) start = mid;
            else end = mid;
        }
    }
    if(nums[start]==target) return start;
    if(nums[end]==target) return end;
    return -1;
}
