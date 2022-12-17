#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法 1，使用简易写法，时间复杂度是O(n)
 * 但是可如果是很大的数可能会溢出
*/
void binaryPow()
{
    int res = 1;
    int a = 3, b = 5, c = 5;
    for (int i = 0; i < b; i++)
    {
        res = res * a % c;
        cout << res << endl;
    }
    cout << "final : " << res << endl;
}

/**
 * 方法 2，使用快速幂解法
 * 如果指数b是偶数：那么a^b = a^b/2 * a^b/2;
 * 如果指数b是奇数：那么a^b = a*a^b-1
*/
long long binaryPow1(int a, int b, int c)
{
    if (b == 0)
        return 1;
    if (b & 1)
        return a * binaryPow1(a, b - 1, c) % c;
    else
    {
        // 这里是偶数的情况，不用两个调用binaryPow1, 而是求一个，然后再乘，这样复杂度不会增加
        long long mul = binaryPow1(a, b / 2, c);
        return mul * mul % c;
    }
}

/**
 * 方法 3，快速幂的迭代写法
 * 返回的是a^k mod b
*/
long long binaryPow2(int a, int b, int c)
{
    long long ans = 1;
    while (b > 0)
    {
        if (b & 1)             // 第一次迭代b末尾要是1的话就是a的2的0次方
            ans = ans * a % c; // 最开始a 是 2的0次方
        a = a * a % c;         // a是上一个数的平方 mod c
        b = b >> 1;            // 然后看b的下一位
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << binaryPow2(a, b, c) << endl;
    }
}