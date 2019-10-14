#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * The Fibonacci numbers, commonly denoted F(n) form a sequence,
 * called the Fibonacci sequence, such that each number is the 
 * sum of the two preceding ones, starting from 0 and 1. That is,
 * F(0) = 0,   F(1) = 1
 * F(N) = F(N - 1) + F(N - 2), for N > 1.
 * Given N, calculate F(N).
 * Example 1:
 * Input: 2
 * Output: 1
 * Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
*/

/**
 * 方法 1 菲波那切数列数列
*/
int fib(int N)
{
    if (N == 0)
        return 0;
    if (N == 1)
        return 1;
    int a = 0, b = 1;
    int c = 0;
    for (int i = 1; i < N; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

/**
 * 方法 2 利用动态规划来做
*/
int fib2(int N)
{
    if (N < 2)
        return N;
    return fib2(N - 1) + fib2(N - 2);
}

int main()
{
    cout << fib2(5) << endl;
}
