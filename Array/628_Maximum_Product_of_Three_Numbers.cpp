#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * 给定一个数组，然后找出三个数字相乘的最大数，三个数字可以不连续分布。思路是
 * 排序，然后找出最大的数组和最小的数字
 * 或者就是手动排序，找出最大的三个数字和最小的两个数字，可能有负数产生
 * */
// 第一种思路，就是如果三个数字是要求连续的，那么可以效仿53题，用kandane 算法来做，如果不要求连续数字，见方法二；
int maximumProduct(vector<int>& nums)
{
    if(nums.size()<3) return 0;
    int current_product = nums[0]*nums[1]*nums[2];
    int global_product = current_product;
    int i=0;
    while(i+2<nums.size())
    {
        int sum = nums[i]*nums[1+i]*nums[2+i];
        current_product = max(sum,current_product);
        if(global_product<current_product)
        {
        
            global_product = current_product;
        }
        i++;
    }
    return global_product;
}

// 第二种类型，这三个数不要求是连续的。
int maximumProduct2(vector<int>&nums)
{
    if(nums.size()<3) return 0;
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    for(const int num:nums)
    {   
        if(num>max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = num;
        }
        else if(num>max2)
        {
            max3 = max2;
            max2 = num;
        }
        else if(num>max3) 
        {
            max3 = num;
        }
        if(num<min1)
        {
            min2 = min1;
            min1 = num;
        }
        else if(num<min2)
        {
            min2 = num;
        }
    }
    return max(max1*max2*max3, min1*min2*max1);
}

int main()
{
    vector<int> nums = {-4, -3, -2, -1, 60};
    cout<<maximumProduct2(nums)<<endl;
    return 0;
}