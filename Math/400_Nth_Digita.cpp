#include<iostream>
using namespace std;
/*
       个位数：1-9，一共9个,共计9个数字
     * 2位数：10-99,一共90个，共计180个数字
     * 3位数：100-999，一共900个，共计270个数字
     * 4位数，1000-9999，一共9000个，共计36000个数字
     * 每次减去9，减180，减900，直到剩下的数不满去位置，这个时候我们n-1/位数判断是第多少个数字，然后
     * （n-1）%位数是取第几位
*/
int findNthDigit(int n)  // 234
{
    long long start = 1, digitBit= 1, times=9;
    while(n>digitBit*times) // 234- 9 - 180 = 45,start = 100, digitBit=3,
    {
        n -= digitBit * times;
        digitBit++;
        times *= 10;
        start *= 10; // 开始的起点是多少
    }
    start += (n - 1)/digitBit;
    string t = to_string(start);
    return t[(n-1)%digitBit] - '0';
}

int main()
{
    cout<<findNthDigit(234);
    return 0;
}