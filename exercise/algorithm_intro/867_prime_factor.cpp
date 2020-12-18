#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

/**
 * 分解质因数，指的就是将一个正整数n写成一个或者多个质数的乘积的形式
 * 例如6=2*3；180 = 2^2*3^2*5^1;
 * 然后写成底数和指数的形式即可；
*/
void prime(int n)
{
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            int s = 0;
            while (n % i == 0)
            {
                n /= i;
                s++;
            }
            printf("%d %d\n", i, s);
        }
    }
    if (n > 1)
        printf("%d %d\n", n, 1);
    cout << endl;
}

int main()
{
    prime(8);
}