#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
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
 * 方法 2，数的很大的次方对1337取余的值，开始一直在想这个1337有什么玄机，
 * 为啥突然给这么一个数，感觉很突兀，后来想来想去也没想出来为啥，估计就是怕结果太大无法表示，
 * 随便找个数取余吧。那么这道题和之前那道Pow(x, n)的解法很类似，我们都得对半缩小，
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
 * we multiply the result b[sz -1] times by a ^ 1 . For 2-digit exponent, 
 * we multiply the result b[sz - 2] times by a ^ 10. For 3 digits, 
 * we multiply the result b[sz - 3] times by (a ^ 10) ^ 10. And so on.
 * 
 * So, in each iteration, we use the current exponential multiplier mul, 
 * and compute the new multiplier new_mul for the next digit
*/
int superPow3(int a, vector<int> &b)
{
    int res = 1, mul = a % 1337;
    for (int i = b.size() - 1; i >= 0; --i)
    {
        int new_mul = 1;
        for (auto j = 0; j <= 9; ++j)
        {
            if (j < b[i])
                res = (res * mul) % 1337;
            new_mul = (new_mul * mul) % 1337;
        }
        mul = new_mul;
    }
    return res;
}

int main()
{
    vector<int> res = {2, 3};
    cout << superPow3(2, res) << endl;
}