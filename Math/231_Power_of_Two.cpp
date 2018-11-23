#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


// 判断一个数是不是能够是2的幂次方。用的是位移操作、
// 因为一个数的二进制数字一定是1000，10，100或者是1.
bool isPowerOfTwo(int n)
{
    int cnt = 0;
    while(n)
    {
        cnt+=(n&1);
        n>>=1;
    }
    return cnt==1;
}

// method 2
/*
    如果一个数是2的次方数的话，根据上面分析，那么它的二进数必然是最高位为1，
    其它都为0，那么如果此时我们减1的话，则最高位会降一位，其余为0的位现在都为变为1，
    那么我们把两数相与，就会得到0，用这个性质也能来解题
*/ 
bool isPowerOfTwo2(int n)
{
    return (n>0) && (!((n-1) & n));
}
int main()
{
    int a = 0;
    cout<<isPowerOfTwo2(a)<<endl;
}