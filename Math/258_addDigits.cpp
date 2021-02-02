#include <iostream>
using namespace std;

/**
 * 258 一个数各位上的数字之和相加之后，知道是个位数就输出
*/
int addDigits(int x)
{
    if (x == 0)
        return 0;
    else if (x % 9 != 0)
        return x % 9;
    else
        return 9;
}

int main()
{
    cout << addDigits(98) << endl;
}