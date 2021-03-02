#include <iostream>
#include <vector>
using namespace std;

/**
 * 63 不同的路径，给定一个二维的格子n*m,然后从左上角走右下角的所有走法
 * 这里考虑可能有障碍物
 * 然后f[i][j]状态表示从原点到ij这个格子的所有路径数目
 * 初始化f[0][0] = 0，然后f[i][0] = f[0][j] = 1,只有一种走法
 * f[i][j] = 从上面走下来或者是从左边走过来的方案数 = f[i-1][j] + f[i][j-1]
*/

int uniquePaths(int m, int n)
{
    vector<vector<int> > f(n, vector<int>(m));
    // 状态初始化
    f[0][0] = 0;
    for (int i = 0; i < n; i++)
        f[i][0] = 1;
    for (int j = 0; j < m; j++)
        f[0][j] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
            f[i][j] = f[i - 1][j] + f[i][j - 1];
    }
    return f[n - 1][m - 1];
}
