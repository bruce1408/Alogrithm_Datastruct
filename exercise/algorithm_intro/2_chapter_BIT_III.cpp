#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200010;
int n, a[N], c[N];
int Greater[N], Lower[N];
#define lowbit(i) ((i) & (-i))
/**
 * 使用树状数组来求解第k个数
*/
int getSum(int x)
{
    int sum = 0;
    for (int i = x; i < N; i += lowbit(i))
        sum += c[i];
    return sum;
}

int findKth(int k)
{
    int l = 1, r = N, mid;
    while (l < r)
    {
        mid = (l + r) >> 1;
        if (getSum(mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
