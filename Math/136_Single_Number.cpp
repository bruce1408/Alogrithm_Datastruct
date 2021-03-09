
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

/**
 * 136. Single Number，找出一个重复数组中出现一次的数字
 * Input: [2,2,1]
 * Output: 1
 * Example 2:
 * 不重复的数字
 * Input: [4,1,2,1,2]
 * Output: 4
*/

/**
 * 方法 1，使用hash表
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
 * 方法 2，利用异或！！但是这种方法只能求解一个不重复的数
*/
int singleNumber2(vector<int> &nums)
{
	int res = 0;
	for (auto num : nums)
		res ^= num;
	return res;
}

int main()
{
	vector<int> nums = {2, 1, 1, 3, 3};
	int t = singleNumber(nums);
	cout << t << endl;
	return 0;
}
