#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 找出这个目标数的起始位置和结束位置，时间复杂度是O(longn) 总是少边界条件、错误的
// vector<int> searchRange(vector<int>& nums, int target)
// {
//     int left = 0, right = nums.size()-1;
//     vector<int> res;
//     // if(nums.size()==1) return {0,0};
//     while(left<=right)
//     {
//         int mid = (left+right)/2;
//         if(nums[mid]==target && nums[mid-1]==target) return {mid-1, mid};
//         else if(nums[mid]==target && nums[mid+1]==target) return {mid, mid+1};
//         else if(nums[mid]==target && nums.size()==1) return {mid, mid};
//         else if(nums[mid]<target) mid++;
//         else if(nums[right]>target) right = mid;
//     }
//     return {-1,-1};
// }


// 好的解决方案
// vector<int> searchRange(vector<int> &nums, int target) 
// {

//     int left = 0, right = nums.size() - 1;
//     vector<int> ret(2, -1);
//     // Search for the left one
//     while (left < right)
//     {
//         int mid = (left + right) /2;
//         if (nums[mid] < target) left = mid + 1;
//         else right = mid;
//     }
//     if (nums[left]!=target) return ret;
//     else ret[0] = left;
    
//     // Search for the right one
//     right = nums.size()-1;  // We don't have to set i to 0 the second time.
//     while (left < right)
//     {
//         int mid = (left + right) /2 + 1;	// Make mid biased to the right
//         if (nums[mid] > target) right = mid - 1;  
//         else left = mid;				// So that this won't make the search range stuck.
//     }
//     ret[1] = right;
//     return ret; 
// }


vector<int> searchRange(vector<int>& nums, int target) 
{
    // pair<vector<int>::iterator, vector<int>::iterator> bounds;

    auto bounds = equal_range(nums.begin(), nums.end(), target);
    if (bounds.first == bounds.second)
    {
        return {-1, -1};
    }    
    return {bounds.first-nums.begin(), bounds.second-nums.begin() - 1};
}

int main()
{
    vector<int> res = {1,3};
    searchRange(res, 1);
    // for(auto i:searchRange(res, 1))
    // {
    //     cout<<i<<" ";
    // }
    return 0;
}