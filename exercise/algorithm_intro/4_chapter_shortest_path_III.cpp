#include <iostream>
#include <vector>
using namespace std;
const int N = 510;
const int inf = 10e9;

int n, m, s, t;
int g[N][N], cost[N][N], c[N], d[N], pre[N];


int main()
{
    cin >> n >> m >> s >> t;
    while (m--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a][b] = g[b][a] = c;
        cost[a][b] = cost[b][a] = d;
    }
    dijkstra();
    dfs();
    cout << d[t] << " " << c[t] << endl;
}