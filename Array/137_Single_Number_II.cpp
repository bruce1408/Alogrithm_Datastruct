#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * 137. Single Number II
 * 只有一个出现一次，其他的都会出现三次，找到那个出现一次的
 * Input: [2,2,3,2] Output: 3
 * Example 2:
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
*/

/**
 * 第一种方法：哈希思路
 */
int singleNumber(vector<int> &nums)
{
	unordered_map<int, int> temp;
	for (int i = 0; i < nums.size(); i++)
	{
		++temp[nums[i]];
	}

	for (auto &x : temp)
	{
		if (x.second < 2)
			return x.first;
	}
	return 0;
}

/**
 * 方法 2，使用位运算来做, 推荐做法
*/
int singleNumber2(vector<int> &nums)
{
	int res = 0;
	for (int i = 0; i < 32; i++)
	{
		int sum = 0;
		for (int j = 0; j < nums.size(); j++)
		{
			sum += (nums[j] >> i) & 1;
		}
		res |= (sum % 3) << i;
	}
	return res;
}

int main()
{
	vector<int> nums = {2, 2, 3, 2};
	cout << singleNumber2(nums) << endl;

	return 0;
}
