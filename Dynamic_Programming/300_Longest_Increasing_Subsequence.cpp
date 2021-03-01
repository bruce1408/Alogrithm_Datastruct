#include <iostream>
using namespace std;

/**
 * 300 求解最长上升子序列
*/

/**
 * 方法 1，使用DP动态规划来做
 * 两个指针，一个i从0-n，然后另一个从0到i开始指向
 * 状态f[i]表示每个数字结尾的最长上升子序列的长度
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

/**
 * 方法 2，使用nlogn的算法
*/
int lengthOfLIS(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    vector<int> f;
    f.push_back(nums[0]); //长度为1的序列的末尾值为nums[0]
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > f.back())
            f.push_back(nums[i]);
        else
        {
            //然后在f[0]到f[i-1]中找到最后一个大于f[i]的，若没有则长度加1
            int l = 0, r = f.size() - 1;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (f[mid] >= nums[i])
                    r = mid;
                else
                    l = mid + 1;
            }
            if (f[l] >= nums[i])
                f[l] = nums[i];
        }
    }

    return f.size();
}
