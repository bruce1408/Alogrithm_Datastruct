#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
/**
 * 使用spfa算法来判断是否有负环
 * 这里新加一个数组cnt，表示当前这个点的最短路的边数，如果cnt[x]>=n，说明至少经过了n条边，那么就有n+1个点，而对于n个节点
 * 显然存在两个相同的节点，那么就存在一个负环
 * 这里的负环可能不是从起点开始，所以要判断每个节点，
 * cnt[i] 表示的是当前以 i 结尾的最短路的长度，
 * 不会因为把所有点都入队了就反复加的。所有点都被压入队所造成的结果，只是以 i 结尾的最短路的起点可能是任意一点，不一定是1号点。
*/
int n, m;
const int N = 100010;
const int inf = 1e8;
int h[N], e[N], ne[N], d[N], idx, w[N];
int cnt[N];
bool visited[N];

void add_n(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

bool spfa()
{
    queue<int> q;
    fill(d, d + N, inf);
    d[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
        visited[i] = true;
    }
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
                cnt[j] = cnt[t] + 1;
                d[j] = d[t] + w[i];
                // 如果超过了n-1
                // 根据抽屉原理，说明经过某个节点两次，则说明有环
                if (cnt[j] >= n)
                    return true;
                if (visited[j] == false)
                {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }
    return false;
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
    bool t = spfa();
    if (t)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}