#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

/**
 * SPFA算法，是对bellman-ford算法的优化
 * 因为bellman是每次都要遍历m条边，这样显然还有大量的无意义的操作，所以只有当
 * 某个顶点u的d[u]改变的时候，从它出发点邻接点v的d[v]值才可能会发生变化。
 * 所以可以优化，使用队列，每次队首元素顶点u取出，然后对队首元素从u出发的所有边u->v进行松弛操作
 * 判断是否d[u] + w[u->v] < d[v]是否成立，如果成立那么就覆盖更新，此时如果v不在队列中，那么把v加入队列，这样操作
 * 直到队列为空。
 * 使用邻接表+队列来优化
*/
int n, m;
const int N = 100010;
const int inf = 1e8;
int h[N], e[N], ne[N], d[N], idx, w[N];
bool visited[N];
queue<int> q;

void add_n(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

int spfa()
{
    fill(d, d + N, inf);
    d[1] = 0;
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        visited[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[t] + w[i] < d[j])
            {
                d[j] = d[t] + w[i];
                if (visited[j] == false)
                {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }
    if (d[n] == inf)
        return -1;
    else
        return d[n];
}

int main()
{
    fill(h, h + N, -1);
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add_n(a, b, c);
    }
    int t = spfa();
    if (t == -1)
        cout << "impossible" << endl;
    else
        cout << t << endl;
}