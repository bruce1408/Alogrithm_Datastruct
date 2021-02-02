#include <iostream>
#include <vector>
#include "../utils/cout_vec.h"
using namespace std;

/**
 * 313 超级丑数
*/
int nthSuperUglyNumber(int n, vector<int> &primes)
{
    vector<int> res(1, 1), idx(primes.size(), 0);
    while (res.size() < n)
    {
        vector<int> tmp;
        int mn = INT_MAX;
        for (int i = 0; i < primes.size(); ++i)
        {
            tmp.push_back(res[idx[i]] * primes[i]);
        }
        cout << res.size() << endl;
        print(tmp);
        cout << endl;
        for (int i = 0; i < primes.size(); ++i)
        {
            mn = min(mn, tmp[i]);
        }
        for (int i = 0; i < primes.size(); ++i)
        {
            if (mn == tmp[i])
                ++idx[i];
        }
        res.push_back(mn);
        cout << "res ";
        print(res);
    }
    return res.back();
}

int main()
{
    vector<int> res = {2, 7, 13, 19};
    cout << nthSuperUglyNumber(12, res) << endl;
}