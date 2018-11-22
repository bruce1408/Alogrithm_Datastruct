#include<iostream>
#include<cmath>
using namespace std;

// 算法超时了


double power(double x, int n)
{
    
    if(x==0) return 0.0;
    if(n==0) return 1.0;
    double half = power(x, n/2);
    if(n%2==0) return half * half;
    else return half * half * x;
}


double myPow(double x, int n)
{
    if(n<0) return 1/power(x, -n);
    else return power(x, n);
}


//
int main()
{
    double x = 2,n = 10;
    cout<<myPow(x, n);
    return 0;
}