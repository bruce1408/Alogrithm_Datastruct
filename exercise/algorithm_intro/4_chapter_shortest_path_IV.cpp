#include <iostream>
#include <vector>
using namespace std;
const int N = 510;
const int inf = 1e9;

int n, m, s, t;
int g[N][N], cost[N][N], c[N], d[N], pre[N];
bool visited[N];

void dijkstra(int s)
{
    fill(d, d + N, inf);
    fill(c, c + N, 0);
    d[s] = 0;
    c[s] = 0;
    for (int i = 0; i < n; i++)
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
        visited[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (visited[v] == false && g[u][v] != inf)
            {
                if (d[u] + g[u][v] < d[v])
                {
                    d[v] = d[u] + g[u][v];
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                }
                else if (d[u] + g[u][v] == d[v])
                {
                    if (c[u] + cost[u][v] < c[v])
                    {
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

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
    cin >> n >> m >> s >> t;
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