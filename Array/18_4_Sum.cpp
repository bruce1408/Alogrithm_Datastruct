#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

/**
 * 18 四数之和，给定一个数组和一个目标数t，然后找出所有四个数之和等于目标数t的情况，不可以重复
 * 还是类似三数之和，使用双指针做法即可
*/

/**
 * 方法 1，使用双指针来做即可；这里用集合
*/
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    set<vector<int>> res; // 这里使用了集合，所以直接可以略去重复的情况
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; i++)
    {
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            int left = j + 1, right = nums.size() - 1;
            while (left < right)
            {
                int s = nums[i] + nums[j] + nums[left] + nums[right];
                if (s == target)
                {
                    res.insert({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if (s < target)
                    left++;
                else
                    right--;
            }
        }
    }
    return vector<vector<int>>(res.begin(), res.end());
}

/**
 * 方法 2，不用集合，就是使用两个指针来做即可，和三数之和一样
*/
vector<vector<int>> fourSum2(vector<int>& nums, int t) {
    int n = nums.size();
    vector<vector<int>>res;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++)
    {
        if(i && nums[i] == nums[i-1]) continue;
        for(int j = i+1;j<n;j++)
        {
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            int l = j+1, r = n-1;
            while(l<r)
            {
                int s = nums[i] + nums[j] + nums[l] + nums[r];
                if(s==t)
                {
                    res.push_back({nums[i], nums[j], nums[l],nums[r]});
                    while(l<r && nums[l] == nums[l+1]) l++;
                    while(l<r && nums[r] == nums[r-1]) r--;
                    l++, r--;
                }
                else if(s<t) l++;
                else r--;
            }
        }
    }
    return res;

}

int main()
{
    vector<int> resi = {-1, 0, 1, 2, -1, -4};
    // threeSum(res);
    for (auto &i : fourSum(resi, 2))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}