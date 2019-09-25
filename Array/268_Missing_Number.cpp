#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
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

int missingNumber1(vector<int>& nums) 
{
	int len = nums.size();
	int formuSum = (1+len)*len/2;
	int arrsum = 0;
	for(int i=0;i<nums.size();i++)
	{
		arrsum+=nums[i];
	}
	return formuSum - arrsum;

}

/**
 * 方法 2,排序,然后看下一个数是不是当前数+1,然后判断缺少的数字
*/
int missingNumber2(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	for(int i=1;i<nums.size();i++)
	{
		if(nums[i]!=nums[i-1]+1)
		{
			return nums[i]-1;
		}
	}
}






int main()
{
	vector<int>nums = {9,6,4,2,3,5,7,0,1};
	cout<<missingNumber2(nums);
	
	return 0;

}


















