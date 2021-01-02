#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 字符串相加，和二进制相加很相似
*/

/**
 * 方法 1，从高位到地位进行相加，然后注意进位
*/
string addStrings1(string num1, string num2)
{
    string res;
    int t = 0, n = num1.size() - 1, m = num2.size() - 1;
    while (n >= 0 || m >= 0)
    {
        if (n >= 0)
            t += num1[n--] - '0';
        if (m >= 0)
            t += num2[m--] - '0';
        res = to_string(t % 10) + res; // res加的时候放在后面
        t /= 10;
    }
    if (t)
        res = '1' + res;
    return res;
}

/**
 * 方法 2 思路一样，写法不同 
*/
string addStrings2(string num1, string num2)
{
    string res = "";
    int m = num1.size(), n = num2.size(), i = m - 1, j = n - 1, carry = 0;
    while (i >= 0 || j >= 0)
    {
        int a = i >= 0 ? num1[i--] - '0' : 0;
        int b = j >= 0 ? num2[j--] - '0' : 0;
        int sum = a + b + carry;
        res.insert(res.begin(), sum % 10 + '0');
        carry = sum / 10;
    }
    return carry ? "1" + res : res;
}
