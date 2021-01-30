#include <iostream>
#include <sstream>
#include <string>
using namespace std;
/**
 * 7 给定一个整数然后翻转即可
*/

/**
 * 方法 1
 * */
int reverse1(int x)
{
    while (x)
        res.push_back(x % 10), x /= 10;
    int temp = 0;
    for (int i = 0; i < res.size(); i++)
    {
        if (abs(temp) > INT_MAX / 10)
            return 0;
        temp = temp * 10 + res[i] % 10;
    }
    return temp;
}

/**
 * 方法 2，优化写法，省去开数组的额外开销
*/
int reverseNum(int x)
{
    int res = 0;
    while (x)
    {
        // 判断翻转越界
        if (abs(res) > INT_MAX / 10)
            return 0;
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

/**
 * 方法 2，注意这里会有越界问题
*/
int reverse2(int x)
{
    int r = 0;
    while (x)
    {
        if (r > 0 && r > (INT_MAX - x % 10) / 10)
            return 0;
        if (r < 0 && r < (INT_MIN - x % 10) / 10)
            return 0;
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}

int main()
{
    int n = -2134567898;
    cout << reverseNum(n) << endl;
    return 0;
}