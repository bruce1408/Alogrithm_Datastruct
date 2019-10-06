#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * Given an array containing n distinct numbers taken from 
 * 0, 1, 2, ..., n, find the one that is missing from the array.
 * Input: [3,0,1]
 * Output: 2
 * Example 2
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 给定一个从0~n的数组,然后找到这个数组缺少的值
*/

/**
 * 方法 1,利用求和公式相加,然后累加和减去数组的累加之和,得到的数就是数组缺少的数字.
 * 时间复杂度是O(n),空间复杂度是O(1)
*/

int missingNumber1(vector<int> &nums)
{
	int len = nums.size();
	int formuSum = (1 + len) * len / 2;
	int arrsum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		arrsum += nums[i];
	}
	return formuSum - arrsum;
}

int missingNumber1_1(vector<int> &nums)
{
	int len = nums.size();
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += i;
		sum -= nums[i];
	}
	sum += len;
	return sum;
}
/**
 * 方法 2,排序,然后看下一个数是不是当前数+1,然后判断缺少的数字
*/
int missingNumber2(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] != nums[i - 1] + 1)
		{
			return nums[i] - 1;
		}
	}
	return -1;
}

/**
 * 方法 3，利用哈希map来做一个下表和数字的映射
*/
int missingNumber3(vector<int> &nums)
{
	unordered_map<int, int> res;
	for (int i = 0; i < nums.size(); i++)
	{
		res[nums[i]]++;
	}
	for (int i = 0; i < res.size() + 1; i++)
	{
		if (res[i] == 0)
			return i;
	}
	return -1;
}
/**
 * 方法 4，利用异或来做，相同数字异或的0，设置一个初始值res，res的值是数组长度，这样就是可以
 * 取到数组中的元素是数组长度的值，例如[0,1,3],长度是3，但是下标元素无法取到3，所以设置res初始值
 * 是数组长度；然后挨个和下标，元素进行异或，只要是出现的，都是0，最后没有出现的就会保留下来；
*/
int missingNumber4(vector<int> &nums)
{
	int res = nums.size();
	for (int i = 0; i < nums.size(); i++)
	{
		res ^= i;
		res ^= nums[i];
	}
	return res;
}

/**
 * 方法 5，这道题还可以用二分查找法来做，我们首先要对数组排序，
 * 然后我们用二分查找法算出中间元素的下标，然后用元素值和下标值之间做对比，
 * 如果元素值大于下标值，则说明缺失的数字在左边，此时将right赋为mid，反之则将left赋为mid+1。
 * 
 * 但是如果真的是有序数组，那么我们比较下标就好了，如果是元素值和下标值不等，返回这个下标即可；
*/
int missingNumber5(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
	int left = 0, right = nums.size();
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] > mid)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int main()
{
	vector<int> nums = {0, 1, 2};
	cout << missingNumber1_1(nums);
	return 0;
}
