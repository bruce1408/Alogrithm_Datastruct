#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

/**
 * Calculate the sum of two integers a and b, 
 * but you are not allowed to use the operator + and -.
 * 
 * Example 1:
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 使用位操作来计算 + 或者 - 的运算
*/

/**
 * 方法 1，使用 递归 + 位操作 来计算两个数的加减法运算。
*/
int getSum(int a, int b)
{
    if (b == 0)
        return a;
    int sum = a ^ b;
    int carry = (a & b & 0x7fffffff) << 1;
    return getSum(sum, carry);
}

/**
 * 方法 2，使用位运算和逻辑解法来做这道题目，不用递归会更好理解一些
*/
int getSum2(int a, int b)
{
    int sum = 0;
    bool carry = false;
    for (int i = 0; i < 32; i++)
    {
        int lastDig = (a & 1) ^ (b & 1); // 异或的情况
        if (carry) // 没有进位的情况
        {
            if (lastDig) // 如果最后一位的数字是0，1组合，那么就没有进位，同时把lastDig设置为0
                lastDig = 0;
            else // 否则，lastDig 设置为1，然后可能有进位的情况，需要判断一下
            {
                lastDig = 1;
                carry = ((a & 1) && (b & 1)); // 判断是不是有进位
            }
        }
        else // 判断是不是有进位
        {
            if ((a & 1) && (b & 1))
                carry = true;
        }
        lastDig = lastDig << i;
        sum = sum | lastDig;
        a >>= 1;
        b >>= 1;
    }
    return sum;
}
/**
 * 偷懒的做法，使用函数sum，这个不算方法
*/
int getSum3(int a, int b)
{
    vector<int> res;
    int sum = 0;
    res.push_back(a);
    res.push_back(b);
    return accumulate(res.begin(), res.end(), sum);
}

int main()
{
    cout << getSum2(2, 4) << endl;
}