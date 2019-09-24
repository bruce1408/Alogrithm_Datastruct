#include<iostream>
#include<vector>
using namespace std;

/**
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the 
 * relative order of the non-zero elements.
 * Example:
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * 这道题目意思是出现0的话,把0全部移动道数组的最后,不改变原来非0的元素的顺序.
*/

/**
 * 方法 1, 和原来数组构成一个一样的数组res,然后统计一个数组0出现的个数,遍历这个新的数组res,然后给定两个指针index1, index2,一个指向新数组res,一个指向原来的数组nums,
 * 两个指针都从0开始,如果是res出现非0的数字,那么把这个数字复制到nums数组中去,nums[index2] = res[index1];且两个指针都自加一次,否则,index1指针加1,最后
 * 所有非0的数组应该都已经复制到nums数组中了,剩下的就是把0给nums,index2上次保留的是非0数字的下标位置,判断,如果index++不越界,那么nums[index2++]=0;
 * 时间复杂度是O(n),空间复杂度是O(n);
*/
void moveZeroes(vector<int> &nums)
{
    vector<int>res = nums;
    int countZeros = 0;
    int len = nums.size();
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0) countZeros+=1; 
    }
    int index1 = 0, index2 = 0;
    while(index1 < len)
    {
        if(res[index1]!=0)
        {
            nums[index2] = res[index1];
            index1++;
            index2++;
        }
        else index1++;
    }
    while(index2<len)
    {
        nums[index2++] = 0;
    }
}


/**
 * 方法 2,利用两个指针,然后其中一个指向的是非0的元素,如果存在0,那么第一个非0的元素和其交换位置即可,超级牛逼的方法!
 * 时间复杂度是O(n),空间复杂度是O(1)
*/

void moveZeroes2(vector<int> &nums)
{
    for(int i =0,j=0;i<nums.size();i++)
    {
        if(nums[i])
        {
            swap(nums[i],nums[j++]);
        }         
    }
}

int main()
{
    vector<int> res = {0,1,0,3,12};
    moveZeroes(res);
    for(auto u: res)
    {
        cout<<u<<" ";
    }
}