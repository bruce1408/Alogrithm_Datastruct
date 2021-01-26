#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * 219 给定一个无序的数组和整数k，如果重复元素的下标之差是k，返回true，否则返回false 
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

/**
 * 方法 1，使用hash表来记录每个元素的下标，然后如果找到重复元素
 * 对比这两个下标的差值是否小于等于k，如果是的话，那么就返回true
 * 否则，更新新的下标为当前的下标即可。
 * 最后遍历结束返回false
*/
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
	unordered_map<int, int> s;
	for (int i = 0; i < nums.size(); i++)
	{
		if (s.count(nums[i]))
		{
			if (i - s[nums[i]] <= k)
				return true;
		}
		s[nums[i]] = i;
	}
	return false;
}

int main()
{
	vector<int> nums = {1, 0, 1, 1};
	if (containsNearbyDuplicate1(nums, 2))
		cout << "有重复的值" << endl;
	else
		cout << "不满足条件";
	return 0;
}
