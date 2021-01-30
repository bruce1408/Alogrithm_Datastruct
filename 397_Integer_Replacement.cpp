#include <iostream>
using namespace std;

/**
 * 397 给一个数n，然后看除以2多少次之后可以变成1，n是偶数直接除2，
 * n是奇数可以用n-1或者是n+1代替
*/

/**
 * 方法 1，按照题目要求直接做即可
*/
typedef long long LL;
int f(LL n)
{
    if (n == 1)
        return 0;
    if (n % 2 == 0)
        return f(n / 2) + 1;
    return min(f(n - 1), f(n + 1)) + 1;
}

int integerReplacement1(int n)
{
    return f(n);
}

/**
 * 方法 2
*/
int integerReplacement2(int n)
{
    int count = 0;
    while (n != 1)
    {
        if (n % 2 != 0)
        {
            cout << n << endl;
            n = n - 1; // n+1 是17 找到最小的才可以；
            count++;
        }
        count++;
        n /= 2;
    }
    return count;
}

// 和方法 2类似
int integerReplacement4(int n)
{
    if (n == 1)
        return 0;
    if (n % 2 == 0)
        return 1 + integerReplacement4(n / 2);
    else
    {
        long long t = n; // 考虑溢出操作
        return 2 + min(integerReplacement4((t + 1) / 2), integerReplacement4((t - 1) / 2));
    }
}
int integerReplacement3(int n)
{
    int res = 0;
    if (n == INT_MAX)
    {
        n /= 2;
        res++;
    } // 对溢出操作直接定义；
    while (n != 1)
    {
        // 研究发现，除了7和3，所有其他加1是4的倍数的奇数，都适合加1操作；
        if (n % 2)
        {
            if ((n + 1) % 4 == 0 && n != 3)
                n += 1;
            else
                n -= 1;
        }
        else
            n /= 2;
        res++;
    }
    return res;
}

int main()
{
    int n;
    cout << "input a num: ";
    cin >> n;
    cout << integerReplacement(n) << endl;
    return 0;
}