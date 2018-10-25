// 找出满足的索引

#include<iostream>
#include<vector>
using namespace std;

// 方法一超时了，但是没有报错
int findIndex(vector<int> &nums)
{
    if(nums.size()<3) return -1;
    int pre=nums.size()-1,bef=0;
    int sum1 = 0, sum2=0;
    while(bef!=pre)
    {
        sum1 +=nums[bef++];
        sum2 +=nums[pre--];
        if(sum1==sum2 && bef==pre) 
        {
            return bef;
        }
        else if(sum1<sum2)
        {
            sum1 +=nums[bef];
            bef++;
        }
        else
        {
            sum2+=nums[pre];
            pre--;
        }
    }
    return -1;
}


// 方法二没问题；这种思路很好
int findIndex2(vector<int>&nums)
{
    if(nums.size()<3) return -1;
    int sum=0, leftsum=0;
    for(int x:nums) sum+=x;
    for(int i=0;i<nums.size();i++)
    {
        if(leftsum == sum-leftsum-nums[i]) return i;
        else
        {
            leftsum += nums[i];
        }
    }
    return -1;
}

int main()
{
    vector<int> res = {1,3,7,6,5,5,1};
    int i = findIndex(res);
    cout<<i<<": "<<res[i]<<endl;
    return 0;
}