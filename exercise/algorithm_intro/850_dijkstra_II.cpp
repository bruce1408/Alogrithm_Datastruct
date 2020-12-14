#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e6+10;
const int inf = 10e9; // 设置一个很大值用来初始化节点的邻接矩阵

int n, m;
int g[N][N];
int dis[N];
bool visited[N];
typedef pair<int, int> PII;
int e[N], ne[N], w[N], h[N], idx;

/**
 * 方法 1
 * 最短路径问题，由于是稠密图，所以使用邻接矩阵来做，然后初始化为最大值
*/

/**
 * 打印出最短路径是多少
*/

void add_n(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

void dfs(int s, int t)
{
    if (s == t) //如果当前已经到达了起点s，那么就输出起点并返回即可
    {
        cout << t << " ";
        return;
    }
    else
    {
        dfs(s, pre[t]);   // 递归访问v的前驱节点pre[v]
        cout << t << " "; // 从最深处return之后，输出每一层的顶点号
    }
}

int dijkstra()
{
    fill(dis, dis + N, inf); // 使用fill函数把数组dis整个值赋值为最大值inf
    dis[1] = 0;              // 节点1到达自身的距离为0
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});          // 1号编号的点的距离是0
    while(heap.size()) // 循环n次，n个节点
    {
        auto t = heap.top(); // 取出队头元素
        heap.pop();
        int ind = t.second, distance = t.first;
        if(visited[ind]) continue;
        visited[ind] = true;

        // 从1开始是因为节点范围是1-n, 这层循环是使u=dis[u]最小的还未被访问的顶点的标号，找到未访问的最小d[u]对应的节点
        for (int i= h[ind], i!=-1;i++)
        {
            int j = e[i];
            if (visited[j] == false && dis[j] > dis[ind] + w[i])
            {
                dis[j] = dis[ind] + w[i];
                heap.push({dis[j], j});
            }
        }
    }
    if (dis[n] == inf)
        return -1;
    return dis[n];
}


int main()
{
    cin >> n >> m;
    fill(h, h + N, -1);
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add_n(x, y, z);
    }
    cout << dijkstra() << endl;
}
