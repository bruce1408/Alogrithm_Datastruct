#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findUnsortedSubarray(vector<int>& nums)
{
    /*  
        题目要去是找出最短无需的数组，如果这个无需数组对它进行排序的话，那么整个
        数组就是有序的。这样的最短序列就是要求的序列
        第一种方法 就是利用一个辅助数组；思路很简单 O(n)时间 O(n)空间
    */
    if(nums.size()==0) return 0;
    int length  = 0;
    int start = -1,end = -1;
    vector<int> temp;
    for(auto num:nums) temp.push_back(num);
    sort(temp.begin(),temp.end()); // 对这个辅助数组排序
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=temp[i])
        {
            if(start==-1) start = i; // 对应位置数字不同，那么更新相应位置上的数字，
            end = i;  // end只要不相同就更新
        }
    }
    if(start==end) length=0;
    else 
    {
        length = end-start + 1;
    }
    return length;

}


int findUnsortedSubarray1(vector<int> &nums)
{
    /*
        第二种方法，思路和上面一样，重做一次；
    */
    int n = nums.size();
    int mx = nums[0],mn = nums[n-1];
    int start=-1,end = -2;
    for(int i=0;i<n;i++)
    {
        mx = max(mx, nums[i]);
        mn = max(mn, nums[n-i-1]);
        if(mx>nums[i]) end = i;
        if(mn<nums[n-i-1]) start = n-i-1;
    }
    return end-start+1;

}
int main()
{
    vector<int> nums = {1,3,5,4,2};
    cout<<findUnsortedSubarray(nums)<<endl;
    return 0;
}