#include <iostream>
#include <vector>
using namespace std;

/**
 * 78 子集问题；给定一个数组，然后返回这个数组的所有子集
 * 比如输入
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

/**
 * 方法 1，使用dfs来做如果index 当前数字小于nums.size()长度，那么就
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
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int> &nums, int index)
    {
        if (index <= nums.size()) res.push_back(out);
        if (index > nums.size()) return;
        for (int i = index; i < nums.size(); i++)
        {
            out.push_back(nums[i]);
            dfs(nums, i + 1);
            out.pop_back();
        }
    }
};