#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

/**
 * 241 楼兰图腾
*/
typedef long long LL;
#define lowbit(i) ((i) & (-i))
const int N = 200010;
int n, a[N], c[N];
int G[N], L[N];

void update(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += v;
}

int getSum(int x)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += c[i];
    return sum;
}

int main()
{
    cin >> n;
    LL resA = 0, resV = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        update(a[i], 1);
        int y = a[i];
        // 左边的数小于这个数的个数
        L[i] = getSum(y - 1);
        // 左边的数大于这个数的个数
        G[i] = getSum(n) - getSum(y);
    }
    memset(c, 0, sizeof c);
    for (int i = n; i > 0; i--)
    {
        int y = a[i];
        update(y, 1);
        resA += L[i] * (LL)getSum(y - 1);
        resV += G[i] * (LL)(getSum(n) - getSum(y));
    }
    cout << resV << " " << resA;
}