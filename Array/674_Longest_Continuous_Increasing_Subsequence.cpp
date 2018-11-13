#include<iostream>
#include<vector>
using namespace std;
// 和kandane 的思想一致
// 目的是寻找最长的连续递增子序列的长度,这一种方法的时间复杂度太高了
int findLengthOfLCIS(vector<int>& nums)
{
    if(nums.size()==0) return 1;
    int global_length = 0;
    for(int i=0;i<nums.size();i++)
    {
        int current_length = 0;
        int j = i;
        while(j<nums.size()-1)
        {
            if(nums[j]<nums[j+1]) 
            {
                current_length++;
                j++;
            }
            else break;
        }
        if(global_length<current_length) global_length = current_length;
    }
    return global_length+1;
}


/**
 * 第二种方法，时间上用时更少,利用kandan的思想这种方法要注意，
 * 如果你不加边界条件空数组的情况，你一定要在写++currentLength，前置++，否则长度会少一，
 * 如果你是又不写边界条件，还写的是后置++，最后在总长度加1，那么这是在空数组的时候，会报错，你多算了一个，
 * 所以，最好的写法是你自己写前置++,最省事!
 * */
int findLengthOfLCIS2(vector<int>& nums)
{
    int currentLength = 0;
    int globalLength = 0;
    int len = nums.size();
    for(int i=0;i<len;i++)
    {
        if(i==0||nums[i-1]<nums[i])
        {
            globalLength = max(globalLength, ++currentLength);
        }
        else
        {
            currentLength = 1;
        }
    }
    return globalLength;
}
int main()
{
    vector<int> res = {1,3,5,4,7};
    cout<<findLengthOfLCIS2(res)<<endl;
    return 0;
}