/*260. Single Number III  和 136 的异或不一样，异或只能求一个数*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

/*第一种方法：哈希思路*/
vector<int> singleNumber(vector<int>& nums)
{
	vector<int>res;
	unordered_map<int,int>temp;
	for(int i=0;i<nums.size();i++)
	{
		++temp[nums[i]];
	}
	
	for(auto &x:temp)
	{
		if(x.second<2)
			res.push_back(x.first);
	}
	return res;
}






int main()
{
	vector<int>nums = {1,2,1,3,2,5};
	vector<int>res;
	res = singleNumber(nums);
	for(auto i:res)
		cout<<i<<" ";

	
	return 0;

}






