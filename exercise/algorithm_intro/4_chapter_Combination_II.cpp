#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
/**
 * 组合数的计算
 * 组合数的计算公式如下：
 *      m       n!
 *    C n =  --------- 
 *            m!(n-m)!
 * 由公式可知上面的式子是通过3个整数的阶乘得到的
 * 一般有三种算法可以计算，定义直接计算法、递推公式计算法、定义式变形计算法
*/

/**
 * 方法 1，定义直接计算法
*/
LL comb(LL n, LL m)
{

}
int main()
{
    int n = 3;
    cout<<comb(n)<<endl;
}