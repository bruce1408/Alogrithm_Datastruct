#include <iostream>
#include <vector>
using namespace std;

/**
 * 338 比特进位，给定一个整数n，从0-n之间的数字二进制位含有
 * 多少个1，输出到数组中即可
*/

/**
 * 方法 1，使用双指针，两重循环。时间复杂度高
*/
vector<int> countBits(int num)
{
    vector<int> res;
    for (int i = 0; i <= num; i++)
    {
        int k = i, bitnum = 0;
        while (k)
        {
            if (k & 1)
                bitnum++;
            k >>= 1;
        }
        res.push_back(bitnum);
    }
    return res;
}

/**
 * 方法 2，使用O(n)时间复杂度来做
 * 因为f[i] = f[i>>1] + i&1 的结果
*/
vector<int> countBits(int num)
{
    vector<int> f(num + 1);
    for (int i = 1; i <= num; i++)
    {
        f[i] = f[i >> 1] + (i & 1);
    }
    return f;
}
