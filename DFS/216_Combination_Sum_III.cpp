#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 216 给两个数
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字
 * 示例 1:
 * 输入: k = 3, n = 7
 * 输出: [[1, 2, 4]] 
 * 
*/

/**
 * 方法 1，使用dfs暴力搜索
*/
vector<int> out;
vector<vector<int>> ans;

void dfs(int k, int sum, int start)
{
    if (sum < 0)
        return;
    if (sum == 0 && k == out.size())
    {
        ans.push_back(out);
    }
    for (int i = start; i <= 9; i++)
    {
        out.push_back(i);
        dfs(k, sum - i, i + 1);
        out.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int sum)
{
    dfs(k, sum, 1);
    return ans;
}

/**
 * 方法 2，使用dfs
*/
vector<int> out;
vector<vector<int>> res;
vector<vector<int>> combinationSum3(int k, int n)
{
    dfs(k, n, 1, 0); // k表示有多少个数字，n表示总和，1表示开始的数，0表示当前数字个数
    return res;
}

void dfs(int k, int n, int start, int index)
{
    // 如果n小于0或者index数目超过k要求的数字，直接返回
    if (n < 0 || index > k)
        return;
    // 如果n是0且数组数字是k的话，保存到结果数字中
    if (n == 0 && k == index)
    {
        res.push_back(out);
        return;
    }
    // 然后i从start开始，i的数值小于等于9，然后i自加
    for (int i = start; i <= 9; i++)
    {
        out.push_back(i);
        dfs(k, n - i, i + 1, index + 1);
        out.pop_back();
    }
}

int main()
{
    int k = 3, n = 7;
    for (auto i : combinationSum3(k, n))
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}