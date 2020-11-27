#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

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
 * 使用浮点二分法来做即可
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

int main()
{
    double x = 100.00;
    tripleRoot2(x);
}
