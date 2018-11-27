#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
// 求一个数组缺省的数字。数字0~n是连续的数字中缺少的数
// 方法一：利用n项和
int missingNumber(vector<int>& nums)
{
    int n = nums.size();
    int sum = (n+1)*n/2;
    for(int i=0;i<nums.size();i++)
    {
        sum-=nums[i];
    }
    return sum;
}

// 方法二：利用位运算！
int missingNumber1(vector<int>& nums) 
{
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) res ^= (i + 1) ^ nums[i];
    return res;
}

// 方法三：二分查找来做。
int main()
{
    vector<int>nums = {3,0,1};
    cout<<missingNumber(nums);
    return 0;
}