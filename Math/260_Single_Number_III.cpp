#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * 260. Single Number III  和 136 的异或不一样，异或只能求一个数
 * 数组中有两个元素出现1次，其他元素出现2次，求出这个出现一次的数
 */

/**
 * 方法 1，hash思路
 */
vector<int> singleNumber(vector<int> &nums)
{
	vector<int> res;
	unordered_map<int, int> temp;
	for (int i = 0; i < nums.size(); i++)
	{
		++temp[nums[i]];
	}

	for (auto &x : temp)
	{
		if (x.second < 2)
			res.push_back(x.first);
	}
	return res;
}

/**
 * 方法 2，使用位运算来做；假设两个出现1次的数字是a和b，直接使用异或来做的话，
 * 那么结果是a^b,所以找到a和b第k为不同的数字，然后把数组分成2部分，k位是1和k位不是
 * 1的情况讨论，这两种情况分别进行异或操作就可以求出a和b的值来
*/
int get(vector<int> &nums, int k, int t)
{
	int res = 0;
	for (auto x : nums)
	{
		if ((x >> k & 1) == t)
			res ^= x;
	}
	return res;
}

vector<int> singleNumber(vector<int> &nums)
{
	int ab = 0;
	for (auto x : nums)
		ab ^= x;
	int k = 0;
	while ((ab >> k & 1) == 0)
		k++;
	return {get(nums, k, 0), get(nums, k, 1)};
}

int main()
{
	vector<int> nums = {1, 2, 1, 3, 2, 5};
	vector<int> res;
	res = singleNumber(nums);
	for (auto i : res)
		cout << i << " ";

	return 0;
}
