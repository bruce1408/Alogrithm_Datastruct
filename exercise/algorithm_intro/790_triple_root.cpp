#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * 给定一个浮点数n，求它的三次方根。
 * 输入格式共一行，包含一个浮点数n。
 * 输出格式共一行，包含一个浮点数，表示问题的解。
 * 注意，结果保留6位小数。
 * 数据范围
 * −10000≤n≤10000
 * 输入样例：
 * 1000.00
 * 输出样例：
 * 10.000000
*/

/**
 * 方法 1，使用的是循环遍历，但是超时了，可以使用二分算法
*/
void tripleRoot1(double x)
{
    for (double i = 0; i < sqrt(x); i += 0.000001)
    {
        if (x - i * i * i <= 1e-6)
        {
            printf("%.6f\n", i);
            break;
        }
    }
}

/**
 * 使用浮点二分法来做即可，浮点二分法相对来说时间复杂度更低，具体算法思路就是
 * 左右设置边界，然后这里和整数二分不同的是，浮点二分不需要严格要求边界，所以
 * 只要区间的长度很小的时候我们就认为找到了答案，这里就用right-left长度大于某个
 * 值来表示，如果中间点的3次方大于x，那么更新从右侧边界为mid，否则是左侧边界为mid，
 * 另外注意题目要求的是1e-6，那么写法要大于2位，1e-8次方。
 * 
 * 或者是可以for循环100次即可，相当于区间的长度L/2^100，那么这个值就很小，也可以表示区间长度。
*/
void tripleRoot2(double x)
{
    double l = -10000, r = 10000;
    while (r - l >= 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x)
            r = mid;
        else
            l = mid;
    }
    printf("%.6f", l);
}

void trip(double x)
{
    double l = -10000, r = 10000;
    while (r - l >= 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x)
            r = mid;
        else
            l = mid;
    }
    printf("%.6f", l);
}
int main()
{
    double x = 100.00;
    tripleRoot2(x);
}
