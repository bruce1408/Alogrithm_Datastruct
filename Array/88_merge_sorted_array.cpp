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
 * 方法 1，和 方法 2的思路完全是一样的。
*/
void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int len1 = nums1.size(), i = len1 - n - 1, j = n - 1, k = len1 - 1;
    while (j >= 0 && i >= 0)
    {
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}

// 方法 2
void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
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

int main()
{
    vector<int> a = {0};
    vector<int> b = {1};
    merge1(a, 0, b, 1);
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}