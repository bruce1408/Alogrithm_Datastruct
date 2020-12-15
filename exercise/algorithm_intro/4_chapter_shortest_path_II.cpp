#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 迪杰斯塔拉算法升级版本
 * 如果不是单纯的求最短路径，可能还要求存在两条以上的最短路径，那么怎么选择：
 * 这里分三种情况，这几种情况都需要一个新数组来存放然后优化d[v]的时候相应的改动即可
 * 1、每条边增加边权，比如花费，要求存在多条最短路径上求出花费之和最小
 *      如果是新增边权的话，那么新增一个数组cost[u][v]表示从节点u-v的花费，然后再新增一个数组c，c[u]表示从起点s到顶点u的最少花费
 *      初始化的时候，c[s] = 0, 其余均为inf,在更新d[v]的时候c[u] + cost[u][v] < c[v] 那么姐更新c[v]即可
 * 
 * 2、每个点增加点权，比如城市可以收集到的物资
 *      如果是新增点权表示城市中可以收集到的物资，那么weight[u]表示城市u中的物资数目，新数组w[u]表示从起点s到达u这个顶点可以收集到的物资数目
 *      初始化的时候，w[s] = weight[s], 其余为0，在更新d[v]的时候w[v] < weight[v] + w[u] 更新代码w[v]
 *      
 * 3、直接问最短路径的条数
 *      需要增加一个新的数组num，表示从起点s到顶点u的最短路径条数用num[u]表示，
 * 
*/
const int N = 510;
const int inf = 10e9;
int n, m, s, t;
int g[N][N], w[N], num[N], d[N], weight[N]; // weight 表示城市i中的物资数目，w[i]表示从起点到i这个城市可以收集到的最大物资
bool visited[N];

void dijkstra()
{
    fill(num, num + N, 0);
    fill(d, d + N, inf);
    fill(w, w + N, 0);
    d[0] = 0;
    w[0] = weight[0];
    num[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = inf;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == false && d[j] < MIN)
            {
                MIN = d[j];
                u = j;
            }
        }
        visited[u] = true;
        for (v = 0; v < n; v++)
        {
            if (visited[v] == false && g[u][v] != inf)
            {
                if (d[u] + g[u][v] < d[v])
                {
                    d[v] = d[u] + g[u][v];
                    w[v] = weight[v] + w[u];
                }
                else if (d[v] == g[u][v] + d[u])
                {
                    if (w[v] < weight[v] + w[u])
                    {
                        w[v] = weight[v] + w[u];
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y >> z;
        g[y][x] = g[x][y] = z;
    }

    dijkstra();
    cout << num[t] << " " << w[t] << endl;
}
