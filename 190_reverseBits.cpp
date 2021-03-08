#include <iostream>
using namespace std;
/**
 * 190 翻转二进制数字
 * 给定一个无符号数字n，然后翻转这个数字
*/

/** 移位操作，大概意思就是，每次数n向右移动一位，如果是
 * 1，那么res 左移一位，刚开始是0，并且加1，如果n右移一位
 * 是0，那么res左移一位之后加0.循环往复
 * */
uint32_t reverseBits(uint32_t n)
{
    uint32_t res = 0;
    for (int i = 0; i < 32; i++)
    {
        if (n & 1)
        {
            res = (res << 1) + 1;
        }
        else
        {
            res = res << 1;
        }
        n = n >> 1;
    }
    return res;
}

int main()
{
    uint32_t n = 987;
    cout << reverseBits(n) << endl;
}