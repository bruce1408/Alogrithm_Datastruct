/*137. Single Number II

只有一个出现一次，其他的都会出现三次，找到那个出现一次的

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99

*/


#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

/*第一种方法：哈希思路*/
int singleNumber(vector<int>& nums)
{
	int res;
	unordered_map<int,int>temp;
	for(int i=0;i<nums.size();i++)
	{
		++temp[nums[i]];
	}
	
	for(auto &x:temp)
	{
		if(x.second<2)
			return x.first;
	}
	return 0;
}






int main()
{
	vector<int>nums = {0,10,1,0,1,99};
	cout<<singleNumber(nums);
	
	return 0;

}






