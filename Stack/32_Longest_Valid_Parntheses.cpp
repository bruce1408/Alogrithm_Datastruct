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
 */

/**
 * 方法 1，推荐做法，也可以用动态规划，但是状态划分比较绕
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

/**
 * 方法 2，使用双指针算法来做，left和right分别表示两个指针，记录左括号和右括号出现的次数，当遇见左括号，left自增1，否则，右括号自增1，
 * 最长的括号序列是左括号等于右括号的次数，更新结果，如果右括号大于左括号，那么left right 次数重新置位0，说明当前不合法。
 * 如果是(()长度应该是2，但是上述条件cover不到这种情况，所以就再从后往前遍历一遍即可，采用类似的机制，不过这次不是右括号大于左括号了
 * 而是，左括号大于右括号那么就置位0，最后返回res
*/
int longestValidParentheses2(string s)
{
    int res = 0, left = 0, right = 0, n = s.size();
    for (int i = 0; i < n; ++i)
    {
        (s[i] == '(') ? ++left : ++right; // 如果是左括号left++，否则right++
        if (left == right)                // 如果是左右括号的数目相等，那么更新匹配数res的值
            res = max(res, 2 * right);
        else if (right > left) // 如果是右边大于左边，那么左右计数全都置0
            left = right = 0;
    }
    left = right = 0; // 再从后往前遍历
    for (int i = n - 1; i >= 0; --i)
    {
        (s[i] == '(') ? ++left : ++right;
        if (left == right)
            res = max(res, 2 * left);
        else if (left > right) // 这里不同的地方就是左括号数大于右括号数就重新置为0
            left = right = 0;
    }
    return res;
}

/**
 * 方法 3，使用动态规划来做，思路比较绕
 * 
*/
int longestValidParentheses3(string s)
{
    if (s.empty())
        return 0;
    vector<int> dp(s.size() + 1, 0);
    int res = 0;
    for (int i = 2; i <= s.size(); i++)
    {
        if (s[i - 1] == ')')
        {
            // 这个好理解
            if (s[i - 2] == '(')
                dp[i] = dp[i - 2] + 2;
            else if (i - dp[i - 1] - 1 > 0 && s[i - dp[i - 1] - 2] == '(')
                dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
            res = max(res, dp[i]);
        }
    }
    return res;
}

int main()
{
    string s = ")(()())";
    cout << longestValidParentheses(s) << endl;
}