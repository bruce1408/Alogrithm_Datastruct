#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * 167 给定一个有序数组和一个目标值，求数组中两个数的和等于目标数的下标，下标从1开始计数的
 * Example:
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * 
 * Explanation: The sum of 2 and 7 is 9. 
 * Therefore index1 = 1, index2 = 2.
*/
/**
 * 方法 1，因为是有序的，所以直接用两个指针来做；头指针和尾指针即可
 * 167. Two Sum II - Input array is sorted
 * O(n)的解法，我们只需要两个指针，一个指向开头，一个指向末尾，然后向中间遍历，
 * 如果指向的两个数相加正好等于target的话，
 * 直接返回两个指针的位置即可，若小于target，左指针右移一位，若大于target，右指针左移一位，
 * 以此类推直至两个指针相遇停止;
*/
vector<int> twoSum1(vector<int> &nums, int target)
{
	int left = 0, right = nums.size() - 1;
	while (left < right)
	{
		int sum = nums[left] + nums[right];
		if (sum == target)
			return {left+1, right+1};
		else if (sum > target)
			right--;
		else
			left++;
	}
	return {};
}

/**
 * 方法 2，因为是有序数组，所以从第二个数中查找满足target-num[i]的元素，
 * 利用二分查找即可；
*/
vector<int> twoSum2(vector<int> &nums, int target)
{
	for (int i = 0; i < nums.size() - 1; i++)
	{
		int l = i + 1, r = nums.size() - 1;
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (nums[mid] >= target - nums[i])
				r = mid;
			else
				l = mid + 1;
		}
		if (nums[l] == target - nums[i])
			return {i + 1, l + 1};
	}
	return {};
}

int main()
{
	vector<int> nums = {2, 7, 11, 15};
	vector<int> res_inde;
	int t = 9;
	res_inde = twoSum3(nums, t);
	for (auto i : res_inde)
		cout << i << " ";

	return 0;
}
