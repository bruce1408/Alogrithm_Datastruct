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
vector<int> res = {0, 1, 2, 2, 1, 2, 1};
vector<int> p(n, 0);
int main()
{
    // 第一个模板，单点修改，区间查询，单点加，区间和
    for (int i = 1; i <= n; i++)
    {
        update(i, res[i]);
        // update(res[i], 1); // 这种写法是统计个数
    }
    cout << "前缀和的：" << getSum(6) << endl;
    update(2, 4);                              // 给第二个数加上4
    cout << getSum(4) - getSum(3 - 1) << endl; // 求区间[3, 4]的和
    cout << getSum(4) - getSum(4 - 1) << endl; // 那么就是单点查询

    // 第二个模板，单点查询， 区间修改，单点和，区间加
}
