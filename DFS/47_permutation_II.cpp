#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/**
 * 47 permutation
 * Given a collection of numbers, nums, 
 * that might contain duplicates, 
 * return all possible unique permutations in any order.
 * 
 * Example 1:
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 *  [1,2,1],
 *  [2,1,1]]
 * Example 2:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 这里数组里面可能包含重复元素
*/

/**
 * 方法 1，使用dfs，但是写法上没有解决重复问题，使用了集合来做
*/
void dfsLeetcode(int index, vector<int> &path, vector<bool> &visited, vector<int> &nums, vector<vector<int> > &temp)
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

vector<vector<int> > permute(vector<int> &nums)
{

    // 假设这个数组是已经排序好的
    int n = nums.size();
    // sort(nums.begin(), nums.end());
    vector<vector<int> > temp;
    vector<int> path(n, 0);
    vector<bool> visited(n, false);
    dfsLeetcode(0, path, visited, nums, temp);
    set<vector<int> > res(temp.begin(), temp.end());
    vector<vector<int> > s(res.begin(), res.end());
    return s;
}

/**
 * 方法 2，使用dfs来做，这里要考虑重复元素的话去重，和46题目非常类似，但是要考虑重复元素的相对顺序
 * 
*/
class Solution
{
public:
    vector<int> out;
    vector<vector<int> > res;
    vector<vector<int> > permuteUnique(vector<int> &nums)
    {
        vector<bool> visited(nums.size());
        sort(nums.begin(), nums.end());
        dfs(nums, visited, 0);
        return res;
    }

    void dfs(vector<int> &nums, vector<bool> &visited, int index)
    {
        if (index == nums.size())
        {
            res.push_back(out);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // 如果当前元素和前一个元素相同且前一个元素没有用过，那么就不能使用当前的这个元素，保持相对顺序，直接退出
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false)
                continue;
            if (visited[i] == false)
            {
                out.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, visited, index + 1);
                visited[i] = false;
                out.pop_back();
            }
        }
    }
};

/**
 * 方法 3，使用dfs，但是写法简单。不太容易理解
*/
class Solution
{
    public:
    vector<vector<int> > ans;
    vector<int> path;

    vector<vector<int> > permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        path.resize(nums.size());
        dfs(nums, 0, 0, 0);
        return ans;
    }

    void dfs(vector<int> &nums, int u, int start, int state)
    {
        if (u == nums.size())
        {
            ans.push_back(path);
            return;
        }

        if (!u || nums[u] != nums[u - 1])
            start = 0;

        for (int i = start; i < nums.size(); i++)
            if (!(state >> i & 1))
            {
                path[i] = nums[u];
                dfs(nums, u + 1, i + 1, state + (1 << i));
            }
    }
}


int main()
{
    vector<int> ans = {1, 1, 2};

    for (auto i : permute(ans))
    {
        for (auto x : i)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}