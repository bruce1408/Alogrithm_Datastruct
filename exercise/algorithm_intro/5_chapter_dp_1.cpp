#include <iostream>
using namespace std;
/**
 * 有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
 * 第 i 件物品的体积是 vi，价值是 wi。
 * 求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
 * 输出最大价值。
*/
const int N = 1005;
int w[N];    // 重量
int v[N];    // 价值
int f[N][N]; // f[i][j], j重量下前i个物品的最大价值

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            //  当前重量装不进，价值等于前i-1个物品
            if (j < w[i])
                f[i][j] = f[i - 1][j];
            // 能装，需判断
            else
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
        }

    cout << f[n][m] << endl;
    return 0;
}
