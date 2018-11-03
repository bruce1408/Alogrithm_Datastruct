#include<iostream>
#include<vector>
using namespace std;
/**
 * 给定一个数组，求出数组中元素相加的和是最大的那个连续子数组
 * A Divide and Conquer based program for maximum subarray sum problem 
*/
int max(int a, int b) { return (a > b)? a : b; } 
int max(int a, int b, int c) { return max(max(a, b), c); } 
// Find the maximum possible sum in arr[] such that arr[m] is part of it 
int maxCrossingSum(int arr[], int l, int m, int h) 
{ 
    //
	int sum = 0; 
    int left_sum = INT_MIN; // 最小值 
	for (int i = m; i >= l; i--) 
	{ 
		sum = sum + arr[i]; 
		if (sum > left_sum) left_sum = sum; 
        cout<<"left sum is: "<<left_sum<<endl;
	} 
	// Include elements on right of mid 
	sum = 0; 
	int right_sum = INT_MIN; 
	for (int i = m+1; i <= h; i++) 
	{ 
		sum = sum + arr[i]; 
		if (sum > right_sum) right_sum = sum;
        cout<<"right sum is: "<<right_sum<<endl; 
	} 
	// Return sum of elements on left and right of mid 
	return left_sum + right_sum; 
} 


int maxSubArraySum(int arr[], int l, int h) 
{ 
    if (l == h) return arr[l]; 
    int m = (l + h)/2; 
    /* Return maximum of following three possible cases 
        a) Maximum subarray sum in left half 
        b) Maximum subarray sum in right half 
        c) Maximum subarray sum such that the subarray crosses the midpoint */
    return max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m+1, h), maxCrossingSum(arr, l, m, h)); 
} 

/*Driver program to test maxSubArraySum*/


// 方法二；kadane's algorithm 求子序列最大值问题，设置当前最大值和全局最大值的初始值都是第一个元素，
// 遍历数组，每次找到最大的：当前最大值 = max(nums[i],当前最大值 + nums[i])，最后保留最大的给global_sum
int MaxSubArray(vector<int>&nums)
{
    int global_sum = nums[0], current_sum=nums[0];
    int Maxsum = 0;
    for(int i=1;i<nums.size();i++)
    {
        current_sum = max(nums[i],current_sum+nums[i]);
        if(current_sum>global_sum) global_sum = current_sum;
    }
    return global_sum;
}

int main() 
{ 
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4}; 
    vector<int> nums = {arr, arr+9};
    cout<<MaxSubArray(nums)<<endl;
    // int n = sizeof(arr)/sizeof(arr[0]); 
    // int max_sum = maxSubArraySum(arr, 0, n-1); 
    // cout<<"Maximum contiguous sum is: "<<max_sum<<endl; 
    return 0; 
} 
