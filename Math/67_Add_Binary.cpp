#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

/**
 * Given two binary strings, return their sum (also a binary string).
 * The input strings are both non-empty and contains only characters 1 or 0.
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
*/

/**
 * 方法 1，逻辑思路解法，代码冗余，时间复杂度不是很高，但是占用空间比较多，AC时间是8ms，是方法 2的一倍。
 * 虽然思路自然，但是写法太麻烦，考虑的边界条件太多了。不是很好的方法。
*/
string addBinary(string a, string b)
{
    char carry = '0';
    stack<char> res;
    stack<char> temp1;
    stack<char> temp2;
    for (auto i : a)
        temp1.push(i);
    for (auto i : b)
        temp2.push(i);
    while (!temp1.empty() && !temp2.empty())
    {
        if (temp1.top() == temp2.top() && temp1.top() == '1')
        {
            if (carry == '0')
            {
                res.push('0');
                carry = '1';
            }
            else
            {
                res.push('1');
                carry = '1';
            }
        }
        else if ((temp1.top() == '0' && temp2.top() == '1') || (temp1.top() == '1' && temp2.top() == '0'))
        {
            if (carry == '0')
            {
                res.push('1');
            }
            else
            {
                res.push('0');
                carry = '1';
            }
        }
        else if (temp1.top() == temp2.top() && temp1.top() == '0')
        {
            if (carry == '0')
            {
                res.push('0');
            }
            else
            {
                res.push('1');
                carry = '0';
            }
        }
        temp1.pop();
        temp2.pop();
    }
    while (!temp1.empty())
    {
        if (carry == '0')
        {
            res.push(temp1.top());
        }
        else
        {
            if (temp1.top() == '1')
            {
                res.push('0');
                carry = '1';
            }
            else
            {
                res.push('1');
                carry = '0';
            }
        }
        temp1.pop();
    }

    while (!temp2.empty())
    {
        if (carry == '0')
        {
            res.push(temp2.top());
        }
        else
        {
            if (temp2.top() == '1')
            {
                res.push('0');
                carry = '1';
            }
            else
            {
                res.push('1');
                carry = '0';
            }
        }
        temp2.pop();
    }
    if (carry == '1')
        res.push('1');
    string t = "";
    while (!res.empty())
    {
        t += res.top();
        res.pop();
    }
    return t;
}

/**
 * 方法 2，相比方法1就是太简单了，写法优雅。
*/
string addBinary1(string a, string b)
{
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    string ans;
    while (i >= 0 || j >= 0)
    {
        int s = (i >= 0 ? a[i--] - '0' : 0) +
                (j >= 0 ? b[j--] - '0' : 0) +
                carry;
        carry = s >> 1;
        ans += '0' + (s & 1);
    }
    if (carry)
        ans += '1';
    return {ans.rbegin(), ans.rend()};
}

int main()
{
    string a = "100";
    string b = "110010";
    for (auto i : addBinary1(a, b))
    {
        cout << i << " ";
    }
}