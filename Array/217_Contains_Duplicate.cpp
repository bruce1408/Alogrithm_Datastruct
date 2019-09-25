#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

/**
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the array, 
 * and it should return false if every element is distinct.
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
 * 方法 1 利用448题目的那个方法,只需要一次遍历即可,时间复杂度是O(n),但是这个前提必须是
 * 从1-n开始的数字,否则会越界;这种方法有局限性!
 * 
*/
bool containsDuplicate(vector<int>& nums)
{
	for(int i=0;i<nums.size();i++)
	{
		int idx = abs(nums[i])-1;
		if(nums[idx]>0)
		{
			nums[idx] = -nums[idx];
		}
		else
		{
			return true;
		}
	}
	return false;
}
/**
 * 方法 2, 利用hash_map来做,把数组的出现次数放进hashmap中,每次查看,如果出现了这个数字,直接返回true;
*/
bool containsDuplicate1(vector<int>& nums)
{
	unordered_map<int,int> res;
	for(int i=0;i<nums.size();i++)
	{
		if(res.find(nums[i])!=res.end()) // hashmap的find函数
			return true;
		++res[nums[i]];
	}
	return false;
}

/**
 * 方法 3,先排序,然后判断前后两个数字是否是相同的,用这样的办法来判断,时间复杂度取决于排序算法
 * 这个题目在lc上提交的时候一直是runtime error,后来发现可能是i=0;i<nums.size()-1;然后后面
 * i的值有可能取到nums.size()-1,虽然题目没有报错,但是可能存在越界问题,所以这里修改成i=1开始,然后到i<nums.size()
*/
bool containsDuplicate2(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	for(size_t i=1;i<nums.size();i++)
	{
		if(nums[i]==nums[i-1]) return true;
	}
	return false;
}

int main()
{
	vector<int> nums = {1,2,3,4,5,6,9};
	if(containsDuplicate2(nums))
		cout<<"有重复的值"<<endl;
	else cout<<"no"<<endl;
	return 0;
}





































