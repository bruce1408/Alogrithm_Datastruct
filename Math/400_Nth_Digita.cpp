#include <iostream>
using namespace std;
/**
 * 400 求解第N位的1
 * 个位数：1-9，一共9个,共计9位数字
 * 2位数：10-99,一共90个，共计180位数字
 * 3位数：100-999，一共900个，共计2700位数字
 * 4位数，1000-9999，一共9000个，共计36000位数字
 * 所以做法就是
 * 1、首先确实是几位数， 
 * 2、确实这个是几位数中的第几个数字，
 * 3、在这个数字中的是第几位
 * 每次减去9，减180，减900，直到剩下的数不满去位置，这个时候我们n-1/位数判断是第多少个数字
 */
int findNthDigit(int n) // 234 
{
    // start 表示数字开始的部分，digitbit表示位数，times表示对应位数的个数，
    // 1位数是9，2位数是90，3位数是900
    long long start = 1, digitBit = 1, times = 9;
    while (n > digitBit * times) // 求解是k位数
    {
        n -= digitBit * times;
        digitBit++, times *= 10; // 位数加1，同时对应的位数的个数乘10即可
        start *= 10; // 位数对一个的起点，1位数是1，二位数是10，三位数是100...
    }

    start += (n - 1) / digitBit;        // 第几个k位数
    n = n % digitBit ? n % digitBit : digitBit; 
    return to_string(start)[n-1] - '0'; // 得到数字的第几位
}

int main()
{
    cout << findNthDigit(15) << endl;
    return 0;
}