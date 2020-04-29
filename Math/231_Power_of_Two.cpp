#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


/**
 * Given an integer, write a function to determine if it is a power of two.
 * Example 1:
 * Input: 1
 * Output: true
 * Explanation: 20 = 1
 * 
 * Example 2:
 * Input: 16
 * Output: true
 * Explanation: 24 = 16
 * 
 * 判断一个数是不是能够是2的幂次方。
 */ 

/**
 * 方法 1，因为一个数的二进制数字一定是1000，10，100或者是1.
*/
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

/**
 * 方法 2，如果一个数是2的次方数的话，根据上面分析，那么它的二进数必然是最高位为1，
 * 其它都为0，那么如果此时我们减1的话，则最高位会降一位，其余为0的位现在都为变为1，
 * 那么我们把两数相与，就会得到0，用这个性质也能来解题
*/ 
bool isPowerOfTwo2(int n)
{
    return (n>0) && (!((n-1) & n));
}

bool isPowerOfTwo3(int x)
{
    while(x)
    {
        x = x>>1;
        x&1
    }
}
int main()
{
    int a = 0;
    cout<<isPowerOfTwo2(a)<<endl;
}