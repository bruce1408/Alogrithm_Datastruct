#include <iostream>
#include <vector>
using namespace std;
const int N = 110;
vector<int> res(N, 0);

void comprime(int n)
{
    for (int t = 1; t <= n; t++)
    {
        int x = t;
        for (int i = 2; i <= x / i; i++)
        {
            if (x % i == 0)
            {
                while (x % i == 0)
                {
                    res[i]++;
                    x /= i;
                }
            }
        }
        if (x > 1)
            res[x] += 1;
    }
    for (int i = 0; i < 4; i++)
    {
        cout << i << " " << res[i] << endl;
    }
}

int cal(int n, int p)
{
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int temp = i;
        while (temp % p == 0)
        {
            ans++;
            temp /= p;
        }
    }
    return ans;
}

int main()
{
    int n = 6;
    comprime(n);
    // cout << cal(6, 3) << endl;
}