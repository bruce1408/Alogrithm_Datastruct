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
    set<int> res;
    for (int i=0;i<nums1.size();i++)
    {
        for (int j=0;j<nums2.size();j++)
        {
            if (nums1[i]==nums2[j])
            {
                res.insert(nums1[i]);
            }
        }
    }
    return vector<int>(res.begin(), res.end());
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
 * 方法 3， 利用二分查找的思路来做；最后把结果放进set集合中，返回vector
 * 就是把一个数组通过set集合处理，然后第二个数组排序，遍历第一个数组，在第二个数组中进行二分查找；
 * 时间复杂度粗略的算是O(nlogn)
*/
vector<int> intersection3(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() == 0 or nums2.size() == 0)
        return {};
    set<int> res1(nums1.begin(), nums1.end()), res;
    sort(nums2.begin(), nums2.end());
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
        if(left < nums2.size() and nums2[left]==*it)
                res.insert(nums2[left]);
    }
    return vector<int>(res.begin(), res.end());
}

/**
 * 方法 3_1, 改进版本的二分查找；和上面的二分查找的算法相比，速度更快，原因是在相等的时候直接return
 * 一个布尔类型的值；
*/
bool binarySearch(vector<int>&nums, int target)
{
    int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if(nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                return true;
            }
        }
        return false;
}

vector<int> intersection3_1(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums2.begin(), nums2.end());
    set<int>res;
    for(auto a:nums1)
    {
        if(binarySearch(nums2, a))
        {
            res.insert(a);
        }
    }
    return vector<int>(res.begin(), res.end());
}

/**
 * 方法 4，方法 5思路思路都是一样的
*/
vector<int> intersection4(vector<int> &nums1, vector<int> &nums2)
{
    set<int>res1(nums1.begin(), nums1.end());
    vector<int>res;
    for(int i=0;i<nums2.size();i++)
    {
        int len = res1.size();
        res1.erase(nums2[i]);
        if(res1.size()!=len)
        {
            res.push_back(nums2[i]);
        }
    }
    return res;
}

/**
 * 方法 5， 方法 4, 方法 3思路相同；写法更加简单
*/
vector<int> intersection5(vector<int> &nums1, vector<int> &nums2)
{
    set<int>res1(nums1.begin(), nums1.end());
    vector<int>res;
    for(auto i: nums2)
    {
        if(res1.erase(i)) // 存在的话返回1，否则返回0；
        {
            res.push_back(i);
        }
    }
    return res;
}


/**
 * 方法 6，使用unordered_set来，最后补一个set 和 unordered_set的知识点；
 * 它们之间的各种操作的时间开销的例子，set 红黑树实现，unordered_set
 * 是hash实现;在讨论里面，unordered_set的时间开销好像更少！
 * 思路和上面的都一样，利用一个数组放到哈希set中，然后第二个数组遍历查找，
 * 找到之后开始把第一个数组元素删除即可；
 * 这个是最好的方法！
*/
vector<int> intersection6(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int>res1(nums1.begin(), nums1.end());
    vector<int>res;
    for(auto i: nums2)
    {
        if(res1.count(i))
        {
            res.push_back(i);
            res1.erase(i);
        }
    }
    return res;
}


/**
 * 方法 7,使用的是STL自带的set_intersection函数来找出共同元素
*/
vector<int> intersection7(vector<int>& nums1, vector<int>& nums2) 
{
    set<int> s1(nums1.begin(), nums1.end());
    set<int> s2(nums2.begin(), nums2.end()), res;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
    return vector<int>(res.begin(), res.end());
}


int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    for (auto i : intersection6(nums1, nums2))
        cout << i << " ";
    return 0;
}
