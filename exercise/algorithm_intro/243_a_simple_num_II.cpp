#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

/**
 * 243 一个简单的整数问题2
 * 输入一个整数数组，然后分别两种操作
 * C l r d 表示区间 l-r 之间的数字加上d
 * Q l r 表示求区间 l-r 之间的和
 * 
 * 要求的是区间加操作，区间查询操作
 * 区间加操作还是使用差分来做
 * 如果要a[l-r]相加，那么就类似于差分的b[l] +=d, b[r+1]-d;
 * 
*/
#define lowbit(i) ((i) & (-i))
typedef long long LL;
const int N = 100010;
int n, m;
int a[N];
LL tr1[N], tr2[N]; // tr1维护的是b的前缀和，tr2表示的时候i*b[i]的前缀和

void update(LL tr[], int x, LL v)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}

LL getSum(LL tr[], int x)
{
    LL sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += tr[i];
    return sum;
}

// 求解前缀和部分，b1+b2+....bn * (x+1) - (b1+ 2*b2 + 3*b3 +......i*bi)
LL prefixSum(int x)
{
    return getSum(tr1, x) * (x + 1) - getSum(tr2, x);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
    {
        int y = a[i] - a[i - 1];
        update(tr1, i, y);
        update(tr2, i, (LL)y * i);
    }

    while (m--)
    {
        char c;
        int l, r, d;
        scanf("%s%d%d", &c, &l, &r);

        if (c == 'C')
        {
            scanf("%d", &d);
            update(tr1, l, d);
            update(tr1, r + 1, -d);

            update(tr2, l, l * d);
            update(tr2, r + 1, (r + 1) * (-d));
        }
        else
            cout << prefixSum(r) - prefixSum(l - 1) << endl;
    }
}