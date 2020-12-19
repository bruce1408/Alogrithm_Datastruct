#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
/**
 * 组合数的计算
 * 组合数的计算公式如下：
 *      m       n!
 *    C n =  --------- 
 *            m!(n-m)!
 * 由公式可知上面的式子是通过3个整数的阶乘得到的
 * 一般有三种算法可以计算，定义直接计算法、递推公式计算法、定义式变形计算法
*/

/**
 * 方法 1，定义直接计算法
 * 先计算n！，然后再计算(n-m)!和m!, 使用long long 数据范围是小于等于20不会越界，否则会发生越界
*/
LL comb(LL n, LL m)
{
    LL ans1 = 1;
    for (LL i = 1; i <= n; i++)
    {
        ans1 *= i;
    }
    for (LL i = 1; i <= m; i++)
    {
        ans1 /= i;
    }
    for (LL i = 1; i <= (n - m); i++)
    {
        ans1 /= i;
    }
    return ans1;
}

/**
 * 方法 2，递推公式来计算
 * C(n,m) = C(n-1, m) + C(n-1, m-1)
 * 这个递推公式可以最后使得n或者是m变成相同或者是让m变为0，可以作为递推边界
*/
LL comb1(LL n, LL m)
{
    if (m == n || m == 0)
        return 1;
    return comb1(n - 1, m) + comb1(n - 1, m - 1);
}

/**
 * 方法 3，类似菲波那切数列的情况，会重复计算很多数字，所以开一个数组，用来记录已经
 * 计算过的数字，如果下次再碰到就直接返回这个结果而不用重计算
 * 这里可以使用vector或者是全局数组都可以
*/
// LL res[67][67];
LL comb2(LL n, LL m, vector<vector<int>> &res)
{
    if (m == 0 || m == n)
        return 1;
    if (res[n][m] != 0)
        return res[n][m];
    return res[n][m] = comb2(n - 1, m, res) + comb2(n - 1, m - 1, res);
}

int main()
{
    int n = 21, m = 10; // 这个数据范围使用定义法会越界，
    // cout<<comb1(n, m)<<endl;
    vector<vector<int>> res(67, vector<int>(67, 0));
    cout << comb2(n, m, res) << endl;
}