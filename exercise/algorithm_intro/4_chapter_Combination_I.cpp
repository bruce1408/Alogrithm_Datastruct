#include <iostream>
#include <vector>
using namespace std;
const int N = 110;
vector<int> res(N, 0);
void comprime(int n)
{
    for (int x = 1; x <= n; x++)
    {
        for(int i=2;i<=x/i;i++)
        {
            if(x%i==0)
        }
    }
}
int main()
{
    int n = 6;
    comprime(n);
}