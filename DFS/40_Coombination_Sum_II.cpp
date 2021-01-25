#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 40 给定一个无序的数组和一个目标值t，求出所有数组中的组合之和等于t的情况，然后保存到结果数组中
 * 注意，数组是不含有重复元素的,数组中的元素不可以重复使用
 * 2，3，6，7, t = 7
 * 输出 7 
*/

/**
 * 方法 1，暴搜，使用dfs
 * 这里不能重复使用某个数字，且结果还要去重的话，先对c数字进行排序，然后再dfs函数里面
 * 去重，如果i>start && c[i] == c[i-1] 就退出，这样就能保证去重
*/
void dfs(vector<int> &c, int t, int start, vector<int> &out, vector<vector<int>> &res)
{
    if (t < 0)
        return;
    if (t == 0)
    {
        res.push_back(out);
        return;
    }

    for (int i = start; i < c.size(); i++)
    {
        if (i > start && c[i] == c[i - 1]) // 去重
            continue;
        out.push_back(c[i]);
        dfs(c, t - c[i], i + 1, out, res);
        out.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<int> out;
    vector<vector<int>> res;
    dfs(candidates, target, 0, out, res);
    return res;
}

int main()
{
    vector<int> res = {1, 3, 5, 8};
    int a = 8;
    for (auto i : combinationSum2(res, a))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}