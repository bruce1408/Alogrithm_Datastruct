#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/**
 * Given an array of integers and an integer k, 
 * find out whether there are two distinct indices i and j in the array
 * such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
 * 
 * Example 1:
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * Example 2:
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * 给一个数组和整数k,找到范围在k的重复数字
*/
bool containsNearbyDuplicate1(vector<int>& nums, int k)
{
	unordered_map<int, int>res;
	for(int i=0;i<nums.size();i++)
	{
		if(res.find(nums[i])!=res.end())
		{
			res[nums[i]]++;
		}
		else 
		{
			int idx = abs(i-k);
			if(res.find(nums[idx])!=res.end())
			{
				return true;
			}
		}
	}
	return false;
}
/**
 * 求得两数相同，而且下标的差最大不能超过k;
 * 思路是：之前没出现的数全部放到res，如果有这个数，那么看下标是否满足，输出true，否则，继续放进res
*/
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	unordered_map<int,int> res;
	for(int i=0;i<nums.size();i++)
	{
		if(res.find(nums[i])==res.end()) // 如果之前没有出现这个数，那么就加进去。
			res[nums[i]] = i;	
		else
		{
			if(i-res.find(nums[i])->second<=k)
			{
				return true;
			}
			else
				res[nums[i]] = i;	
		}
	}
	return false;
}


/**
 * 方法 2
*/
class Solution 
{
	public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
	{
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) 
		{
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) return true; //如果是之前有这个值，而且相减差值满足条件，那么返回true
            else m[nums[i]] = i;
        }
        return false;
    }
};


int main()
{
	vector<int> nums = {1,0,1,1};
	if(containsNearbyDuplicate1(nums,1))
		cout<<"有重复的值"<<endl;
	else
		cout<<"不满足条件";
	return 0;
}
