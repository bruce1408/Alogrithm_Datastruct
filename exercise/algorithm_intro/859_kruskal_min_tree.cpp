#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
const int N = 100010;
const int inf = 1e9;
int g[N][N], d[N];
bool visited[N];

int kruskal()
{
        
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(c, g[a][b]);
    }
}