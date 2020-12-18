#include<iostream>
#include<vector>
using namespace std;

const int N = 1e6+10;

bool visited[N];
int primes[N], cnt;

void shiaxu(int x)
{
    for(itn i=2;i<=n;i++)
    {
        if(visited[i]==false)
        {
            primes[cnt++] = i;
            for(int j=i+i;j<=x;j+=i)
            {
                visited[j] = true;
            }
        }
    }
}
int main()
{
    int n;
    cin>>;

}
