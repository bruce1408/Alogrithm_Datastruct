#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
Small half:    4 . 3 . 2 . 1 . 0 .
Large half:    . 9 . 8 . 7 . 6 . 5
----------------------------------
Together:      4 9 3 8 2 7 1 6 0 5
*/




class Solution 
{
	public:
    void wiggleSort(vector<int>& nums) 
	{
		vector<int> sorted(nums);
		sort(sorted.begin(),sorted.end());
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