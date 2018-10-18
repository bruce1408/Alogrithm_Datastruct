#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;


//给定一个数组，然后从数组里面找到最小的k个数字输出
//方法一：直接利用algorithm模块来排序，然后找到第k个最小数字，缺点是原数组顺序打乱，如果是海量数据，就不可取


int findKthLargest1(vector<int>& nums, int k) 
{
	sort(nums.begin(), nums.end());
	return nums[nums.size() - k];
}


// 方法二：利用最大堆来做，但是海量数据不可以
int findKthLargest2(vector<int>& nums,int k)
{
	
	priority_queue<int> q(nums.begin(),nums.end());
	for(int i=0;i<k-1;i++)
		q.pop();
	return q.top();
	
}

void test(vector<int>&nums,int left, int right)
{
	int pivot = nums[left], l = left + 1, r = right;
	while (l <= r) 
	{
		if (nums[l] < pivot && nums[r] > pivot) 
		{
			swap(nums[l++], nums[r--]);
			cout<<l<<" "<<r<<endl;
			cout<<endl;
		}
		if (nums[l] >= pivot) 
		{
			++l;
			cout<<l<<" ";
		}
		if (nums[r] <= pivot) --r;
	}
		
}


/*
方法三：上面两种方法虽然简洁，但是确不是本题真正想考察的东西，可以说有一定的偷懒嫌疑。
这道题最好的解法应该是下面这种做法，用到了快速排序Quick Sort的思想，这里排序的方向是从大往小排。
核心思想是每次都要先找一个中枢点Pivot，然后遍历其他所有的数字，像这道题从大往小排的话，就把小于中枢点的数字放到左半边，
把大于中枢点的放在右半边，这样中枢点是整个数组中第几大的数字就确定了，虽然左右两部分不一定是完全有序的，
但是并不影响本题要求的结果，所以我们求出中枢点的位置，如果正好是k-1，那么直接返回该位置上的数字；如果大于k-1，
说明要求的数字在左半部分，更新右边界，再求新的中枢点位置；反之则更新右半部分，求中枢点的位置；
*/
int main()
{
	vector<int> res = {3,2,1,5,6,4};
	int k;
	cin>>k;
	// cout<<findKthLargest2(res,k);
	test(res,0,5);
	return 0;
}































