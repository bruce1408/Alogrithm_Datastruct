#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

/**1. Two Sum
 * Given nums = [2, 7, 11, 15], 
 * target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1]
 * 和 49题目很接近
*/

/**
 * 方法 1，就是利用两层for循环，时间复杂度O(n^2)；第一层for循环的i从0到n开始，第二层的for循环j从1-n开始
 * 看是否nums[i] + nums[j] == target,然后返回i 和 j即可
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
 * 方法 2，利用的就是集合来做，重点思路就是查找unordered_set；
 * 利用unordered_set 来做一个查找；
 * 建立一个hash_set,然后每个元素存储的是它的位置下表，遍历数组，对每一个元素看是否存在 target-nums[i] ;
 * 如果存在的话，那么就返回当前的元素位置下标和target-nums[i]的元素下标；
 * 这里的前提条件是数组中的所有元素都是唯一不重复的才行；
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
		if (res.find(anotherNum) != res.end() && res[anotherNum] != i) // 且坐标不能是当前坐标，排出3，6-3的情况；
		{
			cout << res[nums[i]] << endl;
			return {i, res[target - nums[i]]};
		}
	}
	return {};
}

/**
 * 方法 3 是把方法 2的两个for循环合并成一个；
 * 方法 3和 方法 2完全一样，注意find是不能等于res.end(),
 * 而count必须大于0，因为找到的话就是返回1；否则返回的是0；
 * 
*/
vector<int> twoSum3(vector<int> &nums, int target)
{
	unordered_map<int, int> temp;
	vector<int> res;
	for (int i = 0; i < nums.size(); i++)
	{
		/*先找到这个数，判断是否存在，且位置坐标不是当前循环的i的位置，因为是同一个数，闹乌龙了，然后添加到res里面*/
		int left = target - nums[i];			 // 找到了这个数字
		if (temp.count(left) && temp[left] != i) // 找到这个数字并且这个数字不是自己
		{
			return {i, temp[left]}; // 有了这一步，前面两行都不用了，但是推荐用生成res
		}
		temp[nums[i]] = i;
	}
	return {};
}

/**
 * 方法 4，这种方法没有排序，这么做事没有意义的，因为方法 4的思路就是说我们先按照升序对数组排序，然后
 * 给定两个指针，一个指向开头，一个指向结尾，如果开头的和结尾的相加，看sum是不是等于目标值target，如果
 * 大于这个数，尾指针--，如果小于这个数，头指针++；可是排序后数组的下标会乱掉；
 * */
// vector<int> twoSum4(vector<int> &nums, int k)
// {
// 	int sum;
// 	vector<int> res;
// 	for (int i = 0; i < nums.size(); i++)
// 	{
// 		int left = i, right = nums.size() - 1;
// 		while (left < right && res.empty())
// 		{
// 			sum = nums[left] + nums[right];
// 			if (sum == k)
// 			{
// 				res.push_back(left);
// 				res.push_back(right);
// 				cout << left << " " << right << endl;
// 				break;
// 			}
// 			else if (sum > k)
// 				right--;
// 			else
// 				left++;
// 		}
// 	}
// 	return res;
// }

/**
 * 方法 5是在方法 4的基础上改的，方法 4虽然思路对的，但是实现的话没有利用多个多个键值的哈希表，
 * 方法5就是把所有所有元素和下标存在哈希表中，考虑到元素可能有重复的情况，我们使用multimap，它和map类似
 * 但是可以保存多个相同的键值，而且在C++ STL 中，multimap默认是按照key的升序排列的，这样我们只需要两个指针即可
 * 一个是指向开头的指针，一个指向尾元素的指针，end一般是尾元素的下一个元素，这里我们还要减一，然后只要头指针不等于尾指针，
 * 那么判断他们的值相加是不是等于目标数target，如果大于这个数，尾指针减一，如果小于这个数头指针加一即可；
 * 满足的就返回他们的元素下标即可；
*/
vector<int> twoSum5(vector<int> &nums, int target)
{
	multimap<int, int> temp;
	for (int i = 0; i < nums.size(); i++)
	{
		temp.insert(pair<int, int>(nums[i], i));
	}
	multimap<int, int>::iterator iterB = temp.begin(), iterE = temp.end();
	iterE--;
	while (iterB != iterE)
	{
		int sum = iterB->first + iterE->first;
		cout << "the sum is : " << sum << endl;
		if (sum == target)
		{
			return {iterB->second, iterE->second};
			break;
		}
		else if (sum > target)
			iterE--;
		else
			iterB++;
	}
	return {};
}

int main()
{
	// vector<int> nums = {-10, -1, -18, -19};
	vector<int> nums = {3, 2, 4};
	int t = 6;
	// int t = -19;
	for (auto i : twoSum5(nums, t))
		cout << i << " ";
	cout << endl;
	return 0;
}
