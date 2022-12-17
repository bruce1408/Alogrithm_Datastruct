/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int temp=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i+1]-nums[i]==0)
            {
                temp = nums[i];
            }
            return temp;
        }
        
    }
};

