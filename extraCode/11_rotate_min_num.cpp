#include<iostream>
#include<vector>
using namespace std;
/**
 * 题目： 数组开始的若干位旋转到数组的末尾；
*/
void sortAges(vector<int> &res)
{
	if(res.size()<=0)
		return ;
	int n=res.size();
	
	vector<int>temp(n,0);
	for(int i=0;i<n;i++)
	{
		int age = res[i];
		++temp[age];
	}
	cout<<"temp :"<<endl;
	for(auto i:temp)
		cout<<i<<" ";
	cout<<endl;
	
	int index = 0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<temp[i];j++)
		{
			res[index] = i;
			cout<<i<<endl;
			++index;
		}
	}
}

//11_旋转数组得到最小值
int min_num(vector<int> res)
{
	int n = res.size();
	if(n<=0) return 0;
	int index1 = 0;
	int index2 = n-1;
	int indexmid = index1;
	while(res[index1]>=res[index2])
	{
		if(index2-index1==1)
		{
			indexmid = index2;
			break;
		}
		indexmid = (index1+index2)/2;
		if(res[indexmid]>=res[index1])
			index1 = indexmid;
		
		else if(res[indexmid]<=res[index2])
			index2 = indexmid;
	}
	return res[indexmid];
}
int main()
{
	vector<int>res = {3,5,2,7,3,8,3,6,7,6,5,4,5,4,12,12,2,4,5,6,8,9};
	sortAges(res);
	cout<<endl;
	for(auto i:res)
		cout<<i<<" ";
	
}









