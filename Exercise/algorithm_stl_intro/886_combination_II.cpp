#include <iostream>
using namespace std;

const int N = 100010;
const int mod = 1e9 + 7;

typedef long long LL;

int fact[N], infact[N];
/**
 * 组合数II求解，取模mod
 * 主要是用逆元来求解阶乘运算
*/
// 符合费马小定理求逆元,为a^p-2, 使用快速幂来求解
int inv(int a, int b, int p)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = (LL)ans * a % p; // 转化成long long
        a = (LL)a * a % p;
        b >>= 1;
    }
    return ans;
}

int main()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = i * (LL)fact[i - 1] % mod; // 数据范范围long long
        infact[i] = (LL)infact[i - 1] * inv(i, mod - 2, mod) % mod;
    }

    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        // 提前对两个求模，不然会溢出
        printf("%d\n", (LL)fact[a] * infact[b] % mod * infact[a - b] % mod);
    }
}