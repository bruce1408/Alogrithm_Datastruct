#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

/**
 * 42 接雨水
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 输入
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
*/

/**
 * 方法 1，使用一个单调栈来做
*/
int trap(vector<int> &height)
{
    stack<int> res;

    int ans = 0, n = height.size();
    for (int i = 0; i < n; i++)
    {
        int last = 0;
        // 如果栈元素不为空且栈顶的高度小于当前元素的高度，说明形成了一个槽
        while (res.size() && height[res.top()] <= height[i])
        {
            ans += (height[res.top()] - last) * (i - res.top() - 1);
            last = height[res.top()];
            res.pop();
        }
        if (res.size())
            ans += (i - res.top() - 1) * (height[i] - last);
        res.push(i);
    }
    return ans;
}

/**
 * 方法 2，使用双指针来做
*/
int trap(vector<int> &height)
{
    int res = 0, l = 0, r = height.size() - 1;
    while (l < r)
    {
        int mn = min(height[l], height[r]); // 找到左边和右边的最小值
        if (mn == height[l])
        {
            ++l;
            while (l < r && height[l] < mn)
            {
                res += mn - height[l++];
            }
        }
        else
        {
            --r;
            while (l < r && height[r] < mn)
            {
                res += mn - height[r--];
            }
        }
    }
    return res;
}
int main()
{
    vector<int> res = {5, 4, 2, 1, 4, 5};
    cout << trap(res) << endl;
}