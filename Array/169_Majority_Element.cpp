#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/**
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * Example 1:
 * 
 * Input: [3,2,3]
 * Output: 3
 * Example 2:
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 目的就是求出一个数组中出现最多的数字
*/


/**
 * 方法 1,寻找数组中的众数。方法一就是用哈希表，然后来统计每一个出现的次数
 * 但是也需要O(n)空间
 * */
int majorityElement(vector<int>& nums)
{
    int countNum=0;
    int majortiyNum = 0;
    unordered_map<int, int> temp;
    for(auto i:nums)
    {
        ++temp[i];
    }
    for(auto &i:temp)
    {
        if(i.second>countNum)
        {
            countNum = i.second;
            majortiyNum = i.first;
        }   
    }
    return majortiyNum;
}


// 这是对于第一个版本哈希表的优化，时间复杂度是O(n)
int majorityElement(vector<int>& nums)
{
    int countNum=0;
    int majortiyNum = 0;
    unordered_map<int, int> temp;
    for(auto i:nums)
    {
        ++temp[i];
        if(temp[i]>countNum)
        {
            countNum = temp[i];
            majortiyNum = i;
        }  
    }

    return majortiyNum;
}

// 摩尔投票法
int majorityElement2(vector<int>&nums)
{
    int count=1;
    int majorityNum = nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(count>=1)
        {
            if(majorityNum==nums[i]) count++;
            else count--;
        }
        else
        {
            majorityNum=nums[i];
            count++;
        }      
    }
    return majorityNum;
}
int main()
{
    // vector<int> res = {1,2,3,4,5,6,6,6,7};
    vector<int> res = {2,2,3};
    cout<<majorityElement2(res)<<endl;
    return 0;
}