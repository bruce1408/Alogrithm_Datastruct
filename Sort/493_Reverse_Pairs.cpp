#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 493 翻转对
 * 给一个数组，数组中的情况是这样的，
 * 如果下标 i < j 且 a[i] > a[j] * 2,那么算作是一个翻转对
*/

/**
 * 方法 1，使用暴力来做, 超时且数据越界
*/
int reversePairs(vector<int> &nums)
{
    int n = nums.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > 2 * nums[j])
                ans++;
        }
    }
    return ans;
}

/**
 * 方法 2，使用树状数组来做
 * 和327 题目非常类似
*/
typedef long long LL;
int m;
vector<int> c;
int lowbit(int x)
{
    return x & -x;
}

int getSum(int x)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += c[i];
    return sum;
}

void update(int x, int v)
{
    for (int i = x; i <= m; i += lowbit(i))
        c[i] += v;
}

int reverseParis2(vector<int> &nums)
{
    int n = nums.size();
    vector<LL> b(2 * n);

    // 离散化部分
    for (int i = 0; i < n; i++)
    {
        b[i] = nums[i];
        b[i + n] = 2 * nums[i];
    }
    sort(b.begin(), b.end());
    m = unique(b.begin(), b.end()) - b.begin();
    b.resize(m);
    c.resize(m + 1);

    // 计算比当前数小的数字, 要从后往前遍历
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int x = lower_bound(b.begin(), b.end(), nums[i]) - b.begin() + 1;
        ans += getSum(x - 1);
        int y = lower_bound(b.begin(), b.end(), (LL)(nums[i]) * 2) - b.begin() + 1;
        update(y, 1);
    }
    return ans;
}

int main()
{
    vector<int> res = {1, 3, 2, 3, 1};
    cout << reverseParis2(res) << endl;
}
