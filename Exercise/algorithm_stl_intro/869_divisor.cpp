#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 求一个数的所有约数
 * 输入是：16
 * 输出是：1 2 4 8 16
*/
void divisor_prime(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i)
                res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    for (auto u : res)
    {
        cout << u << " ";
    }
}

int main()
{
    // int n;
    // cin >> n;
    // while (n--)
    // {
    //     int x;
    //     cin >> x;
    //     divisor_prime(x);
    // }
    divisor_prime(16);
    /**
     * 输入 
     * 2
     * 4 9
     * 
    */
}