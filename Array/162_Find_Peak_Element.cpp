#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<climits>
using namespace std;

/**
 * A peak element is an element that is greater than its neighbors.
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 * You may imagine that nums[-1] = nums[n] = -∞.
 * 
 * Input: nums = [1,2,3,1]
 * Output: 2
 * 
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5 
 * 找出数组的局部最大值，局部最大，不要求是全局最大。所以
 * 考虑比周围两个数字都大的数字，只需要和周围两个数字比较即可，和左右比较的话，
*/

/**
 * 方法 1，利用两个标记值，在数组的开头插入最小的数min，在最后插入最大的数
 * max，如果这里用遍历整个数组找最大值肯定会出现Time Limit Exceeded，
 * 但题目中说了这个峰值可以是局部的最大值，所以我们只需要找到第一个局部峰值就可以了。
 * 所谓峰值就是比周围两个数字都大的数字，那么只需要跟周围两个数字比较就可以了。既然要跟左右的数字比较，
 * 就得考虑越界的问题，题目中给了nums[-1] = nums[n] = -∞，那么我们其实可以把这两个整型最小值直接加入到数组中，
 * 然后从第二个数字遍历到倒数第二个数字，这样就不会存在越界的可能了。由于题目中说了峰值一定存在，
 * 那么有一个很重要的corner case我们要注意，就是当原数组中只有一个数字，
 * 且是整型最小值的时候，我们如果还要首尾垫数字，就会形成一条水平线，从而没有峰值了，
 * 所以我们对于数组中只有一个数字的情况在开头直接判断一下即可，参见
*/
int findPeakElement(vector<int>& nums)
{
    if(nums.size()==1) return 0;
    nums.insert(nums.begin(), INT_MIN); // 开头插最小
    nums.push_back(INT_MAX); // 最后插最大
    for(int i=1;i<nums.size()-1;i++)
    {
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) // 每一个i都大于它的前后两个数字即可；
            return i-1; // 大于前一个数字，和后一个数字
    }
    return -1;
}

/**
 * 方法 2，对方法 1的改进，
 * 判断后一个数只要小于前一个数字，那么这个数字的前一个数字就是局部最大数返回前一个数的下标索引即可
 * 否则，最后返回数组最后一个数字的下标索引；
 */ 
int findPeakElement1(vector<int>& nums) 
{
    for (int i = 1; i < nums.size(); ++i) 
    {
        if (nums[i] < nums[i - 1]) return i - 1;
    }
    return nums.size() - 1;
}

/**
 * 方法 3，使用二分查找来做，
 * 判断 mid 和 mid+1 之间的大小，如果mid < mid+1,那么left=mid+1，缩小范围，
 * 否则，right = mid，最后返回left即可；
*/
int findPeakElement2(vector<int>& nums)
{
    int left = 0, right = nums.size()-1;
    while(left<right)
    {
        int mid = left + (right-left)/2;
        if(nums[mid] < nums[mid+1])
        {
            left = mid+1;
        }
        else
        {
            right = mid;
        }
    }
    return right;
}


int main()
{
    vector<int> nums = {1,3,2,1};
    int k = findPeakElement(nums);
    cout<<k<<endl;
    return 0;    
}