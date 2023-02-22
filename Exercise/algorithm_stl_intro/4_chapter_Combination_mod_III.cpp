#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
/**
 * 组合数的计算mod P的计算
 * 组合数的计算公式如下：
 *                   n!
 *    C(n, m) =  ---------- 
 *                m!(n-m)!
 * 主要用来计算组合数模一个数的结果
*/

/**
 * 方法 1递归计算
 * C(n,m) = C(n-1, m) + C(n-1, m-1)
 * 这个递推公式可以最后使得n或者是m变成相同或者是让m变为0，可以作为递推边界
*/
LL comb1(LL n, LL m)
{
    if (m == n || m == 0)
        return 1;
    return (comb1(n - 1, m) + comb1(n - 1, m - 1));
}

LL comb1mod(LL n, LL m, LL p)
{
    if (m == n || m == 0)
        return 1;
    return (comb1(n - 1, m) + comb1(n - 1, m - 1)) % p;
}

/**
 * 方法 2，类似菲波那切数列的情况，会重复计算很多数字，所以开一个数组，用来记录已经
 * 计算过的数字，如果下次再碰到就直接返回这个结果而不用重计算
 * 这里可以使用vector或者是全局数组都可以
*/
LL res[67][67];
LL comb2mod(LL n, LL m, int p)
{
    if (m == 0 || m == n)
        return 1;
    if (res[n][m] != 0)
        return res[n][m];
    return res[n][m] = (comb1(n - 1, m) + comb1(n - 1, m - 1)) % p;
}

/**
 * 方法 3，根据定义来做
 * 使用快速幂+质因子的办法
 * 计算C(n, m) % p;
*/
const int N = 1e6;
int prime[N];

// cal函数用来求解n的阶乘的质因子数为p的个数，不是n
int cal(LL n, LL p)
{
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int temp = i;
        while (temp % p == 0)
        {
            temp /= p;
            ans++;
        }
    }
    return ans;
}

LL binaryPow(int a, int b, int c)
{
    LL ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % c;
        b >>= 1;
        a = a * a % c;
    }
    return ans;
}

LL comb3mod(int n, int m, int p)
{
    LL ans = 1;
    // 遍历不超过所有n的指数质数
    for (LL i = 0; prime[i] <= n; i++)
    {
        // 计算C(n,m)中prime[i]的指数c，cal(n, k)为n!含有质因子k的个数
        int c = cal(n, prime[i]) - cal(m, prime[i]) - cal(n - m, prime[i]);
        // 快速幂计算prime[i]^c%p
        ans = ans * binaryPow(prime[i], c, p) % p;
    }
    return ans;
}
/**
 * 方法 4，使用定义式的变形来计算
*/
LL comb4mod(int n, int m, int p)
{
    int ans =1;
    for(int i = 1;i<=m;i++)
    {
        ans = ans * (n-m+i) % p;
        ans = ans * inverse(i, p) % p;
    }
    return ans;
}

int main()
{
    int n = 4, m = 2, p = 5; // 这个数据范围使用定义法会越界，
    // cout << comb2mod(n, m, p) << endl;
    cout << comb3mod(n, m, p) << endl;

    // vector<vector<int>> res(67, vector<int>(67, 0));
    // cout << comb2(n, m, res) << endl;
}