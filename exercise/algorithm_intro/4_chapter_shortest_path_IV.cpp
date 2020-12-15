#include <iostream>
#include <vector>
using namespace std;
const int N = 510;
const int inf = 1e9;

int n, m, s, t, minCost = inf;
int g[N][N], cost[N][N], d[N];
bool visited[N];
vector<int> pre[N], tempPath;

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
                    pre[v].clear();      // 清空pre[v]，如果当前中介点u可以使得d[v]更优，那么就清空pre数组，然后添加u这个数组
                    pre[v].push_back(u); // u为v的前驱，因为数组pre每次都会清空，所以pre不要求初始化
                }
                else if (d[u] + g[u][v] == d[v])
                {
                    pre[v].push_back(u); // 如果有相同的路径，那么就在原来的基础上添加u这个节点
                }
            }
        }
    }
}

/**
 * 上述pre保存的可能有多条最短路径，那么使用dfs来遍历，找出根据第二标尺的最优解
*/
void dfs(int v)
{
    if (v == s)
    {
        tempPath.push_back(v);
        int tempCost = 0;
        for (int i = tempPath.size() - 1; i > 0; i--)
        {
            int id = tempPath[i], idNext = tempPath[i - 1];
            tempCost += cost[id][idNext];
        }

        if (tempCost < minCost)
        {
            minCost = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) // 遍历v这个节点的所有前驱
    {
        dfs(pre[v][i]);
    }
    tempPath.pop_back();
}

int main()
{
    cin >> n >> m >> s >> t;
    fill(g[0], g[0] + N * N, inf);
    fill(cost[0], cost[0] + N * N, inf);
    while (m--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a][b] = g[b][a] = c;
    }
    dijkstra(0);
    dfs(t);
    cout << "最短路径为:" << minCost << endl;
    cout << endl;
    cout << "起点到该点的最短路径长度为: " << d[t] << endl;
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