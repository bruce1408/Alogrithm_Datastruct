#include <iostream>
#include <cmath>
using namespace std;
/**
 * 50  计算n次幂
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 * 
 * Example 1:
 * Input: 2.00000, 10
 * Output: 1024.00000
*/

/**
 * 方法 1，和上面的思路一样，就是写法不太一样
*/
double myPow1(double x, int n)
{
    if (n == 0)
        return 1;
    double half = myPow1(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    if (n > 0)
        return half * half * x;
    return half * half / x;
}

/**
 * 方法 2，其实这道题使用快速幂来求解即可
 * 递归版本的快速幂计算
 * 如果是直接做的话，那么时间复杂度是O(n)，但是使用快速幂利用二分的思想
 * 如果n是奇数那么就是a^b = a^1 * a^b-1
 * 如果n是偶数那么就是a^b = a^b/2 * a^b/2
 * n有可能回越界，所以直接用long long 类型
*/
typedef long long LL;

double binpow(double x, LL n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return x * binpow(x, n - 1);
    else
    {
        double mul = binpow(x, n / 2); // 这里返回的不是两个n/2的乘积，而是计算单个之后再乘
        return mul * mul;
    }
}

double myPow2(double x, int n)
{
    if (n < 0)
        return 1.0 / binpow(x, abs(LL(n)));
    else
        return binpow(x, n);
}

/**
 * 方法 3，使用快速幂的迭代写法
*/
typedef long long LL;
double myPow(double x, int n)
{
    double res = 1;
    bool minus = false;
    if (n < 0)
        minus = true;
    LL t = abs((LL)(n));
    while (t)
    {
        if (t & 1)
            res = res * x;
        x = x * x;
        t >>= 1;
    }
    if (minus)
        return 1 / res;
    else
        return res;
}

int main()
{
    double x = 2, n = -3;
    cout << myPow6(x, n) << endl;
    return 0;
}
