#include <iostream>
#include <vector>
using namespace std;

/**
 * 22,括号生成
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * For example, given n = 3, a solution set is:
 * 
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 * 有效的括号生成是：
 * 1、任意前缀中，左括号数量>=右括号数量
 * 2、左括号数量==右括号数量
*/

/**
 * 方法 1，使用dfs深度优先搜索来计算
 * 如果左边的括号个数lc和右边的括号个数rc相同等于n，那么就存到结果数组里面去
 * 如果左边的括号小于n，那么左边括号加1，
 * 如果右边的括号小于n且左边括号大于右边括号，右边括号加1
*/
void dfs(int n, int lc, int rc, string s, vector<string> &res);
vector<string> generateParenthesis(int n)
{
    vector<string> res;
    dfs(n, 0, 0, "", res);
    return res;
}

void dfs(int n, int lc, int rc, string s, vector<string> &res)
{
    if (lc == n && rc == n)
        res.push_back(s);
    else
    {
        if (lc < n) // 如果左括号小于n，可以添加左括号
            dfs(n, lc + 1, rc, s + "(", res);
        if (lc > rc) // 左括号大于右括号，那么可以在当前序列添加右括号
            dfs(n, lc, rc + 1, s + ")", res);
    }
}

/**
 * 方法 2，同样的思路，不同的写法
*/
vector<string> result;
void helper(string s, int n, int l, int r);
vector<string> generateParenthesis1(int n)
{
    helper("", n, 0, 0);
    return result;
}
void helper(string s, int n, int l, int r)
{
    if (l < r || l > n || r > n)
        return; // 越界判断
    if (l == n && r == n)
    {
        result.push_back(s);
        return;
    }
    helper(s + "(", n, l + 1, r);
    helper(s + ")", n, l, r + 1);
}

int main()
{
    int n = 3;
    for (auto s : generateParenthesis(n))
    {
        cout << s << endl;
    }
}