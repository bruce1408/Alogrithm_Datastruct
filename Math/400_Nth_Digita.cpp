#include <iostream>
using namespace std;
/**
 * 400 求解第N位的1
 * 个位数：1-9，一共9个,共计9位数字
 * 2位数：10-99,一共90个，共计180位数字
 * 3位数：100-999，一共900个，共计2700位数字
 * 4位数，1000-9999，一共9000个，共计36000位数字
 * 每次减去9，减180，减900，直到剩下的数不满去位置，这个时候我们n-1/位数判断是第多少个数字，然后
 * （n-1）%位数是取第几位
 */
int findNthDigit(int n) // 234
{
    long long start = 1, digitBit = 1, times = 9;
    while (n > digitBit * times) // 求解是k位数
    {
        n -= digitBit * times;
        digitBit++;
        times *= 10;
        start *= 10; // 开始的起点是多少
    }
    start += (n - 1) / digitBit;        // 第几个k位数
    string t = to_string(start);        // 得到数字几
    return t[(n - 1) % digitBit] - '0'; // 得到数字的第几位
}

int main()
{
    cout << findNthDigit(15) << endl;
    return 0;
}