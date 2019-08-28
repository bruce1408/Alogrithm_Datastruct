#include<iostream>
#include<vector>
using namespace std;

/**
 * 题目：调整，使得数组中的奇数位于数组前面，偶数位于数组后面
 * 方法1 双指针
 * 思路：
 * 利用双指针来做，第一个指针从开头往后指，最后一个指针从后往前走，如果第一个指针是偶数就停下，后面的指针遇到奇数就停下，然后互换两个指针指向的值；知道第一个指针的
 * 不小于后一个指针，则互换停止
 * */
void beforeOddnum(vector<int>&res)
{
	int left=0,right = res.size()-1;
	while(left<right)
	{
		if((res[left]&1)) // 如果是奇数，那么右移
			left++;
		// 如果左边指针的值不是奇数，且右边的指针是奇数，那么就互换。
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

// 方法2 利用双指针，一样的思路，只不过这里是用两个while循环
void beforeOddNum(vector<int> & res)
{
	if(res.size()==0) return ;
	int left = 0, right = res.size()-1;
	while(left < right)
	{
		while(res[left]%3==0) left++;
		while(!(res[right]%3==0)) right--;
		if(left<right)
		{
			int temp = res[left];
			res[left] = res[right];
			res[right] = temp;
		}
	}	
}
int main()
{
	vector<int>res = {1,2,3,4,5,6,9,18};
	// vector<int>res = {1};
	// beforeOddnum(res);
	beforeOddNum(res);
	for(auto i:res)
		cout<<i<<" ";
	return 0;
}