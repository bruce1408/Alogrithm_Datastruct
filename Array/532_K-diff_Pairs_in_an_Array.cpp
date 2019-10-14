#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

/**
 * Given an array of integers and an integer k, 
 * you need to find the number of unique k-diff pairs in the array.
 *  Here a k-diff pair is defined as an integer pair (i, j), 
 * where i and j are both numbers in the array and their absolute difference is k.
 * 
 * Example 1:
 * Input: [3, 1, 4, 1, 5], k = 2
 * Output: 2
 * 
 * 给定一个数组和一个数字k，然后求这个数组中两个数绝对值相减以后等于k的元素对，如果有重复的元素对
 * 就不考虑；例如[3,1,4,1,5]k = 2的话会两个1，3元素对，只保留一个即可；
*/

/**
 * 方法 1就是利用hash_map，hash_map保存的是每个元素出现的次数，遍历这个哈希map
 * 然后如果是k==0，
 * 那么所有出现次数大于1的都累加起来就是最后k-diff对，
 * 如果k>0，那么查找哈希表中的元素 + k是否存在，如果存在的话计数加1；
*/
int findPairs1(vector<int> &nums, int k)
{
    int count = 0;
    unordered_map<int, int> m;
    for (auto i : nums)
        ++m[i];
    for (auto a : m)
    {
        if (k == 0 && a.second > 1)
            ++count;
        if (k > 0 && m.count(a.first + k))
            ++count;
    }
    return count;
}

/**
 * 方法 2，不利用hash_map,先对原来的数组进行排序，然后利用二分查找来做，二分查找从下一个元素开始
 * 如果mid 的值等于当前数+k的话，那么还需要判断mid 的下标和当前数不相等，另外可能出现重复的元素
 * 那么就要筛掉这个数，利用一个变量beforeNum来做，如果之前出现的数和beforeNum不相等，那么就让
 * beforeNum等于这个数，且记录不同对的变量加1，left++；如果当前的mid数字大于当前数字+k的话，那么
 * right--，否则left++；
*/
int findPairs2(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int pairCount = 0;
    int beforeNum = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int left = i + 1, right = nums.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == nums[i] + k)
            {
                if (mid != i && beforeNum != nums[i])
                {
                    pairCount += 1;
                    beforeNum = nums[i];
                }
                left++;
            }
            else if (nums[mid] > nums[i] + k)
                right--;
            else
                left++;
        }
    }
    return pairCount;
}

/**
 * 方法 3，使用双指针，先排序，然后第一个指针指向第一个元素，
 * 工作指针查看哪个和它相减是小于k的
 * 没有使用哈希表，而是使用了双指针，需要给数组排序，节省了空间的同时牺牲了时间。
 * 我们遍历排序后的数组，然后在当前数字之后找第一个和当前数之差不小于k的数字，
 * 若这个数字和当前数字之差正好为k，那么结果res自增1，然后遍历后面的数字去掉重复数字
*/
int findPairs3(vector<int> a, int k)
{
    if (a.size() <= 1)
        return 0;
    sort(a.begin(), a.end());
    int start = 0;
    int end = 0;
    int res = 0;
    
    while (start < a.size() && end < a.size())
    {
        if (start == end || a[start] + k > a[end]) // 如果两个数字相加大于end的话说明end要向后取值
            end++;
        else if (a[start] + k < a[end]) // 否则 start 要想后取值
            start++;
        else //如果是相等了
        {
            res++; // 结果计数加1
            start++; // 然后start加1，去掉重复的情况！
            while (end < a.size() - 1 && a[end] == a[end + 1])
                end++;
            end++;
        }
    }
    return res;
}

int main()
{
    vector<int> res = {2, 3, 3, 5, 7};
    int k = findPairs3(res, 2);
    cout << k << endl;
    return 0;
}