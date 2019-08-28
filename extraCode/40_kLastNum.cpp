#include<iostream>
#include<vector>
#inlcude<queue>
using namespace std;


void kthSmallest(vector<int>&res,int k)
{
	sort(res.begin(),res.end());
	for(int i=0;i<k;i++)
		cout<<res[i]<<" ";
	cout<<endl;
}