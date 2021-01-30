#include <iostream>
#include <vector>
using namespace std;

/**
 * 233 求一个数字中1出现的次数
*/

/**
 * 方法 1，从n-1之间逐位进行遍历求解即可。
*/
int countDigitOne(int n)
{
    int ans = 0;
    for (int i = n; i > 0; i--)
    {
        ans += getone(i);
    }
    return ans;
}

int getone(int x)
{
    int res = 0;
    while (x)
    {
        if (x % 10 == 1)
            res++;
        x /= 10;
    }
    return res;
}

/**
 * 
*/
int main()
{
}