#include <iostream>
#include <vector>
using namespace std;

/**
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * Input: nums = [1,2,3]
 * Output:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 * 
 * 返回的是这个数组的所有的组合
*/

/**
 * 方法 1,尝试使用递归；
*/

void helper(vector<int> &nums, int begin, vector<int> &temp, vector<vector<int>> &res)
{
    res.push_back(temp);
    for (int i = begin; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
        helper(nums, i + 1, temp, res);
        temp.pop_back();
    }
}

vector<vector<int>> subsets1(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    vector<int> temp;
    helper(nums, 0, temp, res);
    return res;
}

/**
 * 方法 2，使用非递归方法
*/
vector<vector<int>> subsets2(vector<int> &nums)
{
    vector<vector<int>> res(1);
    for (int i = 0; i < nums.size(); i++)
    {
        int size = res.size();
        for (int j = 0; j < size; j++)
        {
            res.push_back(res[j]);
            res.back().push_back(nums[i]);
        }
    }
    return res;
}
int main()
{
    vector<int> res = {1, 2, 3};
    for (auto i : subsets2(res))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
