#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, k;
const int N = 510;
const int inf = 1e9, M = 10010;
int d[N], back[N];

/**bellman_ford 算法用来针对出现负权边的情况，
 * 遍历n次，每次遍历m条边，然后用每一条边去更新起点到该节点的距离；
 * 结构体来保存两个节点之间的边权
*/
struct node
{
    int a, b, c;
} edge[M]; // M条边

int bellman_ford()
{
    fill(d, d + N, inf);
    d[1] = 0;
    for (int i = 0; i < k; i++) // k次遍历
    {
        memcpy(back, d, sizeof d); // 使用back数组，避免a里面更新为b，
        for (int j = 0; j < m; j++) // 遍历每条边
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
        cin >> a1 >> b1 >> c1;
        edge[i] = {a1, b1, c1};
    }
    int s = bellman_ford();
    if (s == -1)
        cout << "impossible" << endl;
    else
        cout << s << endl;
}