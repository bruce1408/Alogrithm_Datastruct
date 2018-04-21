/*136. Single Number
Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

/*第一种方法：哈希思路*/
int singleNumber(vector<int>& nums)
{
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

/*第二种思路；利用异或！！*/
vector<int> twoSum(vector<int>& numbers, int target) 
{
	int l = 0, r = numbers.size() - 1;
	while (l < r) {
		int sum = numbers[l] + numbers[r];
		if (sum == target) return {l + 1, r + 1};
		else if (sum < target) ++l;
		else --r;
	}
	return {};
}


int main()
{
	vector<int>nums = {2,1,1,3,3};
	int m=0;
	int t = singleNumber(nums);
	cout<<t<<endl;
	
	int mm=2;
	mm=m^mm;
	cout<<mm<<endl;
	for(auto i:nums)
	{
		m^=i;
		cout<<m<<" ";
	}
	
	return 0;

}







