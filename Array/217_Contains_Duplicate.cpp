#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 * 217 给定一个无序的整数数组，然后求出这个整数数组的重复元素即可
 * 
 * Example 1:
 * Input: [1,2,3,1]
 * Output: true
 * 
 * Example 2:
 * Input: [1,2,3,4]
 * Output: false
 * 
 * 判断是否数组中出现重复的数
*/

/**
 * 方法 1, 利用hash_map来做,把数组的出现次数放进hashmap中,每次查看,如果出现了这个数字,直接返回true;
 * 时间复杂度是O(n)，空间复杂度是O(n)
*/
bool containsDuplicate1(vector<int> &nums)
{
	unordered_map<int, int> res;
	for (int i = 0; i < nums.size(); i++)
	{
		if (res.find(nums[i]) != res.end()) // hashmap的find函数
			return true;
		++res[nums[i]];
	}
	return false;
}

/**
 * 方法 2，和上面类似的思路，就是用其他容器来实现
*/
bool containsDuplicate2(vector<int> &nums)
{
	unordered_set<int> s;
	for (int i = 0; i < nums.size(); i++)
	{
		if (s.count(nums[i]))
			return true;
		else
			s.insert(nums[i]);
	}
	return false;
}

/**
 * 方法 3,先排序,然后判断前后两个数字是否是相同的,用这样的办法来判断,时间复杂度取决于排序算法
 * 时间复杂度是O(nlgn)，空间复杂度是O(1)
*/
bool containsDuplicate3(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
	for (size_t i = 1; i < nums.size(); i++)
	{
		if (nums[i] == nums[i - 1])
			return true;
	}
	return false;
}

int main()
{
	vector<int> nums = {1, 2, 3, 1};
	if (containsDuplicate3(nums))
		cout << "有重复的值" << endl;
	else
		cout << "no" << endl;
	return 0;
}
