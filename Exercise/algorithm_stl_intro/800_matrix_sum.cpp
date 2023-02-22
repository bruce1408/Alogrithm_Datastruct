#include <iostream>
#include <string>
#include <vector>
#include "../../utils/cout_vec.h"
using namespace std;
/**
 * 给定两个升序排序的有序数组A和B，以及一个目标值x。数组下标从0开始。
 * 请你求出满足A[i] + B[j] = x的数对(i, j)。
 * 数据保证有唯一解。
 * 输入格式 第一行包含三个整数n，m，x，分别表示A的长度，B的长度以及目标值x。
 * 第二行包含n个整数，表示数组A。第三行包含m个整数，表示数组B。
 * 输出格式
 * 共一行，包含两个整数 i 和 j。
 * 数据范围
 * 数组长度不超过100000。
 * 同一数组内元素各不相同。
 * 1≤数组元素≤109
 * 输入样例：
 * 4 5 6
 * 1 2 4 7
 * 3 4 6 8 9
 * 输出样例：
 * 1 1
*/

/**
 * 方法 1，使用一个记录次数的数组，然后每次记录重复出现的次数
 * 如果之前没有出现这个数字，那么统计长度的数字count自加一次，该数字对应的次数也加1，
 * 否则退出当前循环，从下一位开始遍历，最后返回最长的那个长度即可，这里的时间复杂度是O(n^2)
*/
int exist(vector<int> &res, int x)
{
    int n = res.size(), l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (res[mid] > x)
            r = mid - 1;
        else if (res[mid] < x)
            l = mid + 1;
        else
        {
            return mid;
        }
    }
    return -1;
}

vector<vector<int>> targetSum(vector<int> &res1, vector<int> &res2, int k)
{
    vector<vector<int>> result;
    for (int i = 0; i < res1.size(); i++)
    {
        int num2 = k - res1[i];
        int index = exist(res2, num2);
        if (index != -1)
        {
            // cout << i << " " << index;
            result.push_back({i, index});
        }
        // cout << endl;
    }
    return result;
}

/**
 * 方法 2，使用双指针算法来做，因为是升序排序的，所以第一个指针指向第一个数组的起始位置，
 * 第二个指针指向第二个数组的结束位置,然后判断如果两个数组的和加起来大于这个数，那么第二个数组就
 * 每次自减一位，然后判断和是否相同，最后输出相对位置即可，比方法 1 要简洁一点；
*/
void targetSum2(vector<int> &res1, vector<int> &res2, int target)
{
    int n = res1.size(), m = res2.size();
    for (int i = 0, j = m - 1; i < n; i++)
    {
        while (res1[i] + res2[j] > target && j >= 0)
            j--;
        if (res1[i] + res2[j] == target)
        {
            printf("%d %d\n", i, j);
        }
    }
}

int main()
{
    // int n = 5;
    // cin>>n;
    vector<int> res1 = {1, 2, 4, 7};
    vector<int> res2 = {3, 4, 6, 8, 9};
    // for (int i = 0; i < n; i++)
    //     cin >> res[i];
    int target = 6;
    // for (auto i : targetSum1(res1, res2, target))
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    targetSum2(res1, res2, target);
}