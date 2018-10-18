/*217. Contains Duplicate
	包含重复项输出true，否则是false
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


bool containsDuplicate(vector<int>& nums)
{
	unordered_map<int,int> res;
	for(int i=0;i<nums.size();i++)
	{
		if(res.find(nums[i])!=res.end())
			return true;
		++res[nums[i]];
	}
	return false;
}

int main()
{
	vector<int> nums = {1,2,3,4,5,6,6};
	if(containsDuplicate(nums))
		cout<<"有重复的值"<<endl;
	return 0;
}





































