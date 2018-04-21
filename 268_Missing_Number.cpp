/*268. Missing Number

Input: [3,0,1]
Output: 2
Example 2

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

/*第一种方法：哈希思路*/
int missingNumber(vector<int>& nums)
{
	int lenth = nums.size();
	int res=0;
	int sum_res = 0.5*lenth*(lenth+1);
	for(auto i:nums)
	{
		res+=i;
	}
	return sum_res-res;
	
}






int main()
{
	vector<int>nums = {9,6,4,2,3,5,7,0,1};
	cout<<missingNumber(nums);
	
	return 0;

}


















