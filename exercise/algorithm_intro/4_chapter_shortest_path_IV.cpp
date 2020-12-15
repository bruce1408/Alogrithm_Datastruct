#include <iostream>
#include <vector>
using namespace std;
const int N = 510;
const int inf = 1e9;

int n, m, s, t;
int g[N][N], cost[N][N], d[N];
bool visited[N];
vector<int> pre[N];

void dijkstra(int s)
{
    fill(d, d + N, inf);
    d[s] = 0;
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
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (d[u] + g[u][v] == d[v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int main()
{
    // cin >> n >> m >> s >> t;
    // fill(g[0], g[0] + N * N, inf);
    // while (m--)
    // {
    //     int a, b, c, d;
    //     cin >> a >> b >> c >> d;
    //     g[a][b] = g[b][a] = c;
    // }
    // dijkstra(0);
    // cout << "最短路径为:" << endl;
    // cout << endl;
    // cout << "起点到该点的最短路径长度为: " << d[t] << endl;
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
    vector<int> res[3];
    res[0].push_back(0);
    res[1].push_back(3);
    res[1].push_back(4);
    res[2].push_back(5);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}