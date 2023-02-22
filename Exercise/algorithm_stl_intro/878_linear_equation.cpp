#include <iostream>
#include <vector>
using namespace std;

/**
 * 4x = 3(mod5)
 * 表示4乘以某个数然后对5求余数，模是3，那么x=2即可满足要求
 * 只要输入int 范围内的解就可以
 * 
 * 可以表示为ax = my + b -> ax - my = b
 * 即存在y是的上面的式子成立
 * 所以可以使用扩展欧几里得算法的应用
*/
 
int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int t = exgcd(b, a % b, y, x);
    y = y - a / b * x;
    return t;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x, y;
        int a, b, m;
        cin >> a >> b >> m;
        int t = exgcd(a, m, x, y);
        if (b % t) // 如果b不能被最大公约数整除，那么不存在这个数
            cout << "impossible" << endl;
        else                                            // 如果存在这个数，那么先要扩大倍数，然后
            cout << (long long)x * (b / t) % m << endl; // 扩大b/t的倍数即可
    }
    return 0;
}
