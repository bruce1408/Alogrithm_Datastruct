#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/**
 * 题目： 数组开始的若干位旋转到数组的末尾，输入时一个部分递增的数组，例如[3,4,5,1,2]
 * 旋转后是[1,2,3,4,5]，那么最小的旋转数字是 1, 时间复杂度是O(logN)
 * 方法1 二分思路递归找两部分的最小值；
 * 思路：首先明确一点，就是这个判断最小的翻转的数肯定是要和之前的一个数比较才能看出是最小，那么这个比较的话，必须是两个不同的数，
 * 所以我们认为是left和right之间相差1；我们有一个mid中位数，如果下标是中位数的数大于左边的数，那么说明最小的数不在这个范围区间，
 * 如果下标的中位数小于右边的数，那么说明最小的数不在右边的范围区间，因为他们都是升序连续的数组，然后不断的尝试，最后找到了这两个数，比如是 5，1 那么
 * 我们只需要取最小的数即可；
 * 
 * 方法2 
 * 思路：
 * 排序该数组，然后第一个元素就是我们要找的数，但是时间复杂度nlogn，比较高
 * 发散：leetcode 153. Find Minimum in Rotated Sorted Array
 * 
 * 方法3
 * 思路：
 * 扫描一面，然后找出最小的数即可
*/

int min_num1(vector<int> res) // 本题目的最好的解法！
{
	int left = 0, right = res.size()-1;
	if(res[left]<res[right]) return res[0]; // 其实是已经排好序了，返回的最小值
	else
	{
		int mid = left + (right - left)/2;
		if(res[mid]>res[left]) left = mid;
		else right = mid;
	}
	return min(res[left], res[right]);
}

// void sortAges(vector<int> &res)
// {
// 	if(res.size()<=0)
// 		return ;
// 	int n=res.size();
	
// 	vector<int>temp(n,0);
// 	for(int i=0;i<n;i++)
// 	{
// 		int age = res[i];
// 		++temp[age];
// 	}
// 	cout<<"temp :"<<endl;
// 	for(auto i:temp)
// 		cout<<i<<" ";
// 	cout<<endl;
	
// 	int index = 0;
// 	for(int i=0;i<=n;i++)
// 	{
// 		for(int j=0;j<temp[i];j++)
// 		{
// 			res[index] = i;
// 			// cout<<i<<endl;
// 			++index;
// 		}
// 	}
// }

int min_num2(vector<int> res)
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
	// vector<int>res = {3,4,5,1,2};
	vector<int> res = {4, 5, 6, 7, 0, 1, 2};
	// sortAges(res);
	cout<<min_num1(res)<<endl;	
}









