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
    vector<int> res = {1, 2, 2, 1, 2, 1};
    // int n = res.size();
    vector<int> p;
    cout << n << endl;
    for (int i = 0; i < n; i++)
        // update(i, res[i] - res[i - 1]);
        update(res[i], 1), p.push_back(getSum(res[i] - 1));
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
}
