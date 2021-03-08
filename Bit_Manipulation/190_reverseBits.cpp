#include <iostream>
using namespace std;
/**
 * 190 翻转二进制数字
 * 给定一个无符号数字n，然后翻转这个数字
*/

/** 
 * 方法 1，移位操作，设置一个res保存结果，如果n和1与的结果是1，那么
 * res左移一位，且加上1，如果n和1相与结果是0，那么就是左移一位加0；
 * n每次右移一位即可
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
