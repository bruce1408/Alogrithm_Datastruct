#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 输入n个数字，求每一个数的约数个数，然后所有数的约数个数相加
*/
void divisor_prime(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            res.push_back(i);
            if(i!=x/i) res.push_back(x / i);
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
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        divisor_prime(x);
    }
}