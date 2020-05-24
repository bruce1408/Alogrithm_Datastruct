#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

/**
 * 计算器，给定一个字符串，包含 (, ), +, -, *, /。
 * 使用栈来做
*/

/**
 * 方法 1，使用栈，考虑到左括号和右括号的时候，要考虑优先级
*/
int calculate(string s) {
    int n = s.size(), num = 0, curRes = 0, res = 0;
    char op = '+';
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            num = num * 10 + c - '0';
        } else if (c == '(') {
            int j = i, cnt = 0;
            for (; i < n; ++i) {
                if (s[i] == '(') ++cnt;
                if (s[i] == ')') --cnt;
                if (cnt == 0) break;
            }
            num = calculate(s.substr(j + 1, i - j - 1));
        }
        if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
            switch (op) {
                case '+': curRes += num; break;
                case '-': curRes -= num; break;
                case '*': curRes *= num; break;
                case '/': curRes /= num; break;
            }
            if (c == '+' || c == '-' || i == n - 1) {
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
 * 方法 2，自己做
*/
int calculate2(string s)
{
    int n = s.size(), res = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0')
        {
            num = num * 10 + s[i]- '0';
        }
        
    }
}
int main()
{
    string s = "2+3*(5-8)+4";
    calculate(s);
}