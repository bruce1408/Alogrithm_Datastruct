#include<iostream>
using namespace std;

const int N = 100010;
const int mod = 1e9+7;

typedef long long LL;

int fact[N], infact[N];

// 费马小定理求逆元, 使用快速幂来求解
int inv(int a, int b, int p)
{
    int ans = 1;
    while(b>0)
    {
        if(b&1)  ans = (LL)ans * a % p;
        a = (LL)a * a % p;
        b>>=1;
    }
    return ans;
}

int main()
{
    fact[0] = infact[0] = 1;
    for(int i=1;i<N;i++)
    {
        fact[i] = i * (LL)fact[i-1] % mod;
        infact[i] = (LL)infact[i-1] * inv(i, mod-2, mod) % mod;
    }
    
    int n;
    cin>>n;
    while(n--)
    {
        int a, b;
        cin>>a>>b;
        printf("%d\n", (LL)fact[a]*infact[b]%mod * infact[a-b] % mod);
    }
}