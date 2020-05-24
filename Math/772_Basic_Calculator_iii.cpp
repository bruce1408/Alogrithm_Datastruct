#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

/**
 * 计算器，给定一个字符串，包含 (, ), +, -, *, /。
 * 使用栈来做
*/

/**
 * 方法 1，使用栈，考虑到左括号和右括号的时候，要考虑优先级
*/
int calculate(string s)
{
    int n = s.size(), num = 0, curRes = 0, res = 0;
    char op = '+';
    for (int i = 0; i < n; ++i)
    {
        char c = s[i];
        if (c >= '0' && c <= '9')
        {
            num = num * 10 + c - '0';
        }
        else if (c == '(')
        {
            int j = i, cnt = 0;
            for (; i < n; ++i)
            {
                if (s[i] == '(')
                    ++cnt;
                if (s[i] == ')')
                    --cnt;
                if (cnt == 0)
                    break;
            }
            num = calculate(s.substr(j + 1, i - j - 1));
        }
        if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1)
        {
            switch (op)
            {
            case '+':
                curRes += num;
                break;
            case '-':
                curRes -= num;
                break;
            case '*':
                curRes *= num;
                break;
            case '/':
                curRes /= num;
                break;
            }
            if (c == '+' || c == '-' || i == n - 1)
            {
                res += curRes;
                curRes = 0;
            }
            op = c;
            num = 0;
        }
    }
    return res;
}
/**
 * 方法 2，队列来解决
*/
class Solution
{
public:
    int calculate(string s)
    {
        int i = 0;
        return parseExpr(s, i);
    }

private:
    int parseExpr(string &s, int &i)
    { // parse the expression
        vector<int> nums;
        char op = '+';
        int n;
        for (; i < s.length() && op != ')'; ++i)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            if (s[i] == '(')
            {
                n = parseExpr(s, ++i);
            }
            else
            {
                n = parseNum(s, i);
            }
            switch (op)
            {
            case '+':
                nums.push_back(n);
                break;
            case '-':
                nums.push_back(-n);
                break;
            case '*':
                nums.back() *= n;
                break;
            case '/':
                nums.back() /= n;
                break;
            }
            op = s[i];
        }
        int res = 0;
        for (int n : nums)
        {
            res += n;
        }
        return res;
    }

    int parseNum(string &s, int &i)
    { // parse the num
        int n = 0;
        while (i < s.length() && isdigit(s[i]))
        {
            n = 10 * n + s[i++] - '0';
        }
        return n;
    }
};

/**
 * 方法 3，使用队列来做
*/
int helper3(queue<char> temp)
{
    int num = 0, pre = 0, sum = 0;
    char op = '+';
    while (!temp.empty())
    {
        char c = temp.front();
        if (c >= '0')
        {
            num = num * 10 + c - '0';
        }
        else if (c == '(')
        {
            num = helper3(temp);
        }
        else
        {
            switch (op)
            {
            case '+':
                sum += pre;
                pre = num;
                break;
            case '-':
                sum += pre;
                pre = -num;
                break;
            case '*':
                pre *= num;
                break;
            case '/':
                pre /= num;
                break;
            }
            if (c == ')')
                break;
            op = c;
            num = 0;
        }
    }
    return sum + pre;
}
int calculate3(string s)
{
    queue<char> temp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            temp.push(s[i]);
        }
    }
    return helper3(temp);
}
int main()
{
    string s = "2+3*(5-8)+4";
    Solution st;
    // cout << st.calculate(s) << endl;
    cout << calculate3(s) << endl;
}