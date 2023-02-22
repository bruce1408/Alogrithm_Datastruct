#include <iostream>
using namespace std;

typedef long long LL;
/**
 * 快速幂求解逆元
 * 若整数b，m互质，并且对于任意的整数 a，
 * 如果满足b|a，则存在一个整数x，使得a/b≡a∗x(mod m)，则称x为b的模m乘法逆元，记为 b−1(mod m) 。
 * b存在乘法逆元的充要条件是b与模数m互质。当模数m为质数时，bm−2即为b的乘法逆元。
*/
LL binaryPow(int a, int b, int c)
{
    LL res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % c;
        }
        a = a * (LL)a % c;
        b = b>>1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (a % b == 0)
            cout << "impossible" << endl;
        else
            cout << binaryPow(a, b - 2, b)<<endl;
    }
}
