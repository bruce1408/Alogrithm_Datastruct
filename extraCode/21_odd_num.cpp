#include<iostream>
#include<vector>
using namespace std;


//这道题目是把奇数放在偶数的前面，这个题目受到的启发就是从两头往中间的方法。
void beforeOddnum(vector<int>&res)
{
	int left=0,right = res.size()-1;
	while(left<right)
	{
		if((res[left]&1))
			left++;
		else if(!(res[left]&1) && (res[right]&1))
		{
			int temp = res[left];
			res[left] = res[right];
			res[right] = temp;
			left++;
			right--;
		}
		else right--;	
	}
}

int main()
{
	vector<int>res = {1,2,3,4,5};
	// vector<int>res = {1};
	beforeOddnum(res);
	for(auto i:res)
		cout<<i<<" ";
	return 0;
}