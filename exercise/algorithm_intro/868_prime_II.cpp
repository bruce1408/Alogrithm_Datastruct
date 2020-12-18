#include <iostream>
#include <algorithm>
using namespace std;
/**
 * 筛法来求素数的数组
 * 算法是从小到大枚举所有数，关键是对每一个素数，筛去它的所有倍数，
 * 剩下的就是素数，筛这个 工作可以用一个bool数组来实现，如果被筛掉，那么
 * 对应的位置为true，否则是false，初始化的时候全部是false
*/
const int N = 1e6 + 10;
int primes[N], cnt;
bool visited[N];

void getprime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (visited[i] == false)
            primes[cnt++] = i;
        for (int j = i + i; j <= n; j += i)
            visited[j] = true;
    }
}

int main()
{
    int n = 8;
    // cin>>n;
    getprime(n);
    printf("8之前的素数共有: %d 个\n", cnt);
    for (int i = 0; i < cnt; i++)
    {
        cout << primes[i] << " ";
    }
}