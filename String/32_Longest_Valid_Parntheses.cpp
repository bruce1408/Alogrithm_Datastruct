#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

/**
 * 32 记录有效括号的最长的的长度
 * 输入："(()"
 * 输出： 2
 * 
 * 输入：")()())"
 * 输出：4
 * 使用栈来记录，栈保存的是当前字符的下标，start 变量来记录合法括号串的起始位置
*/
int longestValidParentheses(string s)
{
    stack<int> st;
    int res = 0, start = -1, n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i); // 如果当前是左括号，直接入栈
        else
        {
            if (st.empty()) // 如果当前栈是空的话，说明之前已经匹配完了一段有效的长度，那么start为当前下标
                start = i;
            else // 如果当前栈不空
            {
                st.pop();       // 弹出栈顶元素
                if (st.empty()) // 再次判断栈是否是空，如果是空，说明有效的长度已经匹配到了，res更新为i-start和res的最大值即可
                    res = max(res, i - start);
                else // 如果说当前的栈取出栈顶元素还不是空，那么说明有效长度还没有统计结束，所以res更新为i-st.top()和res的最大值
                    res = max(res, i - st.top());
            }
        }
    }
    return res;
}

int main()
{
    string s = ")(()())";
    cout << longestValidParentheses(s) << endl;
}