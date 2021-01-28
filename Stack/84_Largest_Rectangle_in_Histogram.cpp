#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/**
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
 * find the area of largest rectangle in the histogram.
 * 
 * 给一个直方图，宽都是1，高是数组的值，求出面积最大的直方图。
*/

/**
 * 方法 1，单调栈，推荐使用
 * 分别是用两个数组来保存左边和当前数最近的小于它的数字，和从右边起当前数字最近的小于它的数字
 * 左边如果栈不为空，且栈顶元素大于等于当前元素，那么栈顶出栈，直到栈为空或着是小于当前元素为止
 * 然后如果栈是空的话，左边记录数组left[i] =-1表示没有元素
 * 如果栈不是空，但是那么left保存当前栈顶元素即可，最后把当前下标保存进栈顶
 * 
 * 右边也是一样，处理之前先把栈清空，然后思路一样
 * 最后从头遍历，如果每个位置取面积，求出最大值即可
 * 
*/
int largestRectangleArea(vector<int> &nums)
{
    stack<int> res;
    int n = nums.size();
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++)
    {
        while (!res.empty() && nums[res.top()] >= nums[i])
            res.pop();
        if (res.empty())
            left[i] = -1;
        else
            left[i] = res.top();
        res.push(i);
    }

    res = stack<int>();
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!res.empty() && nums[res.top()] >= nums[i])
            res.pop();
        if (res.empty())
            right[i] = nums.size();
        else
            right[i] = res.top();
        res.push(i);
    }
    for (auto x : left)
        cout << x << " ";
    cout << endl;

    for (auto y : right)
        cout << y << " ";
    cout << endl;

    int s = 0;
    for (int i = 0; i < nums.size(); i++)
        s = max(s, (right[i] - left[i] - 1) * nums[i]);
    return s;
}

int main()
{
    vector<int> res = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(res) << endl;
}