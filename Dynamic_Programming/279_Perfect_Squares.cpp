#include <iostream>
using namespace std;

/**
 * 279 给定一个正整数n，然后平方和相加起来最小的个数求解出来即可
*/

/**
 * 方法 1，首先有一个数学法则
 * 就是任意正整数可以有4个数的平方和表示
 * 如果这个数字n不等于4^a*(8*b+7)那么可以用3个数字的平方和表示
*/
bool check(int x)
{
    int root = sqrt(x);
    return root * root == x;
}

int numSquares(int n)
{
    // 只有一个数的情况
    if (check(n))
        return 1;

    for (int i = 1; i <= n / i; i++)
    {
        if (check(n - i * i))
            return 2;
    }

    while (n % 4 == 0)
        n /= 4;
    if (n % 8 != 7)
        return 3;
    return 4;
}

/**
 * 方法 2，使用动态规划来做
 * 建立一个长度为 n+1 的一维dp数组，将第一个值初始化为0，
 * 其余值都初始化为 INT_MAX, i从0循环到n，
 * j从1循环到 i+j*j <= n 的位置，然后每次更新 dp[i+j*j] 的值，
 * 动态更新 dp 数组，其中 dp[i] 表示正整数i能由多个完全平方数组成，
 * 那么我们求n，就是返回 dp[n] 即可，也就是 dp 数组的最后一个数字。
 * 需要注意的是这里的写法，i必须从0开始，j必须从1开始，
 * 因为我们的初衷是想用 dp[i] 来更新 dp[i + j * j]，
 * 如果 i=0, j=1 了，那么 dp[i] 和 dp[i + j * j] 就相等了，
 * 怎么能用本身 dp 值加1来更新自身
*/
int numSquares(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 1; i + j * j <= n; ++j)
        {
            dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
        }
    }
    return dp.back();
}