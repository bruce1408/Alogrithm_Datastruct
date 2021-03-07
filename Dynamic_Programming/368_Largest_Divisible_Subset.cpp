#include <iostream>
#include <vecrtor>
using namespace std;

/**
 * 368 给定一个数组，然后返回子序列满足要求
 * 1.任意两个数字都是互为倍数，一个是另一个数的倍数
 * 输入：[1,2,4,8]
 * 输出：[1,2,4,8]
*/

/**
 * 方法 1，排序数组然后在做任意的子集可以对应一个子序列
 * 所以在排序好的序列中找到长度最长的满足要求的子序列
 * 应为序列是排好序的，那么子序列也是有序的，且后面的数字是前面的数字的倍数关系
 * 动态规划来做，状态f[i]表示i结尾的最长子序列的长度，这个题目还需要求得方案
*/
vector<int> largestDivisibleSubset(vector<int> &nums)
{
    if (nums.empty())
        return {};
    sort(nums.begin(), nums.end());
    int n = num.size();
    vector<int> f(n);

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0)
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        if (f[k] < f[i])
            k = i;
    }
    vector<int> res(1, nums[k]);
    while (f[k] > 1)
    {
        for (int i = 0; i < k; i++)
        {
            if(nums[k] % nums[i] == 0 && f[k] == f[i] + 1)
            {
                res.push_back(nums[i]);
                k = i;
                break;
            }
        }
    }
    return res;
}