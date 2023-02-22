#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
const int N = 210, inf = 1e8;
int d[N][N];
/**
 * 解决全源最短路问题,使用多源汇最短路，就是任意两点u和v之间的最短路径长度。时间复杂度O(n^3)
 * 如果存在顶点k，是的k 作为中介点是顶点i和j的当前最短距离缩短，
 * 则使用顶点k作为顶点i和j的中介点，即d[i][k] + d[k][j] < d[i][j]时，那么更新d[i][j] 
*/
void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}
int main()
{

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = inf;
        }
    }
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    floyd();
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        if (d[a][b] > inf / 2)
            cout << "impossible" << endl;
        else
            cout << d[a][b] << endl;
    }
}