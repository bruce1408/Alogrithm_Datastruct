#include <iostream>
using namespace std;
typedef long long LL;
const int N = 2010;
const int mod = 1e9 + 7;
/**
 * 求解组合数
*/
// 两种写法，第一种写法，保存之前计算过的每个值到res数组中
int res[N][N] = {0};
LL comb(int n, int m)
{
    if (m == 0 || m == n)
        return 1;
    if (res[n][m] != 0)
        return res[n][m];
    return res[n][m] = (comb(n - 1, m) + comb(n - 1, m - 1)) % mod;
}

// 第二种写法
int c[N][N];
void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}

int main()
{
    init();
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << c[a][b] << endl;

        // cout<<comb(a, b)<<endl; // 第一种提交方式
    }
}
