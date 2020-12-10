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

void dfsLeetcode(int index, vector<int> &path, vector<bool> &visited, vector<int> &nums, vector<vector<int>> &temp)
{
    int len = nums.size();
    if (index == len)
    {
        vector<int> res;
        for (int i = 0; i < len; i++)
        {
            res.push_back(path[i]);
        }
        temp.push_back(res);
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            path[index] = nums[i];
            dfsLeetcode(index + 1, path, visited, nums, temp);
            visited[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{

    // 假设这个数组是已经排序好的
    int n = nums.size();
    // sort(nums.begin(), nums.end());
    vector<vector<int>> temp;
    vector<int> path(n, 0);
    vector<bool> visited(n, false);
    dfsLeetcode(0, path, visited, nums, temp);
    return temp;
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