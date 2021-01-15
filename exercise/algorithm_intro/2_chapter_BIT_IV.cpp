#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/**
 * 楼兰图腾数字
 * 给出一个长度为nn的数组，完成以下两种操作：
 * 1. 将第ii个数加上kk
 * 2. 输出区间[i,j][i,j]内每个数的和
 * 详细步骤思路参考：
 * 从左向右依次遍历每个数a[i]，使用树状数组统计在i位置之前所有比a[i]大的数的个数、以及比a[i]小的数的个数。
 * 统计完成后，将a[i]加入到树状数组。
 * 从右向左依次遍历每个数a[i]，使用树状数组统计在i位置之后所有比a[i]大的数的个数、以及比a[i]小的数的个数。
 * 统计完成后，将a[i]加入到树状数组
 * https://www.acwing.com/solution/content/13818/
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
    
    LL resV = 0, resA =0;
    memset(c, 0 , sizeof c);
    for(int i=n;i>0;i--)
    {
        int y = a[i];
        resV+=g[i] * (LL)(getSum(n) - getSum(y));
        resA+=l[i] *(LL)(getSum(y));
        update(y, 1);
    }
    
    printf("%lld %lld\n", resV, resA);
    
}
