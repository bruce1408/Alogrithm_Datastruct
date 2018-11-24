/*1. Two Sum

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]

*/

/*49. Group Anagrams

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[["ate","eat","tea"], ["nat","tan"], ["bat"]]

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

/*一开始想多了，这个target必须是由两个数字构成，不可能出现2,3,4的情况*/
// vector<int> twoSum(vector<int>& nums, int target)
// {
	// unordered_map<int,int>temp;
	// vector<int>res;
	// for(int i=0;i<nums.size();i++)
	// {
		// temp[nums[i]]=i;
	// }
	
	// for(int i=0;i<nums.size();i++)
	// {
		// int t = target-nums[i];
		// if(temp.count(t) && temp[t]!=i)
		// {
			// cout<<temp.count(t)<<endl;
			// res.push_back(i);
			// res.push_back(temp[t]);
			// break;
		// }
	// }
	// return res;
// }

/*给for循环强加条件来优化代码，比如nums[i]<=target,但是没有考虑到负数！另外find()和count()函数都是判断是否存在这个数，
，*/
vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int,int>temp;
	vector<int>res;
	for(int i=0;i<nums.size();i++) temp[nums[i]]=i; // 位置索引
	for(int i=0;i<nums.size();i++)
	{
	 /*先找到这个数，判断是否存在，且位置坐标不是当前循环的i的位置，因为是同一个数，闹乌龙了，然后添加到res里面*/
		int left = target - nums[i]; // 找到了这个数字
		if(temp.count(left) && temp[left]!=i) // 找到这个数字并且这个数字不是自己
		{
			// res.push_back(i);
			// res.push_back(temp[left]);
			return {i, temp[left]}; // 有了这一步，前面两行都不用了，但是推荐用生成res
		}
	}
	return {};
}


// 自己再做一遍
vector<int> sumofTwo(vector<int> & nums, int k)
{
	int sum;
	// sort(nums.begin(),nums.end());
	vector<int>res;
	for(int i=0;i<nums.size();i++)
	{
		int left = i,right = nums.size()-1;
		// if(nums[i]==nums[i+1]) continue;
		while(left<right && res.empty())
		{
			sum = nums[left]+nums[right];
			if(sum==k)
			{
				res.push_back(left);
				res.push_back(right);
				cout<<left<<" "<<right<<endl;
				// left++;
				// right--;
				break;
			}
			else if(sum>k) right--;
			else left++;
		}	
	}
	return res;
}


int main()
{
	vector<int>nums = {-10,-1,-18,-19};
	vector<int>res_inde;
	int t = -19;
	res_inde = twoSum(nums,t);
	for(auto i:res_inde)
		cout<<i<<" ";
	return 0;
}







