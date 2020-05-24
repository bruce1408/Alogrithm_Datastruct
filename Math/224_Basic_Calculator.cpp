#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

/**
 * Implement a basic calculator to evaluate a simple expression string.
 * The expression string may contain open ( and closing parentheses ), 
 * the plus + or minus sign -, non-negative integers and empty spaces 
 * 
 * 给定一个字符的表达式，实现一个计算器，核心是使用栈来完成中缀表达式 -> 后缀表达式
 * 然后后缀表达式->计算结果
*/

/**
 * 方法 1，使用栈的经典应用，计算表达式的思路来解这道题目。具体思路可以参看中缀表达式，后缀表达式；
*/
struct ListStack
{
    int val;
    char sym;
    // ListStack(int x) : val(x), sym{''} {}
};

vector<ListStack> infixTosuffix(string s)
{
    vector<ListStack> res;
    stack<char> symbol;
    vector<int> tempNum;
    int num = 0, n = s.size(), i = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int cur = i;
            char temp = s[i];
            while (cur < n && '0' <= s[cur])
            {
                num = num * 10 + (s[cur++] - '0');
            }
            if (cur - i != 1)
                i = cur;
            ListStack a;
            a.val = num;
            a.sym = '.';
            res.push_back(a);
        }
        else if (s[i] == '(')
        {
            symbol.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (symbol.top() != '(')
            {
                ListStack a;
                a.val = INT_MAX;
                a.sym = symbol.top();
                symbol.pop();
                res.push_back(a);
            }
            symbol.pop();
        }
        else if (symbol.empty())
        {
            symbol.push(s[i]);
        }
        else
        {
            if (s[i] == '-' | s[i] == '+')
            {
                while (!symbol.empty() && (symbol.top() == '*' || symbol.top() == '/' || symbol.top() == '-' || symbol.top() == '+'))
                {
                    ListStack a;
                    a.val = INT_MAX;
                    a.sym = symbol.top();
                    res.push_back(a);
                    symbol.pop();
                }
                symbol.push(s[i]);
            }
            else
            {
                while (symbol.empty() && (symbol.top() == '*' || symbol.top() == '/'))
                {
                    ListStack a;
                    a.val = INT_MAX;
                    a.val = symbol.top();
                    res.push_back(a);
                    symbol.pop();
                }
                symbol.push(s[i]);
            }
            // symbol.push(s[i]);
        }
        num = 0;
    }
    while (!symbol.empty())
    {
        ListStack a;
        a.val = INT_MAX;
        a.sym = symbol.top();
        symbol.pop();
        res.push_back(a);
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].val << " " << res[i].sym << endl;
    }

    return res;
}
int calculate(string s)
{
    int sumNum = 0;
    stack<int> numStack;
    //第一步，把中缀表达式转化为后缀表达式
    vector<ListStack> temp = infixTosuffix(s);
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i].val != INT_MAX)
        {
            numStack.push(temp[i].val);
        }
        else
        {
            int y = numStack.top();
            numStack.pop();
            int x = numStack.top();
            numStack.pop();
            switch (temp[i].sym)
            {
            case '+':
                sumNum = sumNum + x + y;
                break;
            case '-':
                sumNum = sumNum + x - y;
                break;
            case '*':
                sumNum = sumNum + x * y;
                break;
            case '/':
                sumNum = sumNum + x / y;
                break;
            }
            numStack.push(sumNum);
        }
    }
    cout << numStack.top() << endl;
    return 0;
}

int main()
{
    string s = "9+(3-1)*3+10/2";
    // string s = "1+2*3+(4*5+6)*7";
    int a = 1;
    while (a)
    {
        a--;
        // cin >> s;
        cout << calculate(s) << endl;
    }
}