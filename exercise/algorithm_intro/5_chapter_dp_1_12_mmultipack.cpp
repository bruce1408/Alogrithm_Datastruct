#include <iostream>
using namespace std;

const int N = 1010;
int n, m;
int v[N], w[N];
int f[N][N];

/**
 * 多重背包问题，背包的数量有限，假设是si个 
*/

/**
 * 方法 1，使用朴素做法，时间复杂度较高，和完全背包问题基本类似
*/
void totalpack1()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k * v[i] <= j && k <=v[i]; k++)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + w[i] * k);
            }
        }
    }
    cout << f[n][m];
}

/**
 * 方法 2，使用优化，二进制优化拆分成0-1背包问题
*/
void totalpack2()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
    }
    cout << f[n][m];
}

/**
 * 方法 3，优化为一维数组
*/
void totalpack2()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
    cout << f[m] << endl;
}