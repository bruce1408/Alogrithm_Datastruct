#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/**
 * 方法 1、字符转数字 利用流方法简单
 * */
int strTonum(string a)
{
    int res;
    stringstream stream;
    stream << a;
    stream >> res;
    return res;
}

/**
 * 方法 2、不是利用流，而是更加一般的方法； 
 * 按照几个条件去处理，先处理空格 -> 然后正负号 -> 然后字符到数字 -> 越界 -> 输出
 * 简称 空·符·数算法(瞎编吧)
 * */
int strTonum2(string str)
{
    if (str.empty())
        return 0;
    int i = 0, res = 0, sign = 1, n = str.size();
    // 排除开头的空格
    while (str[i] == ' ' && i < n)
        ++i;
    // 如果是有符号的，那么记录符号即可
    if (str[i] == '+' || str[i] == '-')
    {
        sign = (str[i++] == '+') ? 1 : -1;
    }
    while (str[i] >= '0' && str[i] <= '9' && i < n)
    {
        // 考虑溢出问题。如果是这个数大于21xxxxxx467，那么就是取最大的那个越界边界。
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        res = 10 * res + str[i++] - '0';
    }
    return res * sign;
}

/**
 * 方法 3,和上面思路一样，就是写法有些不同
 * 按照几个条件去处理，空格->正负号->字符到数字->越界->输出
 * 然后在考虑是否越界
*/
class Solution
{
public:
    int myAtoi(string str)
    {
        long res = 0;
        int k = 0;
        int n = str.size();
        // 排出空格
        while (k < n && str[k] == ' ')
            k++;

        // 空格之后直接结束的话返回0
        if (k == n)
            return 0;
        // 判断数据的符号是什么
        int minus = 1;
        if (str[k] == '+' || str[k] == '-')
            minus = (str[k++] == '-') ? -1 : 1;

        // 判断数字部分
        while (k < n && str[k] >= '0' && str[k] <= '9')
        {
            // 直接得出当前的数字，然后越界就对其进行相应的处理
            res = res * 10 + str[k] - '0';
            if (minus * res > INT_MAX)
                return INT_MAX;
            if (minus * res < INT_MIN)
                return INT_MIN;
            k++;
        }
        return res * minus;
    }

    // 数字是整型，就按照整型来
    int myAtoi(string str)
    {
        int res = 0;
        int k = 0;
        while (k < str.size() && str[k] == ' ')
            k++;
        if (k == str.size())
            return 0;

        int minus = 1;
        if (str[k] == '-' || str[k] == '+')
            minus = (str[k++] == '-') ? -1 : 1;
        // 判断数字部分
        while (k < str.size() && str[k] >= '0' && str[k] <= '9')
        {
            // 不管符号，直接判断是否越界，int最大的数字是2147483647, 所以只要大于7肯定越界
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[k] - '0') > 7))
            {
                return (minus == -1) ? INT_MIN : INT_MAX;
            }
            res = res * 10 + (str[k++] - '0');
        }
        return res * minus;
    }
};

/**
 * 方法 4，手写再实现一遍
 * */
int strTonum3(string s)
{
    int n = s.size();
    int i = 0, minus = 1; // minus=1表示正数
    while (i < n && s[i] == ' ')
        i++;
    s = s.substr(i, n - i);
    i = 0;
    if (s[i] == '-' || s[i] == '+')
    {
        minus = (s[i] == '-') ? 0 : 1;
        i++;
    }
    int j = i;
    while (j < s.size() && s[j] >= '0' && s[j] <= '9')
        j++;
    string str = s.substr(i, j - i);
    int res = 0;
    for (int i = 0; i < str.size(); i++)
    {
        cout << res << endl;
        if (res > INT_MAX / 10 || ((res == INT_MAX / 10) && (s[i] - '0') > 7))
            return (minus == 1) ? INT_MAX : INT_MIN;
        res = res * 10 + (str[i] - '0');
    }
    if (minus)
        return res;
    return -1 * res;
}

int main()
{
    string a = "-2147483648";
    cout << strTonum3(a) << endl;
    return 0;
}