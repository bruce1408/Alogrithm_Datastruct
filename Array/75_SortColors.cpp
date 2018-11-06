#include<iostream>
#include<vector>
using namespace std;

/*-----------------------1、快速排序的方法来解决三色旗的问题--------------------*/
class Solution
{
	public:
	
	void swap(vector<int> &num,int low,int high)
	{
		int temp = num[low];
		num[low] = num[high];
		num[high] = temp;
	}
	
	int partition(vector<int> &num,int low,int high)
	{
		int piovkey = num[low];
		while(low<high)
		{
			while(low<high && num[high]>=piovkey)
			{
				high--;
			}
			swap(num,low,high);
		
			while(low<high && num[low]<=piovkey)
			{
				low++;
			}
			swap(num,low,high);
		}
		return low;
	}
	
	void Quicksort(vector<int> &num,int low,int high)
	{
		int poiv;
		while(low<high)
		{
			poiv = partition(num,low,high);
			Quicksort(num,low,poiv-1);
			low = poiv + 1;
		}
	}
	
	void sortColors(vector<int>& nums)
	{
		int high = nums.size()-1;
		Quicksort(nums,0,high);
	}
};


print_vec(vector<int> num)
{
	for(auto i:num)
		cout<<i<<" ";
	cout<<endl;
}

/*--------------------------2、统计个数解决三色旗问题---------------------------*/

void sortC(vector<int> &num)
{
	int count0 = 0,count1 = 0,count2 = 0;
	for(auto i:num)
	{
		if(i==0)
			count0++;
		else if(i==1)
			count1++;
		else
			count2++;
	}
	
	int j=0;
	
	//关键步骤；将统计好的个数分别放到里面。
	while(j<count0)
		num[j++]=0;
	
	while(j<count1+count1)
		num[j++]=1;
	
	while(j<count0+count1+count2)
		num[j++]=2;
	
}


int main()
{
	vector<int> num = {0,2,1,0,1};
	print_vec(num);
	// Solution s;
	// s.sortColors(num);
	sortC(num);
	print_vec(num);
	
}