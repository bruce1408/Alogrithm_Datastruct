#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * 166 求解一个数除以另一个数的小数部分
*/

/**
 * 方法 1，按照正常的逻辑思路一步一步求解即可
*/
string fractionToDecimal(int x1, int y1)
{
    typedef long long LL;
    LL x = x1, y = y1;
    if (x % y == 0)
        return to_string(x / y);
    string res;

    // 如果有负数的情况
    if ((x < 0) ^ (y < 0))
        res += '-';
    x = abs(x), y = abs(y);

    // 整数部分
    res += to_string(x / y) + '.';
    x %= y;

    // 余数部分开始
    unordered_map<LL, int> hash;
    while (x)
    {
        hash[x] = res.size();
        x *= 10;
        res += to_string(x / y);
        x %= y;
        if (hash.count(x))
        {
            res = res.substr(0, hash[x]) + '(' + res.substr(hash[x]) + ')';
            break;
        }
    }
    return res;
}

int main()
{
    int x = 100, y = 23;
    cout << fractionToDecimal(x, y) << endl;
}