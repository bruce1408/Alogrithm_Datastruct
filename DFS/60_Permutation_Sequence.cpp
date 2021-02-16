#include <iostream>
#include <vector>
using namespace std;

/**
 * 给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 给定 n 和 k，返回第 k 个排列。
 * 
 * 示例 1：
 * 输入：n = 3, k = 3
 * 输出："213"
*/

/**
 * 方法 1，按照排列的思路做，但是最后超时了
*/
vector<string> out;
vector<vector<string>> res;
string getPermutation(int n, int k)
{
    vector<bool> visited(n);
    dfs(n, k, visited, 0);
    string str = "";
    for (int i = 0; i < res[k - 1].size(); i++)
        str += res[k - 1][i];
    return str;
}

void dfs(int n, int k, vector<bool> &visited, int index)
{
    if (index == n)
    {
        res.push_back(out);
        return;
    }

    if (index > n)
        return;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            out.push_back(to_string(i + 1));
            visited[i] = true;
            dfs(n, k, visited, index + 1);
            visited[i] = false;
            out.pop_back();
        }
    }
}

/**
 * 方法 2，按照题目要求分析，如果这个数字的某位排列是确定的，那么接下来的选择是n-1！种方案
 * 所以这里的选择就是如果确定看它的阶乘数是不是大于k，如果小于k，说明不会是这个数字，如果大于k的话
 * 那么就在保存当前位的数字，这里还需要一个bool数组保存当前数是不是用过了；
*/
string getPermutation(int n, int k)
{
    string res;
    vector<bool> visited(n);
    // 遍历每个数字然后计算当前位置的数字
    for (int i = 0; i < n; i++)
    {
        int fact = 1;
        for (int j = 1; j <= n - i - 1; j++) // 计算n-i-1的阶乘
            fact *= j;
        for (int j = 1; j <= n; j++) // 然后判断当前数字j是不是可以填在这个第i位
        {
            if (visited[j] == false) // 如果数字j之前没有出现
            {
                if (fact < k) // fact阶乘是不是小于k，如果小于那么k-=fact
                    k -= fact;
                else
                {
                    res += to_string(j); // 否则当前j保存在i位置，然后j对应的bool设置为true，break
                    visited[j] = true;
                    break;
                }
            }
        }
    }
    return res;
}

/**
 * 方法 3，回家等通知算法,使用库函数next_permutation函数
*/
string getPermutation(int n, int k)
{
    string res;
    for (int i = 1; i <= n; i++)
        res += to_string(i);
    for (int i = 0; i < k - 1; i++)
        next_permutation(res.begin(), res.end());
    return res;
}