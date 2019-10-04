#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

/**
 * Given an integer array, return the k-th smallest 
 * distance among all the pairs. 
 * The distance of a pair (A, B) is defined as the 
 * absolute difference between A and B.
 * 
 * Input:
 * nums = [1,3,1]
 * k = 1
 * Output: 0 
 * 
 * Here are all the pairs:
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * Then the 1st smallest distance pair is (1,1), and its distance is 0.
 * 
 * 数组，找到数组两两元素绝对值的差，找到第k个元素对的差，例如[1,3,1],两两元素的差是0，2，2
 * k =1，就是第一个元素的差就是0，返回0；
 */

/**
 * 方法 1，方法 1利用的就是两两遍历，然后把元素的差的结果保存在新建数组res中，
 * res下标元素就是元素之间的差的绝对值，而对应的值就是差出现的次数；
 * 下次遍历res的时候，只要发现当前差出现的次数大于等于k，那么返回i下标，
 * 否则k要减去当前的次数！
*/
int smallestDistancePair(vector<int> &nums, int k)
{
    vector<int> res(10000, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        for(int j = i+1; j<nums.size();j++)
        {
            res[abs(nums[j] - nums[i])]++;
        }
    }
    /**
     * 这里已经把元素的差装在res数组中，下标就是元素的差的绝对值，然后值对应的是
     * 就是差的元素出现的次数；如果当前重复的次数大于等于k，那么直接输出这个i，否则
     * k减去这个次数
    */
    for (int i = 0; i < res.size(); i++) 
    {
        if (res[i] >= k)
            return i;
        k -= res[i];
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 6, 1};
    cout << smallestDistancePair(nums, 3) << endl;

    return 0;
}