#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

/**
 * Find the kth largest element in an unsorted array. 
 * Note that it is the kth largest element in the sorted order,
 * not the kth distinct element.
 * 
 * Example 1:
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * Example 2:
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 找到一个数组的第k个最大的数字
**/ 

/**
 * 方法 1，利用最大堆来做
*/
int findKthLargest(vector<int>& nums, int k) {
    int len = nums.size();
    priority_queue<int>mypq;
    for(int i=0;i<len;i++)
    {
        mypq.emplace(nums[i]);
    }
    for(int i=0;i<k-1;i++)
    {
        mypq.pop();
    }
    return mypq.top();

    
}

int main()
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout << findKthLargest(nums, 4) << endl;

    return 0;
}