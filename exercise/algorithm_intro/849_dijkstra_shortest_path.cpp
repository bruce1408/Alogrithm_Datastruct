#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 510;
const int inf = 1e9;
int d[N];
bool visited[N];
int n, m;
int g[N][N];
int dijkstra()
{
    fill(d, d + N, inf);
    d[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = inf;
        for (int j = 1; j <= n; j++)
        {
            if (visited[j] == false && d[j] < MIN)
            {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1)
            return -1;
        visited[u] = true;
        for (int v = 1; v <= n; v++)
        {
            if (visited[i] == false && g[u][v] != inf && d[u] + g[u][v] < d[v])
            {
                d[v] = g[u][v] + d[u];
            }
        }
        if (d[n] == inf)
            return -1;
        return d[n];
    }
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    cout << dijkstra() << endl;
}