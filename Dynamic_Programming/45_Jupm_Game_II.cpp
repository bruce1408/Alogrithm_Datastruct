#include <iostream>
#include <vector>
using namespace std;

/**
 * 动态规划来做
 * 状态f[i]表示从0点到i的最短距离
*/

/**
 * 方法 1，使用动态规划来做
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