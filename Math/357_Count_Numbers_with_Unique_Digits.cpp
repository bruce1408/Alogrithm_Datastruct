#include <iostream>
using namespace std;

/**
 * 方法 1，根据通项公式，然后f(n) = 9 * (11 - i), i=2, 3, 4, 5, 
*/
int countNumbersWithUniqueDigits(int n)
{
    if (n == 0)
        return 1;
    int res = 10, cnt = 9; // res 是一位数的结果，然后i从2开始，表示2位数
    for (int i = 2; i <= n; ++i)
    {
        cnt *= (11 - i); // 两位数的时候使用递推公式来写
        res += cnt;      // 最后res累加即可返回
    }
    return res;
}

/**
 * 方法 2，使用数组保存几位数的个数
*/
int countNumbersWithUniqueDigits2(int n)
{
    n = min(n, 10);
    vector<int> f(n + 1);
    if (n == 0)
        return 1;
    f[1] = 9;
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] * (11 - i);
    }
    for (int i = 1; i <= n; i++)
    {
        res += f[i];
    }
    return res;
}
