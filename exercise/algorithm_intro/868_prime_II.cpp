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

/**
 * 方法 1，朴素筛法
*/
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

/**
 * 方法 2，优化筛法，不用再多次删除某些数
 * 只要删除质数的所有倍数删除就好了，
*/
void getprime1(int n)
{
    // int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (visited[i] == false) // 只有是质数的时候才删除质数的倍数
        {
            primes[cnt++] = i;
            for (int j = i + i; j <= n; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

/**
 * 方法 3，线性筛法
*/
void getprime2(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main()
{
    int n = 8;
    // cin>>n;
    getprime1(n);
    printf("8之前的素数共有: %d 个\n", cnt);
    for (int i = 0; i < cnt; i++)
    {
        cout << primes[i] << " ";
    }
}