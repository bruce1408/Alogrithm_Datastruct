#include <iostream>
#include <vector>
using namespace std;

/**
 * 63 不同的路径，给定一个二维的格子n*m,然后从左上角走右下角的所有走法
 * 这里考虑可能有障碍物
 * 然后f[i][j]状态表示从原点到ij这个格子的所有路径数目
 * 初始化f[0][0] 只有在i和j等于0的情况下为1，
 * f[i][j] 从上面走下来fij += f[i-1][j]
 * f[i][j] 从左边走过来的方案数 += f[i][j-1]
*/

int uniquePathsWithObstacles(vector<vector<int> > &s)
{
    int n = s.size(), m = s[0].size();
    vector<vector<int> > f(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 0)
            {
                if (i == 0 && j == 0)
                    f[i][j] = 1;
                if (i)
                    f[i][j] += f[i - 1][j];
                if (j)
                    f[i][j] += f[i][j - 1];
            }
        }
    }
    return f[n - 1][m - 1];
}

int main()
{
    vector<vector<int> > res = {{1, 0}};
    cout << uniquePathsWithObstacles(res) << endl;
}