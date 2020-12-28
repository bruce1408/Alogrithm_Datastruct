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
 * 如果左边的括号个数lc和右边的括号个数rc相同，那么就存到结果数组里面去
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
        if (lc < n)
            dfs(n, lc + 1, rc, s + "(", res);
        if (rc < n && lc > rc)
            dfs(n, lc, rc + 1, s + ")", res);
    }
}

int main()
{
    int n = 3;
    for (auto s : generateParenthesis(n))
    {
        cout << s << endl;
    }
}