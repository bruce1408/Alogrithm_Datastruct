#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 * Return the quotient after dividing dividend by divisor.
 * The integer division should truncate toward zero, which means losing its fractional part. 
 * For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
 * 
 * Example 1:
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = truncate(3.33333..) = 3.
*/
/**
 * 方法 1，不要使用乘，除，操作来进行计算，求商，注意的是越界问题，如果-2147483648 和 -1，那么结果肯定越界了
 * 方法 1有问题
*/
int divide(int dividend, int divisor)
{
    int remain = abs(dividend) / abs(divisor);
    if (remain <= 2147483647)
    {
        if (dividend < 0 && divisor < 0)
        {
            return remain;
        }
        else if (dividend < 0 || divisor < 0)
        {
            return remain * -1;
        }
    }
    else
    {
        if (dividend < 0 && divisor < 0)
        {
            int k = 4294974298 - remain;
            return k;
        }
    }
    return remain;
}

/**
 * 方法 2，思路是，如果被除数大于或等于除数，则进行如下循环，定义变量t等于除数，定义计数p，当t的两倍小于等于被除数时，进行如下循环
 * t扩大一倍，p扩大一倍，然后更新 res 和m。这道题的 OJ 给的一些 test case 非常的讨厌，因为输入的都是 int 型，比如被除数是 -2147483648
 * 在 int 范围内，当除数是 -1 时，结果就超出了 int 范围，需要返回 INT_MAX，所以对于这种情况就在开始用 if 判定，将其和除数为0的情况放一起判定，
 * 返回 INT_MAX。然后还要根据被除数和除数的正负来确定返回值的正负，这里采用长整型 long 来完成所有的计算，最后返回值乘以符号即可
*/
int divide2(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    long m = abs(dividend), n = abs(divisor), res = 0;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    if (n == 1)
        return sign == 1 ? m : -m;
    while (m >= n)
    {
        long t = n, count = 1;
        while (m >= (t << 1))
        {
            t <<= 1;
            count <<= 1;
        }
        res += count;
        m -= t;
    }
    return sign == 1 ? res : -res;
}

int main()
{
    int a, b;
    int k = 5;
    while (k--)
    {
        cout << "请输入 a 和 b 的值：" << endl;
        // cin >> a >> b;
        a = 69, b = 4;
        cout << "结果是" << endl;
        cout << divide2(a, b) << endl;
    }
}