#include <iostream>
#include <vector>
using namespace std;
const int N = 510;
const int inf = 1e9;

int n, m, s, t;
// cost[u][v]表示从u到v点花费矩阵，d[u]表示起点到u这个点的最短路径，c[u]表示起点到u这个点的最小花费
int g[N][N], cost[N][N], c[N], d[N], pre[N];
bool visited[N];

void dijkstra(int s) // s表示起点
{
    fill(d, d + N, inf);        // 初始化d距离矩阵，设置为inf
    fill(c, c + N, 0);          //最小化费设置为0
    d[s] = 0;                   // 起点s到达自身的距离设置为0
    c[s] = 0;                   // 起点s到达自身的花费为0
    for (int i = 0; i < n; i++) // 初始化pre数组的每个点的前驱为自身
        pre[i] = i;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = inf;
        // 未被访问的节点中找到距离最短的节点
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == false && d[j] < MIN)
            {
                MIN = d[j];
                u = j;
            }
        }
        visited[u] = true; // 标记u为已访问
        for (int v = 0; v < n; v++)
        {
            if (visited[v] == false && g[u][v] != inf) // 如果v未能访问 && u能到达v
            {
                if (d[u] + g[u][v] < d[v])
                {
                    d[v] = d[u] + g[u][v];    // 优化d[v]
                    c[v] = c[u] + cost[u][v]; // 优化c[v]
                    pre[v] = u;               // v的前驱设置为u
                }
                else if (d[u] + g[u][v] == d[v])
                {
                    if (c[u] + cost[u][v] < c[v])
                    {
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u; // v的前驱设置为u
                    }
                }
            }
        }
    }
}

/**
 * 打印路径
*/
void dfs(int s, int t)
{
    if (s == t)
    {
        cout << t << " ";
        return;
    }
    else
    {
        dfs(s, pre[t]);
        cout << t << " ";
    }
}

int main()
{
    cin >> n >> m >> s >> t; // 设置n表示节点数目0~n-1，m表示边的数目，s表示起点，t表示终点
    fill(g[0], g[0] + N * N, inf);
    while (m--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a][b] = g[b][a] = c;
        cost[a][b] = cost[b][a] = d;
    }
    dijkstra(0);
    cout << "最短路径为:" << endl;
    dfs(s, t);
    cout << endl;
    cout << "起点到该点的最短路径长度为: " << d[t] << endl;
    cout << "花费代价最小为: " << c[t] << endl;
    /**
     * 输入如下：
     *  4 5 0 3
     * 0 1 1 20
     * 1 3 2 30
     * 0 3 4 10 
     * 0 2 2 20
     * 2 3 1 20
     * 
     * 输出结果0 2 3
     * 3
     * 40
    */
}