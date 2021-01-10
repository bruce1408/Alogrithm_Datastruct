#include <iostream>
#include <vector>
using namespace std;

/**
 * 461 汉明距离求解
 * 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
 * 给出两个整数 x 和 y，计算它们之间的汉明距离。
 * 注意：0 ≤ x, y < 231.
 * 输入: x = 1, y = 4
 * 输出: 2
 * 解释:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 *        ↑   ↑
*/

/**
 * 方法 1，使用位运算，然后先求解x和y的异或结果
 * 然后最这个结果统计1的个数即可
*/
int hammingDistance(int x, int y)
{
    int cnt = 0;
    int c = x ^ y; // 求解异或结果
    while (c)
    {
        if (c & 1)
            cnt++;
        c >>= 1;
    }
    return cnt;
}

/**
 * 方法 2，分别计算每一个数字的和1相与结果,然后进行相加
*/
int hammingDistance2(int x, int y)
{
    int cnt = 0;
    while (x & 1 || y & 1)
    {
        cnt += (x & 1) ^ (y & 1);
        x >>= 1, y >>= 1;
    }
    return cnt;
}

int main()
{
    int x = 1, y = 4;
    cout << hammingDistance(x, y) << endl;
}