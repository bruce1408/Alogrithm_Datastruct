#include <iostream>
#include <vector>
using namespace std;

/**
 * 70 爬楼梯
 * 给定一个整数n表示楼梯数，然后每次可以爬1格或者是2格
 * 最后计算n的所有种爬楼梯的方案数即可
 * 
*/

/**
 * 方法 1，使用递归来做，但是会超时
*/
int climbStairs(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return climbStairs(n - 1) + climbStairs(n - 2);
}

/**
 * 方法 2，使用动态规划来做，时间复杂度为O(n)
 * 状态f[i]表示第i节楼梯的所有方案的总和，那么它和i-1或者是i-2个楼梯方案
 * 总和有关系，所以利用状态方程进行计算即可
*/

int climbStairs2(int n)
{
    vector<int> f(n + 1);
    if (n < 2)
        return n;
    else
    {
        f[0] = 0, f[1] = 1, f[2] = 2;
    }

        for (int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main()
{
    cout << climbStairs2(5) << endl;
}