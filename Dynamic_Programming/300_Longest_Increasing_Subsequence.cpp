#include <iostream>
using namespace std;

/**
 * 300 求解最长连续子序列
*/

/**
 * 方法 1，使用DP动态规划来做
*/
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(), k = 0;
        vector<int> f(n);
        for (int i = 0; i < n; i++)
        {
            f[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            k = max(k, f[i]);
        }
        return k;
    }
};