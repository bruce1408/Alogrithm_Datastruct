#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
/**
 * 242 一个简单的数字
 * 给定一个数组，和一些指令，Q表示查询，C表示区间加上某个数
 * 比如数组是1，2，3，4，5，6，7，8，9，10
 * Q 2 输出2
 * C 1，3，1 表示区间1到3加上数字1
*/
typedef long long LL;
#define lowbit(i) ((i) & (-i))
const int N = 100010;
int a[N], b[N], n, m;
LL c[N]; // 树状数组
/**
 * 方法 1，即使很简单的写一个函数，每次对该区间进行加某数的操作
 * 但是方法超时，时间复杂度是O(m*n) m表示指令次数，n表示的区间长度
*/
void add_(int l, int r, int d)
{
    for (int i = l; i <= r; i++)
    {
        a[i] += d;
    }
}
/**
 * 方法 2，使用树状数组+差分的思想来做
 * 树状数组只支持单点操作，比如查找某个数字左边的的大于自己的个数
 * 差分的思想是构造一个差分数组，元数组是差分数组的前缀和
*/
void add(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += v;       
}

LL getSum(int x)
{
    LL sum = 0;
    for(int i=x;i>0;i-=lowbit(i))  
        sum += c[i];
    return sum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        add(i, a[i] - a[i-1]);

    while (m--)
    {
        char c;
        int l, r, d;
        cin >> c;
        if (c == 'Q')
        {
            cin >> d;
            cout << a[d] << endl;
        }
        else
        {
            cin >> l >> r >> d;
            add(l, r, d);
        }
    }
}