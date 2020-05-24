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
 * 有几个问题
 * 第一，就是出现最大的数怎么办，越界的情况如何讨论
 * 第二，输入的是字符串，怎么转成后缀表达式那种的数据结构，例如 9 + ( 3 - 1 ) * 3 + 10 / 2 转成 9 3 1 - 3 * 10 + 10 2 / +
 * 第三，
 * 这种算法自己构造了一个新的数据结构，ListStack 类型，保存两个元素，一个是整型val，一个是操作符， 然后保存到vector，
 * 如果当前字符是数字的话，那么val保存数字，操作符没有，用‘.’来表示，如果是操作符'+'，那么数字就用INT_MAX来保存。
 * 比如 9., 3., 1. 表示数字，操作符是., *号操作符，整型是INT_MAX。
 * 最后转化为一个后缀表达式，然后再利用栈操作，后缀表达式，只要是数字，就入栈，然后遇到操作符，就把栈的两个元素出栈进行运算，结果入栈，
 * 继续进行即可。
 * 
 * 这里有个问题就是可以运算最大数范围内的值，如果是最大数，那么就是识别成了运算符。所以，涉及到最大数不能运算。
 * 
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
    int num = 0, n = s.size();
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int cur = i;
            while (cur < n && '0' <= s[cur])
            {
                num = num * 10 + (s[cur++] - '0');
            }
            if (cur - i != 1 && cur >= 1)
                i = cur - 1;
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
            else if (s[i] == ' ')
            {
                continue;
            }
            else
            {
                while (!symbol.empty() && (symbol.top() == '*' || symbol.top() == '/'))
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
    // 最后把符号放入res里面
    while (!symbol.empty())
    {
        ListStack a;
        a.val = INT_MAX;
        a.sym = symbol.top();
        symbol.pop();
        res.push_back(a);
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
            int x = 0, y = 0;
            if (!numStack.empty())
            {
                y = numStack.top();
                numStack.pop();
            }
            if (!numStack.empty())
            {
                x = numStack.top();
                numStack.pop();
            }
            switch (temp[i].sym)
            {
            case '+':
                sumNum = x + y;
                break;
            case '-':
                sumNum = x - y;
                break;
            case '*':
                sumNum = x * y;
                break;
            case '/':
                sumNum = x / y;
                break;
            }
            numStack.push(sumNum);
        }
    }
    return numStack.top();
}

/**
 * 方法 2，这道题目，没有乘除操作，所有比较简单的使用加减即可。
 * 每次判断符号和是否是数字，如果遇到括号，那么就把之前相加的结果入栈，符号入栈，res重新置0；
 * 遇到右括号，栈顶符号*res，res+=栈顶元素，我们需要一个栈来辅助计算，用个变量sign来表示当前的符号，
 * 我们遍历给定的字符串s，如果遇到了数字，由于可能是个多位数，所以我们要用while循环把之后的数字都读进来，
 * 然后用sign*num来更新结果res；如果遇到了加号，则sign赋为1，如果遇到了符号，则赋为-1；如果遇到了左括号，
 * 则把当前结果res和符号sign压入栈，res重置为0，sign重置为1；如果遇到了右括号，结果res乘以栈顶的符号，
 * 栈顶元素出栈，结果res加上栈顶的数字，栈顶元素出栈。
*/
int calculate2(string s)
{
    int res = 0, sign = 1, n = s.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0')
        {
            int num = 0;
            while (s[i] >= '0' && i < n)
            {
                num = num * 10 + (s[i++] - '0');
            }
            res += num * sign;
            --i;
        } 
        else if (s[i] == '(')
        {
            st.push(res);
            st.push(sign);
            res = 0;
            sign = 1;
        }
        else if (s[i] == ')')
        {
            res *= st.top();
            st.pop();
            res += st.top();
            st.pop();
        }
        else if (s[i] == '-')
        {
            sign = -1;
        }
        else if (s[i] == '+')
        {
            sign = 1;
        }
    }
    return res;
}

int main()
{
    string s = "-1+3+(2-3)+4";
    calculate2(s);
}