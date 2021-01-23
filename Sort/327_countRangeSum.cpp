#include <iostream>
#include <algorithm>
#include <vector>
#include "../utils/cout_vec.h"
using namespace std;

/**
 * 327 区间和的个数
 * 给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper
 * 输入: nums = [-2,5,-1], lower = -2, upper = 2,
 * 输出: 3 
 * 解释: 3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2。
 * 
*/

/**
 * 方法 1，使用树状数组来做
*/
typedef long long LL;

class Solution
{
public:
    int m;
    vector<int> c;
    int lowbit(int x)
    {
        return x & -x;
    }

    // 树状数组更新，给x加上v
    void update(int x, int y)
    {
        for (; x <= m; x += lowbit(x))
            c[x] += y;
    }

    // 求前缀和
    int query(int x)
    {
        int tot = 0;
        for (; x; x -= lowbit(x))
            tot += c[x];
        return tot;
    }

    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        vector<LL> pre; // 初始化pre数组

        pre.push_back(0); // 注意要加一个0，因为从下标1开始
        LL sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];             // 构建前缀和
            pre.push_back(sum);         // 前缀和不呢
            pre.push_back(sum - upper); // 前缀和减去up
            pre.push_back(sum - lower); // 前缀和减去low
        }

        // 离散化部分
        sort(pre.begin(), pre.end());
        m = unique(pre.begin(), pre.end()) - pre.begin(); // 得到去重之后的数组长度即可
        pre.resize(m);                                    // 重新得到去重之后的pre离散化数组

        // 开始区间和计算部分
        c.resize(m + 1, 0);                                                  // 树状数组初始化
        int zero = lower_bound(pre.begin(), pre.end(), 0) - pre.begin() + 1; // 找到pre数组中非0的第一个位置
        update(zero, 1);                                                     // 更新第一个非0的数字

        int ans = 0;
        sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            LL x = lower_bound(pre.begin(), pre.end(), sum - upper) - pre.begin() + 1; // sum-upper下标
            LL y = lower_bound(pre.begin(), pre.end(), sum - lower) - pre.begin() + 1; // sum-lower下标
            ans += query(y) - query(x - 1);                                            // 在 sum - upper ~ sum - lower 区间的个数

            LL num = lower_bound(pre.begin(), pre.end(), sum) - pre.begin() + 1; // sum下标
            update(num, 1);                                                      // 更新下标是num的数字
        }

        return ans;
    }
};

int main()
{
    vector<int> res = {-2, 5, -1};
    int low = -2, up = 2;
    Solution s;
    cout << s.countRangeSum(res, low, up) << endl;

    // vector<int> num = {1, 2, 3, 4, 5, 7, 8, 9};
    // auto it = lower_bound(num.begin(), num.end(), 6) - num.begin() + 1;
    // cout << it << endl;
}