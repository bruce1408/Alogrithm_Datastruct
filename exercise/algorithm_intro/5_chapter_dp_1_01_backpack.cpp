#include <iostream>
using namespace std;
/**
 * 0-1背包问题
 * 有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
 * 第 i 件物品的体积是 vi，价值是 wi。
 * 求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
 * 输出最大价值。
*/
const int N = 1005;
int w[N];    // 重量
int c[N];    // 价值
int f[N][N]; // f[i][j], j重量下前i个物品的最大价值

/**
 * 写法 1,
*/
void backpack1()
{
    int n = 5, m = 8; // n=5表示背包数量，m=8表示背包容纳的总重量，
    cin >> n >> m;
    // 计算所有的状态
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> c[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            // 当前重量装不进，价值等于前i-1个物品
            f[i][j] = f[i - 1][j];
            // 能装wi物品的时候，找出最大值
            if (j >= w[i])
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + c[i]);
        }

    cout << f[n][m] << endl;
}

/**
 * 写法 2；二维优化为一维；
 * i只和i-1相关，使用滚动数组的思想简化为一维，然后在进行计算，
 * 
 */
void backpack2()
{
    int n, m; // n=5表示物品数量，m=8表示背包容纳的总重量，
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> c[i];

    // 因为每个i都依赖于前面一个i-1，所以使用滚动数组的方式简化i，然后化简
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= w[i]; j--)
        {
            f[j] = max(f[j], f[j - w[i]] + c[i]);
        }
    }

    cout << f[m] << endl;
}



int main()
{
    backpack1();
}