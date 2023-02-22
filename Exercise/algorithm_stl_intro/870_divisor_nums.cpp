#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;
/**
 * 输入n个数字，求乘积的质因数，每一个数的质因数分解然后利用
 * 哈希表存储，最后使用乘法原理来累乘，
 * 首先进行因式分解，然后指数加1再相乘即可
*/
int main()
{
    int n;
    long long ans = 1;
    unordered_map<int, int> res;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        int cnt = 0;
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                res[i]++;
                x /= i;
            }
        }
        if (x > 1)
            res[x]++;
    }
    for (auto i : res)
        ans = ans * (i.second + 1) % mod;

    cout << ans << endl;
}