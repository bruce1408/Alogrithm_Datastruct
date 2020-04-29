#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Given an integer, write a function to determine if it is a power of two.
 * Example 1:
 * Input: 1
 * Output: true
 * Explanation: 2^0 = 1
 * 
 * Example 2:
 * Input: 16
 * Output: true
 * Explanation: 2^4 = 16
 * 
 * 判断一个数是不是能够是2的幂次方。
 */

/**
 * 方法 1，因为一个数如果他是2的n次方的话，那么它的二进制数字一定是1000，10，100或者是1.也就是只有一个1才可以
 * 所以，他不可能出现2个以上的1，比如10001000这样的数字，这样的话肯定不是
*/
bool isPowerOfTwo(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt += (n & 1);
        n >>= 1;
        if (n > 1)
            return false;
    }
    return cnt == 1;
}

/**
 * 方法 2，如果一个数是2的次方数的话，根据上面分析，那么它的二进数必然是最高位为1，
 * 其它都为0，那么如果此时我们减1的话，则最高位会降一位，其余为0的位现在都为变为1，
 * 那么我们把两数相与，就会得到0，用这个性质也能来解题
*/
bool isPowerOfTwo2(int n)
{
    return (n > 0) && (!((n - 1) & n));
}

/**
 * 方法 3，首先单独解决0，如果输入是0的话，那么直接返回false，然后当前的数字除以2，
 * 判断余数是不是0，如果不是0直接返回false，否则，继续把当前数除以2的商作为下一轮判断的输入继续。
 * 没有上面的解法巧妙
*/
bool isPowerOfTwo3(int x)
{
    if (x == 0)
        return true;
    int remain = 0;
    while (x != 1)
    {
        remain = x % 2;
        if (remain != 0)
        {
            return false;
        }
        x /= 2;
    }
    return true;
}

int main()
{
    int a;
    cout << "输入0的时候退出程序：" << endl;
    while (true)
    {
        cin >> a;
        cout << "当前的数字a是：" << a << endl;
        if (a == 0)
        {
            break;
        }
        cout << "是否是2的幂次: " << isPowerOfTwo3(a) << endl;
    }
}
