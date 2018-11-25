#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

/*
    找出数组的局部最大值，局部最大，不要求是全局最大。所以
    考虑比周围两个数字都大的数字，只需要和周围两个数字比较即可，和左右比较的话，
*/
int findPeakElement(vector<int>& nums)
{
    if(nums.size()==1) return 0;
    nums.insert(nums.begin(), INT_MIN);
    nums.push_back(INT_MAX);
    for(int i=1;i<nums.size()-1;i++)
    {
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) return i-1; // 大于前一个数字，和后一个数字
    }
    return -1;
}

// 第二种方法
int findPeakElement1(vector<int>& nums) 
{
    for (int i = 1; i < nums.size(); ++i) 
    {
        if (nums[i] < nums[i - 1]) return i - 1;
    }
    return nums.size() - 1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    int k = findPeakElement(nums);
    cout<<k<<endl;
    return 0;    
}