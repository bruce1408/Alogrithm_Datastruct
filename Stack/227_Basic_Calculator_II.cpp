#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Implement a basic calculator to evaluate a simple expression string.
 * The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
 * The integer division should truncate toward zero
 * 
 * 只有加减乘除运算，没有包含括号。
*/

/**
 * 方法 1，简化版本的后缀表达式，如果当前是符号，那么+-的话直接符号栈出栈
*/
int calculate(string s)
{
    stack<int> st;
    char op = '+';
    long res = 0, n = s.size(), num = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0')
        {
            num = num * 10 + (s[i] - '0');
        }
        if ((s[i] < '0' && s[i] != ' ') || i == n - 1)
        {
            if (op == '+')
                st.push(num);
            if (op == '-')
                st.push(-num);
            if (op == '*' || op == '/')
            {
                int tmp = (op == '*') ? st.top() * num : st.top() / num;
                st.pop();
                st.push(tmp);
            }
            op = s[i];
            num = 0;
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

/**
 * 方法 2，使用字符流函数来做，// time: O(n)
 *         space: O(1)
 *         algorithm: use stringstream to simulate string input
 *         remember the last value in case of *, /
 *         3 + 2 * 2 * 4 + 1 
 *         + 2 * 2 * 2
 *         ans = ans + cur, last = cur
 *         ans = ans - cur, last = -cur
 *         ans = ans - last + last * cur, last = last * cur
 *         ans = ans - last + last / cur, last = last / cur
*/
int calculate2(string s)
{
    stringstream ss("+" + s);
    char op;
    int cur = 0, last = 0, ans = 0;
    while (ss >> op >> cur)
    {
        if (op == '+' || op == '-')
        {
            cur = op == '+' ? cur : -cur;
            ans += cur;
        }
        else
        {
            cur = op == '*' ? last * cur : last / cur;
            ans = ans - last + cur;
        }
        last = cur;
    }

    return ans;
}

/**
 * 方法 3，使用字符流来计算
*/
int calculate3(string s)
{
    istringstream iss('+' + s + '+');
    char op;
    long ans = 0, temp = 0;
    while (iss >> op)
    {
        if (op == '+' || op == '-')
        {
            ans += temp;
            iss >> temp;
            temp *= (op == '+' ? 1 : -1);
        }
        else
        {
            int n;
            iss >> n;
            if (op == '*')
                temp *= n;
            else
                temp /= n;
        }
    }
    return ans;
}

int main()
{
    string a = "30+4*5-6";
    cout << calculate4(a) << endl;
}