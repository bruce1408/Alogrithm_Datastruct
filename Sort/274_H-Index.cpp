/*---------------- 274. H-Index ----------------
  首先把序列进行排序，注意是逆序排序，然后对这个序列进行分析，如果指数大于等于当前的
  这个序列值的话，那么返回这个数，否则，指数自增，如果都不满足条件，那么最后输出的是
  序列的个数。*/
#include<iostream>
#include<vector>
using namespace std;


class Solution
{
	public:
	
	void print_vec(vector<int> a)
	{
		for(auto i:a)
			cout<<i<<" ";
		cout<<endl;
	}
	void swap(vector<int> &citations,int low,int high)
	{
		int temp = citations[low];
		citations[low] = citations[high];
		citations[high] = temp;
	}
	
	int partition(vector<int> &citations,int low,int high)
	{
		int pivotkey;
		pivotkey = citations[low];
	
		while(low<high)
		{
			while(low<high && citations[high]<=pivotkey)
				high--;
			swap(citations,low,high);
		
			while(low<high && citations[low]>=pivotkey)
				low++;
			swap(citations,low,high);
		}
		return low;
	}
	
	void Msort(vector<int> &citations,int low,int high)
	{
		int pivot ;
		while(low<high)
		{
			pivot = partition(citations,low,high);
			Msort(citations,low,pivot-1);
			low = pivot+1;
		}
	}
	
	int hIndex(vector<int>& citations)
	{
		Msort(citations,0,citations.size()-1);
		for(int index=0;index<citations.size();++index)
		{
			if(index>=citations[index])
				return index;
		}
		return citations.size() ;
	}
	
	
	
};



int main()
{
	vector<int> a ={3,0,6,1,5};
	// vector<int> a ={6,6,6,6,6};
	Solution s;
	s.Msort(a,0,a.size()-1);
	s.print_vec(a);
	
	cout<<"指数是： "<<s.hIndex(a)<<endl;
	return 0;
	
}






