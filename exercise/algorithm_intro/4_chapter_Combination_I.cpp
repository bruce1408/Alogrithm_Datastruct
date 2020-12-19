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
        for (int i = 2; i <= t / i; i++)
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
    }
    for (int i = 0; i < 4; i++)
    {
        cout << res[i] << endl;
    }
}

int main()
{
    int n = 6;
    comprime(n);
}