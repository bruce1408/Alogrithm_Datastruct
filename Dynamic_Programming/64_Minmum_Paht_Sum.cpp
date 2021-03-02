#include <iostream>
#include <vector>
using namespace std;

/**
 * 64 最小路径和
 * 给定一个二维矩阵，然后从左上角走到右下角，求路径的最小和是多少
 * 每个格子只能从左往右或者是从上往下走
*/

/**
 * 方法 1，使用动态规划来做
 * f[i][j]表示从起点到ij这个格子的所有方案，最后要求的是最小的方案即可
 * 初始化f状态数组
 * 首先行的话是当前状态=前一个状态 + 二维数组的数字即可，列也是如此
 * 最后直接遍历ij从1开始
*/
int minPathSum(vector<vector<int> > &g)
{
    int n = g.size(), m = g[0].size();
    // f[i][j] 表示从原点到ij这个格子的所有路径
    vector<vector<int> > f(n, vector<int>(m, INT_MAX));
    f[0][0] = g[0][0];
    for (int i = 1; i < n; i++)
        f[i][0] = g[i][0] + f[i - 1][0];
    for (int i = 1; i < m; i++)
        f[0][i] = g[0][i] + f[0][i - 1];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + g[i][j];
        }
    }
    return f[n - 1][m - 1];
}

/**
 * 方法 2，思路还是动态规划，但是写法不一样，直接遍历，然后如果是ij=起点的话，那么
 * 就让初始状态等于起点，然后如果i大于0说明从上到下，如果j大于0说明从左到右
*/
int minPathSum(vector<vector<int> > &g)
{
    int n = g.size(), m = g[0].size();
    // f[i][j] 表示从原点到ij这个格子的所有路径
    vector<vector<int> > f(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                f[i][j] = g[i][j];
            if (i)
                f[i][j] = min(f[i][j], f[i - 1][j] + g[i][j]);
            if (j)
                f[i][j] = min(f[i][j], f[i][j - 1] + g[i][j]);
        }
    }
    return f[n - 1][m - 1];
}