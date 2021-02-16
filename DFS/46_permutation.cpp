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

/**
 * 方法 1 使用dfs来做即可
 * 使用一个额外的visited数组来记录每个数字是否之前已经用过
*/
vector<int> out;
vector<vector<int>> res;

void dfs(vector<int> &nums, int index, vector<bool> &visited)
{
    if (index == nums.size())
    {
        res.push_back(out);
        return;
    }
    if (index > nums.size())
        return;
    // 这里遍历每一个节点，然后每个节点进行n！次搜索，总的时间复杂度是n*n！
    for (int i = 0; i < nums.size(); i++)
    {
        if (visited[i] == true)
            continue;
        else
        {
            out.push_back(nums[i]);
            visited[i] = true;             // 修改这个数的状态
            dfs(nums, index + 1, visited); // 然后开始计算下一个值，这里是index+1,不能是i
            visited[i] = false;            // 恢复当前数的状态
            out.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<bool> visited(nums.size(), 0);

    dfs(nums, 0, visited);
    return res;
}

int main()
{
    vector<int> ans = {0, 1, 2};

    for (auto i : permute(ans))
    {
        for (auto x : i)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}