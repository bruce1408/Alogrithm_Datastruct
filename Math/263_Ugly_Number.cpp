#include <iostream>
using namespace std;

/**
 * 263 丑数，就是可以被2，3，5质因子整除的数
*/

/**
 * 方法 1，连续被2，3，5整除即可，最后判断是不是等于1
*/
bool isUgly(int num)
{
    if (num <= 0)
        return false;
    while (num % 2 == 0)
        num /= 2;
    while (num % 3 == 0)
        num /= 3;
    while (num % 5 == 0)
        num /= 5;
    return num == 1;
}
