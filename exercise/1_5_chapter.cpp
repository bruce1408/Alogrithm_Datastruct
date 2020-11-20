#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include "../utils/cout_vec.h"
using namespace std;


class Solution
{
	public:
	int findnum(vector<int> &a, int n,int key)
	{
		sort(a.begin(),a.end());
		auto i = max_element(a.begin(),a.end());
		int maxnum = *i;
		int count =0;
		for(auto j: a)
		{
			if(j+key<=maxnum)
			{
				count++;
			}
		}
		return count;
	}
};


int main()
{
	
	vector<int> a = {2,3,4,5,6};
	print(a);
	int n = a.size();
	int key = 2;
	Solution ss;
	
	cout<<ss.findnum(a,n,key)<<endl;
	
	return 0;
}