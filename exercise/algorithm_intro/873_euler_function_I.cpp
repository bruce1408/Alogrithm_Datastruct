#include <iostream>
using namespace std;

/**
 * 欧拉函数问题
 * 首先求解质因数，然后根据质因数来求解，底数就是要求的
 * 欧拉公式如此链接所示：https://www.acwing.com/problem/content/875/
 * 这里要转换除法，先把乘法变成除，然后再乘这个数字，
 * 一来防止越界，第二把除数转化成整式
*/
int phi(int x)
{
    int res = x;

    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        res = res / x * (x - 1);
    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cout << phi(x) << endl;
    }
    return 0;
}