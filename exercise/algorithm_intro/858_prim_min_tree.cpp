#include <iostream>
#include <algorithm>
int n, m;
const int inf = 1e9;
const int N = 510;
int d[N], g[N][N]; // d数组表示的是当前i到集合的最短距离
bool visited[N];
using namespace std;
/**
 * 最小生成树的代码和Dijkstra代码非常类似，但是也有不同的地方
 * 
*/
int prim()
{
    fill(d, d + N, inf);        // d[i]表示顶点到集合的最短距离，之前dijkstra表示的是起点到该点的最短距离有所不同
    d[1] = 0;                   // 1号节点到集合s的最短距离为0，其余都是inf
    int res = 0;                // 最小生成树边权之和
    for (int i = 0; i < n; i++) //循环n次
    {
        int u = -1, MIN = inf;       //u是的d[u]最小，MIN保存的是最小d[u]
        for (int j = 1; j <= n; j++) //找到未被访问的顶点中d[]最小
        {
            if (visited[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        // 找不到小于inf的d[u]，则剩下的顶点和集合s不通
        if (u == -1)
            return inf;
        visited[u] = true; // u节点以及被访问，加入到集合s中去
        res += d[u];       // 将于集合s最小的边加入到最小生成树中
        for (int v = 1; v <= n; v++)
        {
            // 如果v未被访问 && u能到达v && 以u为中介点可以使v离集合更近那么就更新
            if (visited[v] == false && g[u][v] != inf && g[u][v] < d[v])
            {
                d[v] = g[u][v]; // g[u][v]赋值给d[v]
            }
        }
    }
    return res;
}

int main()
{
    fill(g[0], g[0] + N * N, inf);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int t = prim();
    if (t == inf)
        cout << "impossible" << endl;
    else
        cout << t << endl;
}