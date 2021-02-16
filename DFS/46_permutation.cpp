#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Given an array nums of distinct integers, 
 * return all the possible permutations. 
 * You can return the answer in any order.
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 * 
 * 给一个数组，数字互不相同，求这组数的全排列，这里主要负数
*/

vector<int> out;
vector<vector<int>> res;
vector<vector<int>> permute(vector<int> &nums)
{
    vector<bool> visited(nums.size(), 0);

    dfs(nums, 0, visited);
    return res;
}

void dfs(vector<int> &nums, int index, vector<bool> &visited)
{
    if (index == nums.size())
    {
        res.push_back(out);
        return;
    }
    if (index > nums.size())
        return;
    for (int i = 0; i < nums.size(); i++)
    {
        if (visited[i] == true)
            continue;
        else
        {
            out.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, index + 1, visited);
            visited[i] = false;
            out.pop_back();
        }
    }
}
int main()
{
    vector<int> ans = {0, -1, 1};

    for (auto i : permute(ans))
    {
        for (auto x : i)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}