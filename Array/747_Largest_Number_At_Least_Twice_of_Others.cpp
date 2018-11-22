#include<iostream>
#include<vector>
using namespace std;

int dominantIndex(vector<int>& nums)
{
    /*
        思路就是找出第一大和第二大的数字，如果第二大的数的2倍都小于这个数，那么
        说明满足题目要去，否则不满足
    */   
    int max1 = INT_MIN,max2 = INT_MIN;
    int index=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>max1)
        {
            max2 = max1;
            max1 = nums[i];
            index=i;

        }
        if(nums[i]>max2 && nums[i]<max1)
        {
            max2 = nums[i];
        }   
    }
    return (max2*2>max1)?-1:index;
}
int main()
{
    vector<int> nums = {0,0,0,1};
    cout<<dominantIndex(nums);
    return 0;
}