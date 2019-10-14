#include<iostream>
#include<vector>
using namespace std;
/**
 * Given two sorted integer arrays nums1 and nums2, 
 * merge nums2 into nums1 as one sorted array.
 * Note:
 * 
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to m + n)
 *  to hold additional elements from nums2
 * 
 * Example:
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * Output: [1,2,2,3,5,6]
 * 
 * 给定两个数组，一个长度数组，一个是较短的数组，把第二个短数组合并到长数组中去；保证整个数组
 * 是有序的；
*/


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int numsIndex1 = 0, numsIndex2 = 0, len = nums1.size();
    int rearNum = m;
    while(numsIndex1<m)
    {
        if(nums1[numsIndex1] < nums2[numsIndex2])
        {
            numsIndex1++;
        }
        else
        {
            int temp = nums2[numsIndex2];
            int moveIndex = numsIndex1;
            while(moveIndex < rearNum)
            {
                nums1[rearNum] = nums1[rearNum-1];
                rearNum--;
            }

        }
        
    }

}
// 一般情况，直接比较大小，赋值即可、
vector<int> mergeSortedArray(vector<int> &a, vector<int>&b)
{
    vector<int> res;
    int i=0, j=0;
    while(i<a.size()&& j<b.size())
    {
        if(a[i]<b[j])
        {
            res.push_back(a[i]);
            i++;
        }
        else
        {
            res.push_back(b[j]);
            j++;
        }
    }
    while(i<a.size())
    {
        res.push_back(a[i]);
        i++;
    }
    while(j<b.size())
    {
        res.push_back(b[j]);
        j++;
    }
    return res;
}

// 方法二：按照题目要求的来做
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while(i>=0 && j>=0)
    {
        nums1[k--] = nums1[i]>nums2[j]?nums1[i--]:nums2[j--];
    }
    while(j>=0)
    {
        nums1[k--] = nums2[j--];
    }
}


int main()
{
    vector<int> a = {1,2,3,4,6,7};
    vector<int> b = {4,5,5,6,7,8,9};
    vector<int>c = mergeSortedArray(a, b);
    for(auto i:c)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;   
}