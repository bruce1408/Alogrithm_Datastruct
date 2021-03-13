#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * 169 给定一个数组，然后找出这个数组出现次数大于n/2的元素，限定O(N)时间和O(1)的空间
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * Example 1:
 * 
 * Input: [3,2,3]
 * Output: 3
 * Example 2:
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 目的就是求出一个数组中出现最多大于(n/2)的数字,
*/

/**
 * 方法 1，这是对于第一个版本哈希表的优化，时间复杂度是O(n)
 * */
int majorityElement1(vector<int> &nums)
{
    int countNum = 0;
    int majortiyNum = 0;
    unordered_map<int, int> temp;
    for (auto i : nums)
    {
        ++temp[i];
        if (temp[i] > countNum)
        {
            countNum = temp[i];
            majortiyNum = i;
        }
    }
    return majortiyNum;
}

/**
 * 方法 2，投票法，出现最多的那个数，设置两个变量，一个是记录数字出现的次数c初始化为0，
 * 还有一个是r表示当前的数，遍历整个数组，如果当前的数字和r相等，那么c+1，否则不相等就减一
 * 如果c减到最后为0，那么把当前的数字更新为r，同时c记录为1
 * 如果说一个数字出现的次数大于整个长度的一半，那么不同的数字即使每次消耗c，即c-1，那么也无法完全消耗，所以可以记录那个
 * 最多次数的c
 * */
int majorityElement2(vector<int> &nums)
{
    int value, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt == 0) value = nums[i], cnt = 1;
        else if (nums[i] == value) cnt++;
        else if (nums[i] != value) cnt--;
    }
    return value;
}

int main()
{
    vector<int> res = {2, 3, 3};
    cout << majorityElement2(res) << endl;
}