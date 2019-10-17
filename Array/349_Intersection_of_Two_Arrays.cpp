#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * Given two arrays, write a function to compute their intersection.
 * Example 1:
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * Example 2:
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * 
 * 求解两个数组的交集即可
*/

/**
 * 方法 1，暴力搜索来遍历即可；把两个数组放到集合中，然后开始遍历每个集合
 * 最后如果数字相等就放到结果数组res中，时间复杂度是O(n1*n2)
*/
vector<int> intersection1(vector<int> &nums1, vector<int> &nums2)
{

    set<int> res1(nums1.begin(), nums1.end());
    set<int> res2(nums2.begin(), nums2.end());
    vector<int> res;
    for (set<int>::iterator it = res1.begin(); it != res1.end(); it++)
    {
        for (set<int>::iterator it2 = res2.begin(); it2 != res2.end(); it2++)
        {
            if (*it == *it2)
            {
                res.push_back(*it);
            }
        }
    }
    return res;
}

/**
 * 方法 2，利用查找的思路来做,但是和上面的时间复杂度没有多大区别
*/
vector<int> intersection2(vector<int> &nums1, vector<int> &nums2)
{

    set<int> res1(nums1.begin(), nums1.end());
    set<int> res2(nums2.begin(), nums2.end());
    vector<int> res;
    for (set<int>::iterator it = res1.begin(); it != res1.end(); it++)
    {
        if (res2.count(*it) > 0)
        {
            res.push_back(*it);
        }
    }
    return res;
}

/**
 * 方法 3， 利用二分查找的思路来做；
*/
vector<int> intersection3(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() == 0 or nums2.size() == 0)
        return {};
    set<int> res1(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    for (set<int>::iterator it = res1.begin(); it != res1.end(); it++)
    {
        int left = 0, right = nums2.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums2[mid] < *it)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (left < nums2.size())
        {
            res.push_back(nums2[left]);
        }
    }
    return res;
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    for (auto i : intersection3(nums1, nums2))
        cout << i << " ";
    return 0;
}
