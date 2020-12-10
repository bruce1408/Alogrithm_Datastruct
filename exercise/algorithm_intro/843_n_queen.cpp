#include <iostream>
#include <vector>
using namespace std;

/**
 * 使用DFS来做数字的全排列，DFS:回溯+剪枝
 * DFS：回溯的时候一定要恢复现场
*/
int n;
const int N = 20;
char g[N][N];
int row[N], path[N], col[N], dg[N], udg[N];

void dfs1(int u)
{
    if (u == n) // 类似于死胡同或者是递归边界
    {
        for (int i = 0; i < n; i++)
            cout << g[i] << endl;
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !dg[u + i] && !udg[n - u + i])
        {
            col[i] = dg[u + i] = udg[n - u + i] = true;
            g[u][i] = 'Q';
            dfs1(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false; // 恢复现场
            g[u][i] = '.';
        }
    }
}

void dfs2(int x, int y, int s)
{
    if (s > n)
        return;
    if (y == n) // 每一行的最后一列搜索完毕，开始下一行
    {
        x++;
        y = 0;
    }
    if (x == n) // 最后一行搜索完毕
    {
        if (s == n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << g[i][j];
                cout << endl;
            }
            cout << endl;
        }
        return;
    }

    // 不放皇后，继续下一层遍历
    g[x][y] = '.';
    dfs2(x, y + 1, s);

    // 这个格子可以放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        dfs2(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        g[x][y] = '.';
    }
}

int main()
{
    // int n = 4;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = '.';
        }
    }
    dfs1(0);
    // dfs2(0, 0, 0); //每行每列开始，先从左上角，
}
