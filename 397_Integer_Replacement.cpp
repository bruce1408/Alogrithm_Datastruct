#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * 397 给一个数n，然后看除以2多少次之后可以变成1，n是偶数直接除2，
 * n是奇数可以用n-1或者是n+1代替
*/

/**
 * 方法 1，按照题目要求直接做即可，使用递归来做
*/
typedef long long LL;
int f(LL n)
{
    if (n == 1)
        return 0;
    if (n % 2 == 0)
        return f(n / 2) + 1;
    return min(f(n - 1), f(n + 1)) + 1;
}

int integerReplacement1(int n)
{
    return f(n);
}

/**
 * 方法 2，对方法1的优化
*/
unordered_map<LL, int> dp;
int f2(LL n)
{
    if (dp.count(n))
        return dp[n];
    if (n == 1)
        return 0;
    if (n % 2 == 0)
        return dp[n] = f(n / 2) + 1;
    return dp[n] = min(f(n + 1), f(n - 1)) + 1;
}

int integerReplacement2(int n)
{
    return f2(n);
}

/**
 * 方法 3
 */
int integerReplacement3(int n)
{
    if (n == 1)
        return 0;
    if (n % 2 == 0)
        return 1 + integerReplacement3(n / 2);
    else
    {
        long long t = n; // 考虑溢出操作
        return 2 + min(integerReplacement3((t + 1) / 2), integerReplacement3((t - 1) / 2));
    }
}

/**
 * 方法 4
*/
int integerReplacement4(int n)
{
    int count = 0;
    while (n != 1)
    {
        if (n % 2 != 0)
        {
            cout << n << endl;
            n = n - 1; // n+1 是17找到最小的才可以；
            count++;
        }
        count++;
        n /= 2;
    }
    return count;
}

int main()
{
    int n = 9;
    cout << integerReplacement3(n) << endl;
    return 0;
}