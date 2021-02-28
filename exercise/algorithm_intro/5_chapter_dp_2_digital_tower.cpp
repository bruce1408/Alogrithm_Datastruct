#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20;
int a[N][N], f[N][N];
/**
 * 数塔问题：
 * 所谓数塔问题就是把一些数字按照金字塔排列开来，
 * 第一行一个数字，
 * 第二行两个数字
 * 第三行三个数字
 * ...
 *  
 * 输入
 * 5
 * 5
 * 8 3
 * 12 7 16
 * 4 10 11 6
 * 9 5 3 9 4
 * 输出
 * 44 
 */
 * 以此类推,用f[i][j]表示i行第j个数字
 * 现在从第一层走到第n层，然后每次只能向下走一层连接的两个数字中的一个
 * 最后需要把所有数字相加后得到和最大的输出即可
 * 
 * 设置dp[i][j]表示从第i行第j个数字出发的到达最底层所有路径中能得到的最大和。
 * 最后一层就是dp[i][j] = f[i][j]
 * 如果需要求解dp[i][j]，那么一定要求出他的两个子问题
 * 
 * dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j];
*/
void triangle1()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    // 初始化数组dp，需要一个额外的dp数组来记录状态
    for (int j = 1; j <= n; j++)
        f[n][j] = a[n][j];

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
        }
    }
    printf("%d\n", dp[1][1]);
}

/**
 * 和上面的思路一样，都是从下到上来写，但是不需要额外的数组来记录状态
*/
void triangle2()
{
    cin>>n;
    for(int i= 1;i<=n;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            cin>>f[i][j];
        }
    }

    for(int i = n-1;i;i--)
    {
        for(int j= 1; j<=i;j++)
        {
            f[i][j] = max(f[i+1][j], f[i+1][j+1]) + f[i][j];
        }
    }

    cout<<f[1][1]<<endl;
}

/**
 * 方法 2，从上往下计算，不推荐算法，需要判断边界
*/
const int N = 510, INF = 1e9;
int n;
int a[N][N];
int f[N][N];

int main()
{
    cin>>n;
    for(int i = 1; i<=n;i++)
    {
        for(int j = 1; j<=i;j++)
        {
            cin>>a[i][j];
        }
    }
    
    for(int i = 0; i<=n;i++)
    {
        for(int j = 0;j<=i+1;j++)
            f[i][j] = -INF;
    }
    
    f[1][1] = a[1][1];w
    for(int i=2; i<=n; i++)
    {
        for(int j = 1; j<=i; j++)
        {
            f[i][j] = max(f[i-1][j], f[i-1][j-1] ) + a[i][j];
        }
    }

    int res = -INF;
    for(int i =1; i<=n;i++)
    {
        res = max(res, f[n][i]);
    }
    cout<<res<<endl;

}