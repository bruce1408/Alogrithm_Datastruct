#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 510;
const int inf = 10e9; // 设置一个很大值用来初始化节点的邻接矩阵

int n, m;
int g[N][N];
int dis[N];
bool visited[N];

/**
 * 方法 1
 * 最短路径问题，由于是稠密图，所以使用邻接矩阵来做，然后初始化为最大值
*/
int dijkstra()
{
    fill(dis, dis + N, inf);    // 使用fill函数把数组dis整个值赋值为最大值inf
    dis[1] = 0;                 // 节点1到达自身的距离为0
    for (int i = 0; i < n; i++) // 循环n次，n个节点
    {
        int u = -1, MIN = inf; // u使得d[u] 最小，MIN存放该最小的d[u];
        // 从1开始是因为节点范围是1-n, 这层循环是使u=dis[u]最小的还未被访问的顶点的标号，找到未访问的最小d[u]对应的节点
        for (int j = 1; j <= n; j++)
        {
            if (visited[j] == false && dis[j] < MIN)
            {
                MIN = dis[j];
                u = j;
            }
        }
        if (u == -1) // 找不到小于inf距离的节点u，那么说明剩下的顶点和起点不连通
            return -1;
        visited[u] = true; // 节点u已经被访问
        for (int v = 1; v <= n; v++)
        {
            // 如果v未被访问&&u能到达v&&u到达v的距离+起点到u的距离d[u]<起点到v的距离d[v] 那么就更新dis[v]
            if (visited[v] == false && g[u][v] != inf && dis[u] + g[u][v] < dis[v])
            {
                dis[v] = g[u][v] + dis[u]; // 更新优化dis[v]
            }
        }
    }
    if (dis[n] == inf)
        return -1;
    return dis[n];
}

/**
 * 方法 2，使用模板来做，思路和上面都一样
*/
int dijkstra()
{
    memset(dis, 0x3f, sizeof dis);
    dist[1] = 0;

    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!visited[j] && (t == -1 || dis[t] > dis[j]))
                t = j;

        for (int j = 1; j <= n; j++)
            dis[j] = min(dis[j], dis[t] + g[t][j]);
        visited[t] = true;
    }

    if (dis[n] == 0x3f3f3f3f)
        return -1;
    return dis[n];
}

int main()
{
    cin >> n >> m;
    fill(g[0], g[0] + N * N, inf);
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    cout << dijkstra() << endl;
}
