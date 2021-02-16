#include <iostream>
#include <vector>
using namespace std;

/**
 * N皇后问题，不用输出方案，而是直接输出方案数，和51一样，最后返回结果就好了
*/

/**
 * 方法 1，使用dfs来暴搜即可
 * 这里需要记录对角线和列的情况，然后对角线
 * y = x + b;  b = y - x + n
 * y = -x + b; b = y + x
 * b是映射
*/
class Solution
{
public:
    // vector<string> out;
    int n, cnt;
    vector<bool> col, dg, udg;

    int totalNQueens(int m)
    {
        n = m;
        col = vector<bool>(n);          // 列
        dg = udg = vector<bool>(n * 2); // 两条对角线
        // out = vector<string>(n, string(n, '.')); // out 初始化为'.'
        dfs(0);
        return cnt;
    }

    void dfs(int k)
    {
        if (k == n) // 如果k==n那么就是最后一行，保存结果
        {
            cnt += 1;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            // 如果当前i列和对角线没有存放元素，就操作如下
            if (!col[i] && !dg[k - i + n] && !udg[k + i])
            {
                // 置位true
                col[i] = dg[k - i + n] = udg[k + i] = true;
                // out[k][i] = 'Q'; // 元素占位Q
                dfs(k + 1);
                // out[k][i] = '.';
                col[i] = dg[k - i + n] = udg[k + i] = false; // 恢复现场
            }
        }
    }
};