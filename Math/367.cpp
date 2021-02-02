#include <iostream>
using namespace std;

/**
 * 367 完全平方数
 * 给定一个数字n，然后看是否是完全平方数，是的就返回true，否则返回false
*/

/**
 * 方法 1，使用二分来做
*/
bool isPerfectSquare(int num)
{
    int l = 1, r = num;
    while (l < r)
    {
        int mid = (l + 1ll + r) >> 1;
        if (mid <= num / mid)
            l = mid;
        else
            r = mid - 1;
    }
    return l * l == num;
}
