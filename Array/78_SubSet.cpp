#include <iostream>
#include <vector>
using namespace std;

/**
 * 78 给一个数组，然后返回数组所有可能的组合
*/

/**
 * 方法 1，使用位运算
 * 采用位运算的思路进行求解。对于一个大小为n的集合来说，我们需要用一个n位二进制数来表示每个数的选择状态，
 * 所有子集的个数为2^n个，所以每个叶子结点的状态刚好可以用0 ~ 2^n−1中的二进制数表示。
 * https://www.acwing.com/solution/content/14584/ 参考
*/
vector<vector<int>> subsets1(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < 1 << n; i++)
    {
        vector<int> path;
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
                path.push_back(nums[j]);
        }
        res.push_back(path);
    }
    return res;
}

/**
 * 方法 2，使用dfs搜索
*/
vector<int> out;
vector<vector<int>> res;
vector<vector<int>> subsets2(vector<int> &nums)
{
    dfs(nums, 0);
    return res;
}

void dfs(vector<int>&nums, int start)
{
    if(start==nums.size())
    {
        res.push_back(out);
        return ;
    }

    dfs(nums, start + 1); // 不选当前数递归到下一层
    out.push_back(nums[start]); // 选择当前数递归到下一层
    dfs(nums, start + 1);
    out.pop_back();
}

int main()
{
    vector<int> res = {1, 2, 3};
    subsets(res);
}