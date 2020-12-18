#include<iostream>
#include<vector>
using namespace std;

const int N = 1e6+10;

bool visited[N];
int primes[N], cnt;

void shiaxu(int x)
{
    for(int i=2;i<=x;i++)
    {
        if(visited[i]==false)
        {
            primes[cnt++] = i;
            
        }
        for(int j = i+i;j<=n;j+=i)
        {
            if(x%i==0)
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
