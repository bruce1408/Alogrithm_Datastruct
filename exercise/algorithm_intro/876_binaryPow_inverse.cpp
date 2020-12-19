#include <iostream>
using namespace std;

typedef long long LL;

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
