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

// 求n的阶乘的p因子的个数，n!中这个素数的个数，n! = (n/p + n/p^2 + n/p^3 + .....) 个质因子p
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
    // 得到小于a的所有素数
    getprimes(a);

    // 遍历每一个素数，然后求解n!中这个素数的个数，n! = (n/p + n/p^2 + n/p^3 + .....) 个质因子p
    for (int i = 0; i < cnt; i++)
    {
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p); // 得到质因子数组sum
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

    // 高精度乘法结果输出
    for (int i = res.size() - 1; i >= 0; i--)
    {
        printf("%d", res[i]);
    }
    cout << endl;
}
