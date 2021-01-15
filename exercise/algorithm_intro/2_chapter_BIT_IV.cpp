#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/**
 * 楼兰图腾数字
 * 
*/
const int N = 2000010;

int c[N], a[N], n;

int g[N], l[N];
typedef long long LL;
#define lowbit(i) ((i)&(-i))

// 更新函数
void update(int x, int v)
{
    for(int i=x; i<=n; i+=lowbit(i))
        c[i] +=v;
}

// 函数返回前x项之和
int getSum(int x)
{
    int sum = 0;
    for(int i=x; i>0; i-=lowbit(i))
    {
        sum += c[i];
    }
    return sum;
}

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    
    for(int i=1;i<=n;i++)
    {
        int y = a[i];
        g[i] = getSum(n) - getSum(y); // y+1 ~ n;
        l[i] = getSum(y-1);
        update(y, 1);
    }
    
    LL res1 = 0, res2 =0;
    memset(c, 0 , sizeof c);
    for(int i=n;i>0;i--)
    {
        int y = a[i];
        res1+=g[i] * (LL)(getSum(n) - getSum(y));
        res2+=l[i] *(LL)(getSum(y));
        update(y, 1);
    }
    
    printf("%lld %lld\n", res1, res2);
    
}
