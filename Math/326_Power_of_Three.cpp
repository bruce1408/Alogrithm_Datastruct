#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法 1，判断是不是3 的 n次方
*/

bool isPowerOfThree1(int n)
{
    while (n && n % 3 == 0)
    {
        n /= 3;
    }
    return n == 1;
}

int main()
{
    cout << isPowerOfThree1(9) << endl;
}
