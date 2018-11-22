#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int mySqrt(int x) 
{
    /*
        利用优化算法迭代求解。
        这里用牛顿法
        求解的是f(x)= x^2 -n ,f(x)=0 的情况 
    */
    double res = 1.0;
    double comp = 0;
    while(abs(comp-res)>=0.00001)
    {
        comp = res;
        res = (res + x/res)/2;
    }    
    return (int)res;
}

// 除了上面的这种方法之外。还有一种二分查找方法。后面再补吧
int main()
{
    int a = 8;
    cout<<mySqrt(a);
}