#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20;
int f[N][N], dp[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> f[i][j];
        }
    }
    // 最后一层的所有数字都是等于f值，也是边界
    for (int j = 1; j <= n; j++)
        dp[n][j] = f[n][j];

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j];
        }
    }
    printf("%d\n", dp[1][1]);

    /**
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
}