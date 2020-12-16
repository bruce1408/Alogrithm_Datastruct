#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, k;
const int N = 510;
const int inf = 1e9,  M = 10010;
int d[N], back[N];

struct node
{
    int a, b, c;
    // node(int x, int y, int z) : a(x), b(y), c(z) {}
}edge[M];

int bellman_ford()
{
    fill(d, d + N, inf);
    d[1] = 0;
    for (int i = 0; i < k; i++)
    {
        memcpy(back, d, sizeof d);
        for (int j = 0; j < m; j++)
        {
            int a = edge[j].a, b = edge[j].b, c = edge[j].c;
            if (back[a] + c < d[b])
            {
                d[b] = back[a] + c;
            }
        }
    }
    if (d[n] > inf / 2)
        return -1;
    else
        return d[n];
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a1, b1, c1;
        cin>>a1>>b1>>c1;
        edge[i] = {a1, b1, c1};
    }
    int s = bellman_ford();
    if(s==-1) cout<<"impossible"<<endl;
    else cout<<s<<endl;
}