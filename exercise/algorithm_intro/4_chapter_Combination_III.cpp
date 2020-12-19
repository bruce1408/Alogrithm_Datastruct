#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
/**
 * 组合数的计算mod P的计算
 * 组合数的计算公式如下：
 *      m       n!
 *    C n =  --------- 
 *            m!(n-m)!
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
 * 方法 3，类似菲波那切数列的情况，会重复计算很多数字，所以开一个数组，用来记录已经
 * 计算过的数字，如果下次再碰到就直接返回这个结果而不用重计算
 * 这里可以使用vector或者是全局数组都可以
*/
// LL res[67][67];
LL comb3(LL n, LL m, vector<vector<int>> &res)
{
    if (m == 0 || m == n)
        return 1;
    if (res[n][m] != 0)
        return res[n][m];
    return res[n][m] = comb3(n - 1, m, res) + comb3(n - 1, m - 1, res);
}

/**
 * 方法 4，递推公式展开计算
*/
LL comb4(LL n, LL m)
{
    LL ans = 1;
    for (LL i = 1; i <= m; i++)
    {
        ans = ans * (n - m + i) / i;
    }
    return ans;
}
int main()
{
    int n = 4, m = 2, p = 5; // 这个数据范围使用定义法会越界，
    cout << comb1mod(n, m, p) << endl;
    vector<vector<int>> res(67, vector<int>(67, 0));
    // cout << comb2(n, m, res) << endl;
    // cout << comb4(n, m) << endl;
}