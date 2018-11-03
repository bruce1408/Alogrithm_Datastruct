#include<iostream>
#include<vector>
using namespace std;
/**
 * 题目描述：
 * 给定一个数字，插入到原来的数组中，返回插入位置，如果是有这个数字，那么直接返回位置下标，否则，返回插入的位置，
 * 当前的数组的数大于你插入的数字的话，肯定插在当前的位置
 * */
int searchInsert(vector<int>&nums, int target)
{
    int res = 0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>=target) return i;
        else
        {
            res = i;
        }
    }
    return res+1;
}

// 方法二：如果数组中的数字大于等于要插入的数字，那么直接插入该位置。只要是大于的，肯定是插入第一个位置
int searchInsert1(vector<int>&nums, int target)
{
    int res = 0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>=target) return i;
    }
    return nums.size();
}


// 方法三：由于是排好序的，利用二分查找方法来做
int searchInsert2(vector<int>&nums,int target)
{
    int len = nums.size(), i=0;
    while(i<len)
    {
        int mid = (i+len)/2;
        if(nums[mid]<target)
        {
            i = mid+1;
        }
        else
        {
            len = mid; 
        }
    }
    return i;
}


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if (nums.back() < target) return nums.size();
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};

int main()
{
    vector<int> nums = {1,3,5,8};
    cout<<searchInsert(nums, 4)<<endl;
    return 0;
}