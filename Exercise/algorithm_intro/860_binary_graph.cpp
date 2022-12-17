#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
const int N = 100010, M = 200020;
int h[N], e[M], ne[M], idx;
int color[N];

void add_n(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int u, int c)
{
    color[u] = c;

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!color[j])
        {
            if (!dfs(j, 3 - c))
                return false;
        }
        else if (color[j] == c)
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    fill(h, h + N, -1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add_n(a, b);
        add_n(b, a);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (!color[i])
        {
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
