#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 216 给两个数
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字
 * 示例 1:
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]] 
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