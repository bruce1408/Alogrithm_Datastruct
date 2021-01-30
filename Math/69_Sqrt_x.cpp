#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * 69 求一个非负整数的平方根
*/

/**
 * 方法 1，使用二分算法，注意越界问题
*/
int mySqrt1(int x)
{
    int l = 0, r = x;
    while (l < r)
    {
        int mid = (l + (long long)r + 1) >> 1;
        if (mid <= x / mid)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

/**
 * 方法 2，利用牛顿迭代法
 * 求解的是f(x)= x^2 - n ,f(x)=0 的情况 
*/
int mySqrt2(int x)
{
    double res = 1.0;
    double comp = 0;
    while (abs(comp - res) >= 0.00001)
    {
        comp = res;
        res = (res + x / res) / 2;
    }
    return (int)res;
}

// 除了上面的这种方法之外。还有一种二分查找方法。后面再补吧
int main()
{
    int a = 8;
    cout << mySqrt(a);
}