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
 * 方法 1，使用双指针来做，从后往前遍历即可
 */
void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n)
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
    while (j >= 0) // 如果第二个数没有存完，把第二个数保存进来即可
        nums1[k--] = nums2[j--];
}

int main()
{
    vector<int> a = {1, 2, 3, 0, 0, 0};
    vector<int> b = {2, 5, 6};
    merge1(a, 3, b, 3);
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}