#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
# include <unordered_set>
#include <string>
using namespace std;

/**
 * Given two arrays, write a function to compute their intersection.
 * Example 1:
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 * Example 2:
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * 
 * 重复的数字输出出来，每个元素尽可能多的出现,就是说重复的元素在两个数组中出现的次数
 * 例如 2，在两个数组出现的次数都是2，那么最后输出的就是2,2；
*/

/**
 * 方法 1，利用的哈希map来做，记录的是出现的次数；
*/
vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    
}


int main()
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    for (auto i : intersect(nums1, nums2))
        cout << i << " ";
    return 0;
}
