#include <iostream>
#include <vector>
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

/**
 * 方法 1，按照要求，
*/
void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i=0,j=0,k=0;
    
}


// 方法 2：按照题目要求的来做
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}

/**
 * 方法 3，使用归并的思路来做即可
*/
void merge3(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> res(m + n);
    int i = 0, k = 0, j = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            res[k++] = nums1[i++];
        }
        else
        {
            res[k++] = nums2[j++];
        }
    }
    while (j < n)
    {
        res[k++] = nums2[j++];
    }
    while (i < m)
    {
        res[k++] = nums1[i++];
    }
    if(m>n)
    {
        for(int i=0;i<m;i++)
        {
            nums1[i] = res[i];
        }
    }
}

int main()
{
    vector<int> a = {1, 2, 3, 0, 0, 0};
    vector<int> b = {4, 5, 5};
    for (auto i : c)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}