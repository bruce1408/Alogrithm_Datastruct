#include <iostream>
using namespace std;
/**
 * 欧几里得扩展方法
 * 给定n对正整数ai,bi，对于每对数，求出一组xi,yi，
 * 使其满足 ai∗xi + bi∗yi = gcd(ai,bi)。
 * 如果b=0，那么返回公约数为a，然后ax = d = a
 * 所以x=1,b=0
 * 如果b不是0，按照欧几里得做法求公约数，
 * 这里返回y和x调换一下顺序，因为后面做多项式化简比较方便
 * 然后根据a mod b = a - a/b * b;
 * 带入公式之后得到x不变，y = y- a / b * x；
 * 不断更新x和y即可
 * 
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
    int x = 1, y = 0;
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        exgcd(a, b, x, y);
        cout << x << " " << y << endl;
    }
    /**
     * 输入
     * 2
     * 4 6
     * 8 18
     * 输出
     * -1 1
     * -2 1
    */
}