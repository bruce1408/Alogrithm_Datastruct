#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
void prime(int n)
{
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            int s = 0;
            while (n % i == 0)
            {
                n /= i;
                s++;
            }
            printf("%d %d\n", i, s);
        }
    }
    if (n > 1)
        printf("%d %d\n", n, 1);
    cout << endl;
}

int main()
{
    prime(8);
}