#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

/**1. Two Sum
 * Given nums = [2, 7, 11, 15], 
 * target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1]
 * 
 * 和 49题目很接近
*/

/**
 * 方法 1，就是利用两层for循环，时间复杂度O(n^2)
*/
vector<int> twoSum1(vector<int> &nums, int target)
{
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				return {i, j};
			}
		}
	}
	return {};
}

/**
 * 方法 2，利用的就是集合来做，重点思路就是查找unordered_set
*/
vector<int> twoSum2(vector<int> &nums, int target)
{
	unordered_map<int, int> res;
	for (int i = 0; i < nums.size(); i++)
	{
		res[nums[i]] = i;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		int anotherNum = target - nums[i];
		if (res.find(anotherNum) != res.end() && res[anotherNum]!=i)
		{
			cout << res[nums[i]] << endl;
			return {i, res[target - nums[i]]};
		}
	}
	return {};
}
/**给for循环强加条件来优化代码，比如nums[i]<=target,但是没有考虑到负数！
 * 另外find()和count()函数都是判断是否存在这个数，
*/
vector<int> twoSum3(vector<int> &nums, int target)
{
	unordered_map<int, int> temp;
	vector<int> res;
	for (int i = 0; i < nums.size(); i++)
		temp[nums[i]] = i; // 位置索引
	for (int i = 0; i < nums.size(); i++)
	{
		/*先找到这个数，判断是否存在，且位置坐标不是当前循环的i的位置，因为是同一个数，闹乌龙了，然后添加到res里面*/
		int left = target - nums[i];			 // 找到了这个数字
		if (temp.count(left) && temp[left] != i) // 找到这个数字并且这个数字不是自己
		{
			// res.push_back(i);
			// res.push_back(temp[left]);
			return {i, temp[left]}; // 有了这一步，前面两行都不用了，但是推荐用生成res
		}
	}
	return {};
}

// 自己再做一遍
vector<int> sumofTwo(vector<int> &nums, int k)
{
	int sum;
	// sort(nums.begin(),nums.end());
	vector<int> res;
	for (int i = 0; i < nums.size(); i++)
	{
		int left = i, right = nums.size() - 1;
		// if(nums[i]==nums[i+1]) continue;
		while (left < right && res.empty())
		{
			sum = nums[left] + nums[right];
			if (sum == k)
			{
				res.push_back(left);
				res.push_back(right);
				cout << left << " " << right << endl;
				break;
			}
			else if (sum > k)
				right--;
			else
				left++;
		}
	}
	return res;
}

int main()
{
	vector<int> nums = {-10, -1, -18, -19};
	vector<int> nums = {3,2,4};
	target = 6;
	int t = -19;
	for (auto i : twoSum2(nums, t))
		cout << i << " ";
	return 0;
}
