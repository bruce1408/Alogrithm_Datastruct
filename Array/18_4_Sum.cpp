#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    set<vector<int>>res;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-3;i++)
    {
        for(int j=i+1;j<nums.size()-2;j++)
        {
            int left = j+1,right = nums.size()-1;
            while(left<right)
            {
                int s = nums[i]+nums[j]+nums[left]+nums[right];
                if(s==target)
                {
                    res.insert({nums[i],nums[j],nums[left],nums[right]});
                    left++;
                    right--;
                }
                else if(s<target) left++;
                else right--;
            }
        }
    }
    return vector<vector<int>>(res.begin(),res.end());
}


// 不用set来做，和3sum一样。就是利用两个while循环判断
vector<vector<int>> fourSum1(vector<int> &nums, int target) 
{
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end()); // 排序
    for (int i = 0; i < n - 3; ++i) // 
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // 连续相同的直接退出
        for (int j = i + 1; j < n - 2; ++j) 
        {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // 两个数相等直接跳过
            int left = j + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                    res.push_back(out);
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left; --right;
                } else if (sum < target) ++left;
                else --right;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> resi = {-1, 0, 1, 2, -1, -4};
    // threeSum(res);
    for(auto &i: fourSum(resi, 2))
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}