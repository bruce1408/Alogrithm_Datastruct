#include <iostream>
#include <vector>
using namespace std;
/**
 * 88 合并两个有序数组到其中一个数组之中。
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

/**
 * 方法 2
 */
void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = nums1.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
    while (j >= 0)
        nums1[k--] = nums2[j--];
}

int main()
{
    vector<int> a = {1, 2, 3, 0, 0, 0};
    vector<int> b = {2, 5, 6};
    merge2(a, 3, b, 3);
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}