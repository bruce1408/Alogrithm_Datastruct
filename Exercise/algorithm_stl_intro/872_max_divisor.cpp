#include <iostream>
using namespace std;
/**
 * 最大公约数
 * 输入n包含是一个整数
 * 然后输出两个整数的最大公约数
 * 主要使用最大公约数的一个公式
 * gcd(a, b) = gcd(b, a%b);
*/
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
}