#include <iostream>
#include <vector>
using namespace std;

/**
 * 78 子集问题；给定一个数组，然后返回这个数组的所有子集的情况
 * 比如输入
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

/**
 * 方法 1，使用位运算
 * 采用位运算的思路进行求解。对于一个大小为n的集合来说，我们需要用一个n位二进制数来表示每个数的选择状态，
 * 所有子集的个数为2^n个，所以每个叶子结点的状态刚好可以用0 ~ 2^n−1中的二进制数表示。
 * https://www.acwing.com/solution/content/14584/ 参考
*/
vector<vector<int>> subsets2(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>>res;
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
 * 方法 2，使用dfs来做如果index 当前数字小于nums.size()长度，那么就
 * 保存进结果数组，如果大于的话，直接返回；
 * i=index开始，i<nums.size();递归调用下一个dfs(i+1)
*/
class Solution
{
public:
    vector<int> out;
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs2(nums, 0);
        return res;
    }

    void dfs2(vector<int> &nums, int index)
    {
        if (index <= nums.size())
            res.push_back(out);
        if (index > nums.size())
            return;
        for (int i = index; i < nums.size(); i++)
        {
            out.push_back(nums[i]);
            dfs2(nums, i + 1);
            out.pop_back();
        }
    }
};

/**
 * 方法 3，使用dfs搜索
*/
vector<int> out;
vector<vector<int>> res;

void dfs(vector<int> &nums, int start)
{
    if (start == nums.size())
    {
        res.push_back(out);
        return;
    }

    out.push_back(nums[start]); // 选择当前数递归到下一层
    dfs(nums, start + 1);       // 不选当前数递归到下一层
    out.pop_back();
    dfs(nums, start + 1);
}

vector<vector<int>> subsets3(vector<int> &nums)
{
    dfs(nums, 0);
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