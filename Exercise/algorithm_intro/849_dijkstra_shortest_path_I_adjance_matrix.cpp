#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 给定一个n个点m条边的有向图，图中可能存在重边和自环，所有边权均为正值。
 * 请你求出1号点到n号点的最短距离，如果无法从1号点走到n号点，则输出-1
 * 使用邻接矩阵来做
*/
const int N = 510;
const int inf = 1e9;
int d[N];
bool visited[N];
int n, m;
int g[N][N];
int dijkstra()
{
    fill(d, d + N, inf);
    d[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = inf;
        for (int j = 1; j <= n; j++)
        {
            if (visited[j] == false && d[j] < MIN)
            {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1)
            return -1;
        visited[u] = true;
        for (int v = 1; v <= n; v++)
        {
            if (visited[i] == false && g[u][v] != inf && d[u] + g[u][v] < d[v])
            {
                d[v] = g[u][v] + d[u];
            }
        }
        if (d[n] == inf)
            return -1;
        return d[n];
    }
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    cout << dijkstra() << endl;
    /**
     * 输入如下：
     * 3 3
     * 1 2 2
     * 2 3 1
     * 1 3 4
     * 输出如下：
     * 3
    */
}