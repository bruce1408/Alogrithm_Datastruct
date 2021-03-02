#include <iostream>
#include <vector>
using namespace std;

/**
 * 动态规划来做
 * 状态f[i]表示从0点到i的最少步数
*/

/**
 * 方法 1，动态规划
 * f[i]表示所有跳到第i个位置的最小步数
 * f[i]可以是从0~i-1跳过来的，时间复杂度是O(n^2)
*/

int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> f(n + 1);
    for (int i = 1; i < n; i++)
    {
        int t = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (j + nums[j] >= i)
                t = min(t, f[j] + 1); // 最后一步是跳到i
        }
        f[i] = t;
    }

    return f[n - 1];
}

/**
 * 方法 1，使用动态规划来做
 * 状态f[i]表示从0点到i的最少步数
 * 初始化状态f为0，然后开始遍历，i从1开始，j从0开始
 * 判断j和当前的nums[j] 和是不是小于当前的i，如果小于当前i
 * 说明j的位置跳nums[j]是跳不到i的位置的，所以j要往后自加一位
 * 否则j的位置跳nums[j]可以跳到i的位置，那么j不用自加
 * 状态f[i] = f[j] + 1即可
*/
int jump(vector<int> &nums)
{
    int n = nums.size(), j = 0;
    vector<int> f(n);
    for (int i = 1; i < n; i++)
    {
        while (j + nums[j] < i)
            j++;
        f[i] = f[j] + 1;
    }
    for (auto i : f)
        cout << i << " ";
    cout << endl;
    return f[n - 1];
}

int main()
{
    vector<int> res = {2, 3, 1, 1, 4};
    cout << jump(res) << endl;
}