#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * 85 求解数组中1的最大面积
*/

/**
 * 方法 1，给定一个数组，然后只有0和1两个数字，找出数组中1构成的最大面积是多少
 * 这里可以借鉴84题目单调栈的做法，就是一个给定的一维数组表示高度，然后求解这个
 * 一维数组最大柱型面积是多少，这里可以借鉴
 * 首先是对一个二维数组，先求出ij这个位置的高度是多少
 * 例如输入：
 * [1 0 1 0 0]
 * [1 0 1 1 1]
 * [1 1 1 1 1]
 * [1 0 0 1 0]
 * 
 * 最后得到的高度h数组是
 * 1 0 1 0 0 
 * 2 0 2 1 1 
 * 3 1 3 2 2 
 * 4 0 0 3 0 
 * 计算思路如下，如果当前位置有1，然后高度h = 1 + 上一行的高度
 * 这样得到h数组，最后遍历每一行一位数组，然后进行计算最大面积是多少，这个部分参考84题单调栈
 */
int maxarea(vector<int> &nums)
{
    int n = nums.size();
    stack<int> res;
    vector<int> left(n), right(n);
    // 左边小于当前数的最近的数字
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

    // 栈清空然后计算从右边开始的小于当前数字的最近的数
    res = stack<int>();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!res.empty() && nums[res.top()] >= nums[i])
            res.pop();
        if (res.empty())
            right[i] = n;
        else
            right[i] = res.top();
        res.push(i);
    }

    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = max(s, (right[i] - left[i] - 1) * nums[i]);
    }
    return s;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> h(n, vector<int>(m, 0)); // 设置一个数组然后保存ij位置的高度是多少
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 如果当前位置是1，那么如果i从第二行开始，使用递归来求每一行高度，当期i高度是上一行高度+1
            if (matrix[i][j] == '1')
            {
                if (i > 0)
                    h[i][j] = 1 + h[i - 1][j];
                else
                    h[i][j] = 1;
            }
        }
    }
    // 最后计算部分，遍历每一行，然后每一行的高度得到一个面积的最大值。
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, maxarea(h[i]));
    }
    return res;
}
