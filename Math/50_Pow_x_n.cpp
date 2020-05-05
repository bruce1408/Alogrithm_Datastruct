#include <iostream>
#include <cmath>
using namespace std;
/**
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 * 计算n次幂
 * 
 * Example 1:
 * Input: 2.00000, 10
 * Output: 1024.00000
*/

/**
 * 方法一：递归，每次折半的计算，
 * 一开始考虑过使用 x *Pow(x, n-1)递归的形式，但是有两点问题，一个是负数的问题怎么办
 * 还有一个是这样的递归，依然效率太低，超时了。
 */ 
double power(double x, int n)
{
    if (x == 0)
        return 0.0;
    if (n == 0)
        return 1.0;
    double half = power(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else
        return half * half * x;
}

double myPow(double x, int n)
{
    if (n < 0)
        return 1 / power(x, -n);
    else
        return power(x, n);
}

/**
 * 方法 2，使用递归，另一个思路的递归
*/
double power2(double x, int n)
{
    if (x == 0)
        return 0.0;
    else if (n == 0)
        return 1.0;
    int t = n / 2;
    double temp = power2(x, t);
    if (n % 2 == 0)
    {
        return temp * temp;
    }
    else
    {
        return temp * temp * x;
    }
}

double myPow2(double x, int n)
{
    if (n < 0)
    {
        n = abs(n);
        return 1.0 / power2(x, n);
    }
    else
    {
        return power2(x, n);
    }
}
/**
 * 方法 3，和上面的思路一样，就是写法不太一样
*/
double myPow3(double x, int n)
{
    if (n == 0)
        return 1;
    double half = myPow3(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    if (n > 0)
        return half * half * x;
    return half * half / x;
}

/**
 * 方法 4，就是如果n选择的是最小的数字，那么取绝对值就会越界，这里需要判断一下
 * 方法 4考虑到了这种情况；方法 1和 方法 2都包含了这种情况了， 就是首先n/2折半，这样即使取绝对值的话，就不会出现
 * 越界的情况了，方法 4的思路是一样的，但是写法更清晰。
*/
int myPow4(double x, int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else if (n < 0)
    {
        if (n == INT_MIN)
        {
            n = INT_MAX;
            return x / (myPow4(x, n));
        }
        else
        {
            n = n * -1;
            return 1 / myPow4(x, n);
        }
    }
    int t = n / 2;
    double temp = myPow4(x, t);
    if (n % 2 == 0)
    {
        return temp * temp;
    }
    else
    {
        return temp * temp * x;
    }
}

/**
 * 方法 5，推荐算法
*/
double myPow5(double x, int n)
{
    if (n == 1)
        return x;
    if (n == 0)
        return 1.0;
    int t = n / 2;
    if (n < 0)
    {
        x = 1 / x;
        t = -t;
    }
    double res = myPow5(x, t);
    if (n % 2 == 0)
        return res * res;
    return res * res * x;
}
/**
 * 方法 6，迭代法
*/
double myPow6(double x, int n)
{
    double res = 1.0;
    for (int i = n; i != 0; i /= 2)
    {
        if (i % 2 != 0)
            res *= x;
        x *= x;
    }
    return n < 0 ? 1 / res : res;
}

int main()
{
    double x = 2, n = -3;
    cout << myPow6(x, n) << endl;
    return 0;
}
