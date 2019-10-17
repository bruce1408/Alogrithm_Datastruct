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
vector<int> intersect1(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int, int>res1;
    vector<int>res;
    for(int i=0;i<nums1.size();i++)
    {
        res1[nums1[i]]++;
    }
    for(int j = 0; j<nums2.size(); j++)
    {
        if(res1[nums2[j]]>0)
        {
            res.push_back(nums2[j]);
            res1[nums2[j]]--;
        }

        /**
         * 上面的代码也可以再简化，就是
         * if(res1[nums2[j]]-- >0)
         * {
         *      res.push_back(nums2[j]);
         * }
         * 先判断双目运算符，然后再来判断单
        */
    }
    return res;
}

/**
 * 方法 2，先对两个数组排序，然后设置两个指针，如果两个指针指向的相同就同时
 * 向后加1，否则，哪个小，哪个就向后移动一位；
*/
vector<int> intersect2(vector<int>& nums1, vector<int>& nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i=0,j=0;
    vector<int>res;
    while(i<nums1.size() && j<nums2.size())
    {
        if(nums1[i]<nums2[j])
        {
            i++;
        }
        else if(nums1[i]>nums2[j])
        {
            j++;
        }
        else
        {
            res.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    return res;
}

int main()
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    for (auto i : intersect2(nums1, nums2))
        cout << i << " ";
    return 0;
}
