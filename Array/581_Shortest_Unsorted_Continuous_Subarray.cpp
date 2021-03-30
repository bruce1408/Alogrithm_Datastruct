#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Given an integer array, you need to find one continuous subarray that 
 * if you only sort this subarray in ascending order, then the whole 
 * array will be sorted in ascending order, too.
 * You need to find the shortest such subarray and output its length.
 * Example 1:
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * 
 * 给定一个数组，然后找出最短的不是升序的子数组，这个子数组如果按照升序排序之后仍然
 * 原来的数组仍然是升序排列的数组。
*/

/**
 * 方法 1创建一个和原来一样的数组，然后排序，排序之后的新数组开始和
 * 原来的数组一一对比对应位置上的元素是否相同，如果是不同，记录开始和结束的位置，
 * 开始位置和结束位置都初始为-1，如果下次相同位置上的数字不同，那么结束标志一直更新即可，
 * 开始位置为第一次不同时候的标记位，最后把这个位置相减即可得到最小子数组的长度
 * O(n)时间 O(n)空间
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        vector<int>temp(nums);
        sort(temp.begin(), temp.end());
        int l = 0, r = nums.size()-1;
        while(l < nums.size() && nums[l]==temp[l]) l++;

        while(r >= 0 && nums[r]==temp[r]) r--;
        
        return max(r - l + 1, 0);
    }
};

/**
 * 方法 3很厉害，只用O(n)的时间复杂度，空间复杂度是O(1)
 * 主要思路就是如何找出在这个无序区间内的最小值和最大值！[2,6,4,8,10,9,15]中的无序区间是
 * [6,4,8,10,9]它的最小值是4，最大值是10，最小值是从第二个开始找，最大值是从倒数第二个找起。
 * 首先判断数组中的不按照升序的最大数和最小数，以[2,6,4,8,10,9,15]为例子，第一次不按照升序
 * 的最小数字是4，不按照升序的最大数字是10，找到之后，用两个指针，i和j，i从第一个开始，如果当前
 * 的数字比最小数4还要大，那么就说明这个数组是不按照升序的顺序，记录下来，退出循环，如果当前
 * 数字比这个数字小，那继续遍历；同样，指针j从后开始，如果当前数字比最大的数字还要大，那么正常，
 * 按照的是升序的，继续往前遍历，如果当前的数字比最大的数字要小，说明这个数不是升序排列的，记录位置
 * 最后j的位置减去i的位置+1即可。
 * 
*/
int findUnsortedSubarray(vector<int>& nums) 
{
    int n = nums.size();
    int l = 0, r = nums.size()-1;

    while(l + 1 < n && nums[l+1] >=nums[l]) l++;
    if(l==r) return 0;

    while(r-1>=0 && nums[r-1] <=nums[r]) r--;


    for(int i = l+1;i<nums.size();i++)
    {
        while(l>=0 && nums[l]>nums[i]) l--;
    }
    for(int i = r-1;i>=0;i--)
    {
        while(r < nums.size()&& nums[r] < nums[i]) r++;
    }
    return r - l -1;
}

int main()
{
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    cout << findUnsortedSubarray3(nums) << endl;
    return 0;
}