#include<iostream>
#include<vector>
using namespace std;

/**
 * 90 subsets II
 * 给定一个包含重复的元素，然后输出不含有重复元素的所有子集情况
*/

/**
 * 方法 1，使用dfs来做
*/
class Solution {
public:
    vector<int>out;
    vector<vector<int>>res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>&nums, int k)
    {
        if(k <= nums.size())
        {
            res.push_back(out);
        }

        if(k > nums.size()) return ;
        for(int i = k; i< nums.size();i++)
        {
            if(i > k && nums[i] == nums[i-1]) continue;
            out.push_back(nums[i]);
            dfs(nums, i+1);
            out.pop_back();
        }
    }
};


/**
 * 方法 2，dfs的背包模型来做即可
*/
class Solution {
public:
    vector<int>out;
    vector<vector<int>>res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int> &nums, int start)
    {
        if (start == nums.size())
        {
            res.push_back(out);
            return;
        }
        int k = start+1;
        while(k < nums.size() && nums[k] == nums[start]) k++;
        out.push_back(nums[start]); // 选择当前数递归到下一层
        dfs(nums, start + 1);       // 不选当前数递归到下一层
        out.pop_back();
        dfs(nums, k);
    }
  
};

