#include <iostream>
using namespace std;

/**
 * 342 求一个数的是不是4的n次幂
*/

/**
 * 方法 1，不断除以4判断最后余数是不是1
*/
bool isPowerOfFour(int n)
{
    while (n && n % 4 == 0)
    {
        n /= 4;
    }
    return n == 1;
}

/**
 * 方法 2
*/
bool isPowerOfFour(int n)
{
    // n要大于
    if (n <= 0)
        return false;
    // n要是平方
    int r = sqrt(n);
    if (r * r != n)
        return false;
    // n的质因子都是2的平方
    return (1 << 30) % n == 0;
}
