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
*/
long long binaryPow1(int a, int b, int c)
{
    if(b==0) return 1;
    if(b%2==1) return a * binaryPow1(a, b-1, c) % c;
    else 
    {
        long long mul = b * binaryPow1(a, b/2, c);
        return mul * mul  % c;
    }

}