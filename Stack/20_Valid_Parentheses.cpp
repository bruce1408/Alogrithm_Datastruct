#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * 20 验证括号
 * 验证是否是正确括号，成对出现
 * 
 * Input: "()"
 * Output: true
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * Input: "(]"
 * Output: false
 * 
 * Input: "([)]"
 * Output: false
*/

/**
 * 方法 1，使用栈， 把左括号都放进栈里面，然后如果是成对的右括号，那么弹出栈顶元素
 * 否则返回false
 * 这里成对的右括号，有两种方式，第一就是ascii码，成对的ascii码差值不大于2，如果大于2那么就是false
*/
bool isValid(string s)
{
    if (s.size() % 2)
        return false;
    stack<char> res;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            res.push(s[i]);
        }
        else
        {
            if (!res.empty() && abs(s[i] - res.top()) <= 2)
                res.pop();
            else
                return false;
        }
    }
    return res.empty();
}

/**
 * 方法 2，使用另外一种判断成对的方式
*/
bool isValid(string s)
{
    stack<char> res;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            res.push(s[i]);
        else
        {
            if (res.empty())
                return false;
            if (s[i] == ')' && res.top() != '(')
                return false; // 如果当前的符号和栈顶元素无法成对，那么就返回false
            if (s[i] == ']' && res.top() != '[')
                return false;
            if (s[i] == '}' && res.top() != '{')
                return false;
            res.pop();
        }
    }
    return res.empty();
}

int main()
{
}