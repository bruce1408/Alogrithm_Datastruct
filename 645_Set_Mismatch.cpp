/*645. Set Mismatch
Input: nums = [1,2,2,4]
Output: [2,3]
*/


#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

// vector<int> findErrorNums(vector<int>& nums)
// {
	// map<int,int>temp;
	// vector<int>res;
	// int lastNum;
	// // if(nums.size()==2 && nums[0]==nums[1])
		// // return nums;
		
	// for(int i=0;i<nums.size();i++) ++temp[nums[i]];
	// if(temp.size()==1)
	// {
		// res.push_back(1);
		// res.push_back(nums[0]);
		// return res;
	// }
	// for(auto x:temp)
	// {
		// if(x.second==2 && res.empty() &&res.size()<2)
		// {
			// res.push_back(x.first);
			// if(temp.find(x.first+1)==temp.end())
			// {
				// res.push_back(x.first+1);
				// break;
			// }
		// }
		// if(x.second==2 && !res.empty() && temp.find(x.first+1)==temp.end())
			// res.push_back(x.first+1);
		// lastNum = x.first;
	// }
	// if(res.size()==2)
		// return res;
	// else
	// {	
		// res.push_back(lastNum+1);
		// return res;
	// }
// }


vector<int> findErrorNums(vector<int>& nums) 
{
	vector<int> res(2, 0), cnt(nums.size(), 0);
	for (int num : nums) ++cnt[num - 1];
	for (int i = 0; i < cnt.size(); ++i) 
	{
		if (res[0] != 0 && res[1] != 0) return res;
		if (cnt[i] == 2) res[0] = i + 1;
		else if (cnt[i] == 0) res[1] = i + 1;
	}
	return res;
}




int main()
{
	vector<int>input_num= {3,3,1,4,5};
	// vector<int>input_num= {2,2};
	vector<int> res = findErrorNums(input_num);
	for(auto i:res)
		cout<<i<<" ";
	
	
	
	return 0;

}



















































































