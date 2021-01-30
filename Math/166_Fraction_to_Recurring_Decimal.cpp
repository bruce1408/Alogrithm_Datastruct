#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * 166 求解一个数除以另一个数的小数部分
*/

/**
 * 方法 1
*/
string fractionToDecimal(int s, int t)
{
    typedef long long LL;
    LL x = s, y = t;
    if (x % y == 0)
        return to_string(x / y);
    string res;
    if (x < 0 ^ y < 0)
        res += '-';
    x = abs(x), y = abs(y);
    res += to_string(x / y) + '.';
    x = x % y;
    unordered_map<LL, int> hash;
    while (x)
    {
        hash[x] = res.size();
        x *= 10;
        res += to_string(x / y);
        x = x % y;

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