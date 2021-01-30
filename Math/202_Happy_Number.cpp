#include <iostream>
#include <set>
using namespace std;

/**
 * 202 快乐数
 * 寻找HAPPY num 特点就是如果不是1的话，那么肯定会出现4.否则就是死循环，不可能出现死循环的，
 */

/**
 * 方法 1，使用环来做，因为最坏的情况
 * 这道题其实就是包装后的环形链表，其中
 * 慢指针就是每次把数字各位求一次平方和
 * 快指针就是每次把数字各位求两次平方和
 * 有两种情况
 * 是快乐数：最后两个指针都会变成1，重合在一起
 * 不是快乐数：相当于一个环，快慢指针总会在某个数处相遇
 * 即：不管是不是快乐数，快慢指针最终都会汇聚到一个数上，我们只需要判断这个数是不是1即可
*/
int get(int x)
{
    int res = 0;
    while (x)
    {
        res += (x % 10) * (x % 10);
        x /= 10;
    }
    return res;
}

bool isHappy(int x)
{
    int fast = get(x), slow = x;
    while (fast != slow)
    {
        fast = get(get(fast));
        slow = get(slow);
    }
    return fast == 1;
}

int main()
{
    int a = 19;
    cout << isHappy(a);
    return 0;
}