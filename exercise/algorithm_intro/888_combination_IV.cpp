#include <iostream>
#include <vector>
using namespace std;

const int N = 5010;
int primes[N], cnt, sum[N];
bool visited[N];

void getprimes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (visited[i] == false)
        {
            primes[cnt++] = i;
            for (int j = i + i; j <= n; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

// 求n的阶乘的p因子的个数
int get(int n, int p)
{
    int t = 0;
    while (n)
    {
        t += n / p;
        n /= p;
    }

    return t;
}

vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;

    for (int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }

    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

int main()
{
    int a, b;
    cin >> a >> b;
    ;
    getprimes(a);

    for (int i = 0; i < cnt; i++)
    {
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p);
    }

    vector<int> res;
    res.push_back(1);

    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < sum[i]; j++)
        {
            res = mul(res, primes[i]);
        }
    }

    for (int i = res.size() - 1; i >= 0; i--)
    {
        printf("%d", res[i]);
    }
    cout << endl;
}
