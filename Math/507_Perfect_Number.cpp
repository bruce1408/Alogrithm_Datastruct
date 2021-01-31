#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * 507 一个数的 完数 就是所有因子相加还是这个数，那么满足题意 28 = 1 + 2 + 4 + 7 + 14
 * */

/**
 * 方法 1，找小于num的因子然后相加即可
*/
bool checkPerfectNumber(int num)
{

    int sum = 0;
    for (int i = 1; i <= num / i; i++) // 这个是求所有因子
    {
        if (num % i == 0)
        {
            if (num / i != i && num / i < num)
                sum += num / i;
            if (i < num)
                sum += i;
        }
    }
    return sum == num;
}

int main()
{
    int a = 28;
    cout << checkPerfectNumber(a);
    return 0;
}