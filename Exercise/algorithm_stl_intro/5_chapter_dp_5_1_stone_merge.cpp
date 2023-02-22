#include <iostream>
using namespace std;
/**
 * 282 石子合并，区间DP
*/
const int N = 310;
int f[N][N];
int n;
int s[N];

/**
 * 方法 1，使用区间dp，然后枚举长度，在枚举区间的端点
*/
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    // 前缀和后面需要计算
    for (int i = 1; i <= n; i++)
        s[i] += s[i - 1];

    // 先循环区间长度，然后再循环左右端点
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int l = i, r = i + len - 1;
            f[l][r] = 1e9; // f[l][r] 初始化为最大
            // k不能取右边，否则右边就不存在了
            for (int k = l; k < r; k++)
            {
                // 不包含最后合并的那一步，所以要加上从i到j的和，使用前缀和来做即可
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    cout << f[1][n];
}