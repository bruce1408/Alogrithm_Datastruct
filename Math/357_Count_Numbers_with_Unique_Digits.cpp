#include <iostream>
using namespace std;

/**
 * 357 
 * 给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10n 。
 * 示例:
 * 输入: 2
 * 输出: 91
 * 解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。
*/

/**
 * 方法 1，根据通项公式，然后f(n) = 9 * (11 - i), i=2, 3, 4, 5...找出除各个位上数字不相同的数字总和
 * 推荐做法
 * 如果n是0的话，那么只有1种，否则
 * 一位数的满足要求的数字是10个(0到9)；
 * 二位数的满足题意的是81个，[10 - 99]这90个数字中去掉[11,22,33,44,55,66,77,88,99]这9个数字，还剩81个
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
