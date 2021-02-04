#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 39 给定一个无序的数组和一个目标值t，求出所有数组中的组合之和等于t的情况，然后保存到结果数组中
 * 注意，数组是不含有重复元素的,数组中的元素可以重复使用
 * 2，3，6，7, t = 7
 * 输出 2, 2, 3 和 7
 * 注意：
 * 1 数组里面无重复的数字
 * 2 每个数字可以重复使用
*/

/**
 * 方法 1，
 * 在一个函数中完成递归，还是要先给数组排序，然后遍历，如果当前数字大于 target，说明肯定无法组成 target，由于排过序，
 * 之后的也无法组成 target，直接 break 掉。如果当前数字正好等于 target，则当前单个数字就是一个解，组成一个数组然后放到结果 res 中。
 * 然后将当前位置之后的数组取出来，调用递归函数，注意此时的 target 要减去当前的数字，
 * 然后遍历递归结果返回的二维数组，将当前数字加到每一个数组最前面，然后再将每个数组加入结果 res 即可
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
        out.push_back(c[i]);
        dfs(c, t - c[i], i, out, res); // 这里i不是i+1因为可以重复使用
        out.pop_back();                // 恢复现场
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> out;
    vector<vector<int>> res;
    dfs(candidates, target, 0, out, res);
    return res;
}

/**
 * 方法 3，使用背包问题的写法来写
 * */
vector<vector<int>> combinationSum3(vector<int> &c, int t)
{
    vector<int> out;
    vector<vector<int>> res;
    dfs(c, t, 0, 0, out, res);
    return res;
}

void dfs(vector<int> &c, int t, int sum, int index, vector<int> &out, vector<vector<int>> &res)
{
    if (sum == t)
    {
        res.push_back(out);
        return;
    }
    if (sum > t || index == c.size())
        return;

    // 选择index数字
    out.push_back(c[index]);
    dfs(c, t, sum + c[index], index, out, res); // 这里是index而不是index+1的原因是可以重复选择这个数，如果是index+1，那么只能选择1次
    // 恢复现场
    out.pop_back();
    // 不选择index
    dfs(c, t, sum, index + 1, out, res);
}

int main()
{
    vector<int> res = {1, 3, 5};
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