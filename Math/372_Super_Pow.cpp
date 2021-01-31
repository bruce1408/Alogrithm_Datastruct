#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * 372超级次方和50计算n次幂非常类似，使用快速幂的方法来做
 * Your task is to calculate ab mod 1337 
 * where a is a positive integer and b is an extremely large positive integer given in the form of an array
 * 
*/
/**
 * 方法 1，使用逻辑算法，但是会越界
*/
int superPow(int a, vector<int> &b)
{
    int dig = 0, res = 1;
    for (int i = 0; i < b.size(); i++)
    {
        dig = dig * 10 + b[i];
    }
    for (int i = 0; i < dig; i++)
    {
        res = res * a;
    }
    return res;
}
/**
 * 方法 2，那么这道题和之前那道Pow(x, n)的解法很类似，我们都得对半缩小，
 * 不同的是后面都要加上对1337取余。由于给定的指数b是一个一维数组的表示方法，我们要是折半缩小处理起来肯定十分不方便，
 * 所以我们采用按位来处理，比如2^23 = (2^2)10 * 2^3, 所以我们可以从b的最高位开始，算出个结果存入res，
 * 然后到下一位是，res的十次方再乘以a的该位次方再对1337取余,推荐
*/
int pow1(int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x % 1337;
    return pow1(x % 1337, n / 2) * pow1(x % 1337, n - n / 2) % 1337;
}

int superPow2(int a, vector<int> &b)
{
    long long res = 1;
    for (int i = 0; i < b.size(); ++i)
    {
        res = pow1(res, 10) * pow1(a, b[i]) % 1337;
    }
    return res;
}
/**
 * 方法 3，For 1-digit exponent, 
 */

typedef long long LL;
int superPow(int a, vector<int> &b)
{
    if (b.empty())
        return 1;
    int t = b.back();
    b.pop_back();
    return qmi(a, t) * qmi(superPow(a, b), 10) % 1337;
}

LL qmi(LL a, LL n)
{
    LL res = 1;
    a %= 1337;
    while (n)
    {
        if (n & 1)
            res = res * a % 1337;
        n >>= 1;
        a = a * a % 1337;
    }
    return res;
}

int main()
{
    vector<int> res = {2, 3};
    cout << superPow3(2, res) << endl;
}