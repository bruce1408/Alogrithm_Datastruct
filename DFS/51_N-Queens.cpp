#include <iostream>
#include <vector>
using namespace std;

/**
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
*/

/**
 * 方法 1，N皇后可以上下左右移动，也可以在对角线移动，所以设置三个数组分别记录当前位置的列，对角线
 * 是不是存在，然后这里主对角线和副对角线的方程如下：
 * 对角线映射到下标
 * 正： y = x + b        b = y - x + n(偏移量保证正）
 * 反： y = -x + b       b = y + x
 * b就是映射下的坐标
*/
class Solution
{
public:
    vector<string> out;
    vector<vector<string>> res;
    int n;
    vector<bool> col, dg, udg;

    vector<vector<string>> solveNQueens(int m)
    {
        n = m;
        col = vector<bool>(n);                   // 列
        dg = udg = vector<bool>(n * 2);          // 两条对角线
        out = vector<string>(n, string(n, '.')); // out 初始化为'.'
        dfs(0);
        return res;
    }

    void dfs(int k)
    {
        if (k == n) // 如果k==n那么就是最后一行，保存结果
        {
            res.push_back(out);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            // 如果当前i列和对角线没有存放元素，就操作如下
            if (!col[i] && !dg[k - i + n] && !udg[k + i])
            {
                // 置位true
                col[i] = dg[k - i + n] = udg[k + i] = true;
                out[k][i] = 'Q'; // 元素占位Q
                dfs(k + 1);
                out[k][i] = '.';
                col[i] = dg[k - i + n] = udg[k + i] = false; // 恢复现场
            }
        }
    }
};