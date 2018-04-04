#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;





class Solution 
{
	public:
    void wiggleSort(vector<int>& nums) 
	{
		vector<int> sorted(nums);
		sort(nums.begin(),nums.end());
		for (int i=nums.size()-1, j=0, k=i/2+1; i>=0; i--)
			nums[i] = sorted[i&1 ? k++ : j++];
    }
};	
	
	


int main()
{
	vector<int>nums = {1,5,1,1,6,4};
	Solution s;
	s.wiggleSort(nums);
	for(auto i:nums)
		cout<<i<<" ";
	cout<<endl;
	
	
	return 0;
}