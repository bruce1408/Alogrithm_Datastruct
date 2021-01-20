#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200010;
int n = 6, a[N], c[N];
int Greater[N], Lower[N];
#define lowbit(i) ((i) & (-i))
/**
 * 使用树状数组来求解第k个数
 * c[i]表示的是从在号位之前，包含i号位lowbit(i)个整数之和
 * 然后计算的是当前数左边小于这个数的个数
*/
int getSum(int x)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += c[i];
    return sum;
}

void update(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += v;
}

int main()
{
    vector<int> res = {0, 1, 2, 2, 1, 2, 1};
    vector<int> p(n, 0);
    cout << n << endl;
    for (int i = 1; i <= n; i++)
    {
        p[i] = (getSum(res[i] - 1));
        update(res[i], 1);
        cout << "前缀和: " << getSum(res[i]) << endl;
    }
    cout << "左边小于该数的个数为：" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << c[i] << " ";
    cout << endl;
    // cout << getSum(1) << endl;
}
