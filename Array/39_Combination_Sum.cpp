#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

/**
 * 39 给定一个无序的数组和一个目标值t，求出所有数组中的组合之和等于t的情况，然后保存到结果数组中
 * 注意，数组是不含有重复元素的,数组中的元素可以重复使用
 * 2，3，6，7, t = 7
 * 输出 2, 2, 3 和 7
 * 
*/

/**
 * 方法 1，不使用递归
 * 就在一个函数中完成递归，还是要先给数组排序，然后遍历，如果当前数字大于 target，说明肯定无法组成 target，由于排过序，
 * 之后的也无法组成 target，直接 break 掉。如果当前数字正好等于 target，则当前单个数字就是一个解，组成一个数组然后放到结果 res 中。
 * 然后将当前位置之后的数组取出来，调用递归函数，注意此时的 target 要减去当前的数字，
 * 然后遍历递归结果返回的二维数组，将当前数字加到每一个数组最前面，然后再将每个数组加入结果 res 即可
*/
vector<vector<int>> combinationSum(vector<int> &c, int target)
{
    vector<vector<int>> res;
    sort(candidates.begin(), c.end());
    for (int i = 0; i < c.size(); ++i)
    {
        if (c[i] > target)
            break;
        if (c[i] == target)
        {
            res.push_back({c[i]});
            break;
        }
        vector<int> vec = vector<int>(c.begin() + i, c.end());
        vector<vector<int>> tmp = combinationSum(vec, target - c[i]);
        for (auto a : tmp)
        {
            a.insert(a.begin(), c[i]);
            res.push_back(a);
        }
    }
    return res;
}
/**
 * 方法 2
*/
void helper(vector<int> &candidates, int target, int start, vector<int> &out, vector<vector<int>> &res)
{
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> out;
    vector<vector<int>> res;
    helper(candidates, target, 0, out, res);
    return res;
}

int main()
{
    vector<int> res = {1, 3, 5};
    int a = 8;
    for (auto i : combinationSum(res, a))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}