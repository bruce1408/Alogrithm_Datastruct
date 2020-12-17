#include <iostream>
#include <algorithm>
int n, m;
const int inf = 1e9;
const int N = 510;
int d[N], g[N][N];
bool visited[N];
using namespace std;

int floyd()
{
    fill(d, d+N, inf);
    for(int i=1;i<=n;i++)
    {
        
    }
}

int main()
{
    fill(g[0], g[0] + N * N, inf);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    int t = floyd();
    if(t==-1) cout<<"impossible"<<endl;
    else cout<<t<<endl;
}