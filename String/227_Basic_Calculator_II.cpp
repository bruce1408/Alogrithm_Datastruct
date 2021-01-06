#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

/**
 * 227,基本计算器
 * 给定一个字符串，例如"3 + 2 /1",然后返回这个表达式的计算结果
 * 这里使用两个栈，一个是运算符，一个是数字
 * 每次遍历当前字符，如果是空格直接跳过，如果是数字的话，那么遍历到数字结尾，然后把这个
 * 字符串数字转成数字即可，然后对当前这个数字保存到栈里面去，并把指针指向前一个位置
 * 如果当前不是数字，那么可能是运算符，所以首先需要判断运算符栈是不是空栈，如果是空栈，直接保存运算符即可
 * 否则就执行eval函数，eval就是把数字栈中的两个数字取出来，然后和运算符里面的进行运算，结果再保存到
 * 数字栈即可。
*/
stack<int> nums;
stack<char> op;

void eval()
{
    int r;
    int b = nums.top();
    nums.pop();
    int a = nums.top();
    nums.pop();
    char c = op.top();
    op.pop();
    if (c == '-')
        r = a - b;
    else if (c == '+')
        r = a + b;
    else if (c == '*')
        r = a * b;
    else
        r = a / b;
    nums.push(r);
}

int calculate(string s)
{
    unordered_map<char, int> pr;
    pr['+'] = pr['-'] = 1, pr['*'] = pr['/'] = 2;
    for (int i = 0; i < s.size(); i++)
    {
        auto c = s[i];
        if (c == ' ')
            continue;
        if (isdigit(c))
        {
            int j = i, num = 0;
            while (j < s.size() && isdigit(s[j]))
                num = num * 10 + (s[j++] - '0');
            nums.push(num); // 把当前的数字存入栈中
            i = j - 1;
        }
        else
        {
            while (op.size() && pr[op.top()] >= pr[c])
                eval();
            op.push(c);
        }
    }
    while (op.size())
        eval();
    return nums.top();
}

int main()
{
    string a = "3/2";
    cout << calculate(a) << endl;
}