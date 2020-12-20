#include <iostream>
using namespace std;

typedef long long LL;
int p;

/**
 * 组合数求解3，使用lucas算法即可
*/
int inv(int a, int m)
{
    int ans = 1;
    while (m)
    {
        if (m & 1)
        {
            ans = (LL)ans * a % p;
        }
        a = (LL)a * a % p;
        m >>= 1;
    }
    return ans;
}

// 这里和y总不一样，使用展开项之后，写成如下形式可以进行求解
int cal(int a, int b)
{
    int ans = 1;
    for (int i = 1; i <= b; i++)
    {
        ans = (LL)ans * (a - b + i) % p;
        ans = (LL)ans * inv(i, p - 2) % p; // 这里可以使用扩展的欧几里得算法，也可以使用快速幂
    }
    return ans;
}

int lucas(LL a, LL b)
{
    // if(b==0) return 1;
    if (a < p && b < p)
        return cal(a, b);
    return (LL)cal(a % p, b % p) * lucas(a / p, b / p) % p;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        LL a, b;
        cin >> a >> b >> p;
        cout << lucas(a, b) << endl;
    }
    return 0;
}
