#include <iostream>
#include <vector>
using namespace std;

/**
 * 152 乘积最大的子数组
 * 给定一个数组，然后找到连续的子序列是的乘积最大
*/

/**
 * 方法 1，使用动态规划来做
 * 状态划分：
 * 要么只包含nums[i]自己，或者是包含前面的部分,但是这个题目有负数的情况，所以需要两个数组来保存动态规划的内容
 * 一个f[i]表示当前最大值，还有一个g[i]表示当前的最小值，f[i] = max(两种情况，第一种就是说如果a小于0的情况，那么我就要找到一个更小的数字来和a相乘来达到最大，
 * 第二种情况就是如果a大于0的情况，那么我就需要一个更大的数字和a相乘来得到最大值，所以综上情况，我们得到的是)
*/
int maxProduct(vector<int> &nums)
{
    int res = nums[0], n = nums.size();
    vector<int> f(n, 0), g(n, 0);
    f[0] = nums[0];
    g[0] = nums[0];
    for (int i = 1; i < n; ++i)
    {
        f[i] = max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
        g[i] = min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
        res = max(res, f[i]);
    }
    return res;
}

/**
 * 方法 2，上面的优化版本，使用滚动数组优化空间复杂度
*/
int maxProduct2(vector<int> &nums)
{
    int res = nums[0];
    int f = nums[0], g = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int a = nums[i], fa = f * a, ga = g * a;
        f = max(a, max(fa, ga));
        g = min(a, min(fa, ga));
        res = max(res, f);
    }
    return res;
}

int main()
{
    int ans = 0;
    vector<int> res = {1, 2, 1, 5, -4, 7, -3, 2, 0, 1};
    cout << maxProduct(res) << endl;
}