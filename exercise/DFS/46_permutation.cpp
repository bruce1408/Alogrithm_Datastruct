#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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