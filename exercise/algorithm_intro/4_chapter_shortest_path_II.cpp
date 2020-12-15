#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 迪杰斯塔拉算法升级版本
 * 如果不是单纯的求最短路径，可能还要求存在两条以上的最短路径，那么怎么选择：
 * 这里分三种情况，这几种情况都需要一个新数组来存放然后优化d[v]的时候相应的改动即可：
 * 
 * 1、每条边增加边权，比如花费，要求存在多条最短路径上求出花费之和最小
 *      如果是新增边权的话，那么新增一个数组cost[u][v]表示从节点u到v的花费，然后再新增一个数组c，c[u]表示从起点s到顶点u的最少花费
 *      初始化的时候，c[s] = 0, 其余均为inf,在更新d[v]的时候c[u] + cost[u][v] < c[v] 那么姐更新c[v]即可
 *      for(int i=0;i<n;i++)
 *      {
 *          if(visited[v]==false && g[u][v] !=inf)
 *          {
 *              if(d[u] + g[u][v] < d[v])
 *              {
 *                  d[v] = d[u] + g[u][v];
 *                  c[v] = c[u] + cost[u][v];
 *              }
 *              else if(d[u] + g[u][v] ==d[v] && c[u] + cost[u][v] < c[v])
 *              {
 *                  c[v] = c[u] + cost[u][v];
 *              }
 *          }
 *      }
 * 
 * 2、每个点增加点权，比如城市可以收集到的物资
 *      如果是新增点权表示城市中可以收集到的物资，那么weight[u]表示城市u中的物资数目，新数组w[u]表示从起点s到达u这个顶点可以收集到的物资数目
 *      初始化的时候，w[s] = weight[s], 其余为0，在更新d[v]的时候w[v] < weight[v] + w[u] 更新代码w[v]
 *      for(int i=0; i<n; i++)
 *      {
 *          if(visited[v]==false && g[u][v] !=inf)
 *          {
 *              if(d[u] + g[u][v] < d[v])
 *              {
 *                  d[v] = d[u] + g[u][v];
 *                  w[v] = w[u] + weight[v];
 *              }
 *              else if(d[u] + g[u][v] ==d[v] && w[u] + weight[v] > w[v])
 *              {
 *                  w[v] = w[u] + weight[v];
 *              }
 *          }
 *      }
 *      
 * 3、直接问最短路径的条数
 *      需要增加一个新的数组num，表示从起点s到顶点u的最短路径条数用num[u]表示，初始化num[s]为1，其余均为0，这样在更新d[v]的时候可以更新num
 *      当d[u]+g[u][v] < d[v]的时候，num[v] = num[u],集成num[u],而当d[u] + g[u][v] = d[v]距离相同的时候，num[v] += num[u]
 *      for(int i=0; i<n; i++)
 *      {
 *          if(visited[v]==false && g[u][v] !=inf)
 *          {
 *              if(d[u] + g[u][v] < d[v])
 *              {
 *                  d[v] = d[u] + g[u][v];
 *                  num[v] = num[u];
 *              }
 *              else if(d[u] + g[u][v] ==d[v])
 *              {
 *                  num[v] += num[u];
 *              }
 *          }
 *      }
 * 
*/
const int N = 510;
const int inf = 10e9;
int n, m, s, t;
/**
 * weight 表示城市i中的物资数目，
 * w[i]表示从起点s到i这个城市可以收集到的最大物资，初始化为w[s] = weight[s]起始节点，其余节点为0；
 * weight[u]表示当前节点u这个城市所拥有的物资数目，这个题目初始设定
 * num[u]表示从起点s开始到u这个节点的最短路径条数，初始化num[s]起始节点=1，然后其余节点为0
 * */
int g[N][N], w[N], num[N], d[N], weight[N];
bool visited[N]={false};

void dijkstra()
{
    fill(num, num + N, 0); // 初始化为0
    fill(d, d + N, inf);   // 初始化为最大值
    fill(w, w + N, 0);     // 初始化为0
    d[0] = 0;              // 因为节点范围从0-n,所以起始节点0设置距离为0
    w[0] = weight[0];      // w起始节点设置为0号节点的点权
    num[0] = 1;            // 0号节点的最短路径条数
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = inf;
        for (int j = 0; j < n; j++) // 找到未被访问节点当中距离最短的那个节点
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
            if (visited[v] == false && g[u][v] != inf) // v未被访问 && u能到达v && 从u为中介的点可以是d[v]更优
            {
                if (d[u] + g[u][v] < d[v]) // 以u为中介的点能令v变得更小就更新
                {
                    d[v] = d[u] + g[u][v];   // 更新d[v]
                    w[v] = weight[v] + w[u]; // 更新w[v]
                    num[v] = num[u];         // 更新num[v]
                }
                else if (d[v] == g[u][v] + d[u]) // 找到一条相同路径的长度
                {
                    if (w[v] < weight[v] + w[u]) // 如果以u为中介点的点权和更大那么就更新w[v]
                    {
                        w[v] = weight[v] + w[u];
                    }
                    num[v] += num[u]; // 最短路径条数和点权无关，必须写在外面
                }
            }
        }
    }
}

int main()
{
    fill(g[0], g[0] + N*N, inf);
    cin >> n >> m >> s >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[y][x] = g[x][y] = z;
    }
    dijkstra();
    cout << num[t] << " " << w[t] << endl;
}
