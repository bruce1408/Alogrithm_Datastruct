#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

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