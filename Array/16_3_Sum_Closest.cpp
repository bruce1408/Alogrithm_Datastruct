#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
using namespace std;

/*
    没有重复数组，标准求解,主要的问题就是重复数组怎么处理，一般想法是去重，但是还要写一个函数
    下面的解法是直接在程序里去掉重复的数组。
*/ 
int threeSumClosest(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    int closet = nums[0]+nums[1]+nums[2];
    int temp, n=nums.size(), diff = abs(closet - target);
    for(int i=0;i<n;i++)
    {
        int left=i+1, right = n-1;
        while(left<right)
        {
            int sum = nums[i]+nums[left] +nums[right];
            if(abs(sum-target)<diff)
            {
                diff = abs(sum-closet);
                closet = sum;
            }
            if(sum<target) ++left;
            else --right;
        }
    }
    return closet;
}


int main()
{
    vector<int> res = {-1, 2, 1, -4};
    threeSumClosest(res);
    return 0;
}