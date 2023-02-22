#include <iostream>
using namespace std;

const int N = 110;
int n, m;
int v[N], w[N], s[N];
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
        cin >> v[i] >> w[i]>>s[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k * v[i] <= j && k <=s[i]; k++)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + w[i] * k);
            }
        }
    }
    cout << f[n][m]<<endl;
}

/**
 * 方法 2，使用优化，二进制优化拆分成0-1背包问题
 * 对si物品，然后拆成log si，时间复杂度降低
*/
const int N = 25000, M = 2010;
int n, m;
int v[N], w[N];
int f[N];


void totalpack2()
{
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin>>a>>b>>s;
        int k= 1;
        while(k<=s)
        {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s-=k;
            k*=2;
        }
        if(s >0)
        {
            cnt++;
            v[cnt] = a*s;
            w[cnt] = b*s;
        }
    }
    n = cnt;
    for(int i=1;i<=n;i++)
    {
        for(int j = m;j>=v[i];j--)
        {
            f[j] = max(f[j], f[j-v[i]] + w[i]);
        }
    }
    cout<<f[m]<<endl;
}



