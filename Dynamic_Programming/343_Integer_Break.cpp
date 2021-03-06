#include <iostream>
#include <vector>
using namespace std;

/**
 * 343 整数拆分，把一个整数进行拆分，将其拆分成至少两个整数的和，然后使得这个
 * 整数的乘积的最大化，返回这个乘积的最大乘积即可；
*/

/**
 * 方法 1，尽可能分成3和2，且最多是2个2,且分解的值是没有大于等于5的数
 * 因为如果大于等于5的话，那么可以分解成3+(a-3),3 * (a-3) ,它是大于a的
 * 因为3+(a-3) > a => 2a >9; a>4.5,所以成立的
 * 故最优解中没有一个数是大于等于5，只有1，2，3，4，同时不包含1，因为任何数
 * 和1相乘都是1，不如把1加到另一个数中去；
 * 所以包含2，3，4；4可以分解成2+2，所以只包含2，3；
 * 且2的个数不能大于2，比如6 = 2+2+2 不如分成3+3
*/
int integerBreak(int n)
{
    if (n <= 3)
        return 1 * (n - 1);
    int s = 1;
    while (n >= 5)
        n -= 3, p *= 3; // 最后n就剩下2，3，4所以最后乘以n即可
    return p * n;
}

/**
 * 方法 2，使用动态规划来做
 * f[i]表示将i拆分之后的最大乘积,数组大小为 n+1，值均初始化为1，
 * 因为正整数的乘积不会小于1;
 * 状态计算：f[i]作为结尾，考虑i拆成i-j和j；j的范围是1到i-1;
 * 分解j的情况：如果j的最大乘积是f[j]，那么fi = f[j] * (i-1);
 * 不分解的情况：f[i] = j * (i-j);
*/
int integerBreak(int n)
{
    vector<int> f(n + 1, 1);
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            f[i] = max(f[i], max(f[j] * (i - j), (i - j) * j));
        }
    }
    return f[n];
}