#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    /*
        失败的方法// 失败的方法
        求解三个数相加等于0数组。可以求解，但是有重复数组,方法失败
    */
    int n = nums.size(),index1 = INT_MIN,index2=INT_MIN;
    vector<int> result;
    vector<vector<int>>finalResult;
    unordered_map<int ,int>indexPosition;
    sort(nums.begin(), nums.end());
    for(auto i:nums) ++indexPosition[i];
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        if (i > 0 && nums[i] == nums[i - 1]) continue; // 忽略连续两个相同的数的结果
        cout<<nums[i]<<endl;
        while(j++<n)
        {
            if(indexPosition.count(0-nums[i]-nums[j])>0)
            {

                finalResult.push_back({nums[i],nums[j],0-nums[i]-nums[j]});
            }
            else break;
        }
    }
    return finalResult;
}


/*
    没有重复数组，标准求解,主要的问题就是重复数组怎么处理，一般想法是去重，但是还要写一个函数
    下面的解法是直接在程序里去掉重复的数组。
*/ 
vector<vector<int>> threeSum1(vector<int>& nums) 
{
    sort(nums.begin(), nums.end()); // 一定要排序
    vector<vector<int>> res;
    for (unsigned int i=0; i<nums.size()-2; i++) 
    {
        if ((i>0) && (nums[i]==nums[i-1])) continue; // 两个数一样的话就跳过
        int l = i+1, r = nums.size()-1;  // 两个指针
        while (l<r) 
        {
            int s = nums[i]+nums[l]+nums[r];
            if (s>0) r--;
            else if (s<0) l++;
            else 
            {
                // 去重复数组16. 3Sum Closest
                res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                while (nums[l]==nums[l+1]) l++;
                while (nums[r]==nums[r-1]) r--;
                l++; r--;
            }
        }
    }
    return res;
}


int main()
{
    vector<int> res = {-1, 0, 1, 2, -1, -4};
    // threeSum(res);
    for(auto &i: threeSum1(res))
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}