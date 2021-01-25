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
 * 首先使用一个单调栈来做，保存的是元素的下标；设置ans保存结果；
 * 从头开始遍历数组，然后设置一个保存上个栈顶元素的变量last，
 * 如果当前的栈不为空且栈顶的元素小于当前元素说明形成了一个U槽，那么
 * ans加上 (栈顶元素的高度 - 上一个栈顶元素高度) * (宽度=当前下标 - 栈顶元素下标 - 1)
 * last更新为栈顶元素高度，然后弹出栈顶元素；
 * 遍历结束之后还要加上最后一个区间高度，就是(当前元素高度 - 上一个栈顶元素高度) * (当前下标 - 栈顶元素下标 - 1)；
 * 然后当前元素进栈
 * 
 * 最后整个数组遍历结束之后返回结果ans即可
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
            ans += (height[i] - last) * (i - res.top() - 1);
        res.push(i);
    }
    return ans;
}

/**
 * 方法 2，使用双指针来做，设置一个保存结果的变量res=0
 * 设置两个指针l和r分别指向数组的两个端点，然后找到这两个端点中较小的值，
 * 如果较小的数是左端点的值，那么继续从左端点进行遍历，如果有比左端点还小的数
 * 那么就res不断加上左端点和最小数的差值
 * 同理如果较小的是右端点的值，那么也和上述一样的操作，最后返回res即可
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