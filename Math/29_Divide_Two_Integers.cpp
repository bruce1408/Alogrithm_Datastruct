#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * 29 两数相除，不能使用乘，除，mod运算
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
 * 方法 1，使用快速幂的思路，首先，处理两数的符号，如果是负数的话，那么就记录符号然后两数取绝对值即可
 * 然后利用快速幂的技巧，新开一个数组保存b到a之间的 2^i * b的数值，在后面计算商的时候会用到，只要a >= 2^i * b
 * 说明a可以减去这个数字，然后知道a小于位置，同时每次累加商左移i位，最后得到的就是商。
*/
typedef long long LL;
int divide(int x, int y)
{
    bool minus = false;
    if (x < 0 && y > 0 || x > 0 && y < 0)
        minus = true;
    LL a = abs((LL)x), b = abs((LL)y);
    vector<LL> res;
    for (LL i = b; i <= a; i = i + i)
        res.push_back(i); // 2^i * y 保存y的乘积
    LL ans = 0;
    for (int i = res.size() - 1; i >= 0; i--)
    {
        if (a >= res[i])
        {
            ans += 1ll << i;
            a -= res[i];
        }
    }
    if (minus)
        return ans * -1;
    if (ans < INT_MIN || ans > INT_MAX)
        ans = INT_MAX;
    return ans;
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