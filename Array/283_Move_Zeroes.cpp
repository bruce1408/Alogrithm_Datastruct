#include <iostream>
#include <vector>
using namespace std;

/**
 * 283 如果数组含有0，那么就把0往后移动，保持原数组顺序不变
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the 
 * relative order of the non-zero elements.
 * Example:
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 这道题目意思是出现0的话,把0全部移动道数组的最后,不改变原来非0的元素的顺序.
*/

/**
 * 方法 1,使用双指针来做
 */
void moveZeroes1(vector<int> &nums)
{
    int k = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i])
        {
            nums[k++] = nums[i];
        }
    }
    while (k < nums.size())
    {
        nums[k++] = 0;
    }
}
/**
 * 方法 2,利用两个指针,然后其中一个指向的是非0的元素,如果存在0,那么第一个非0的元素和其交换位置即可,
 * 时间复杂度是O(n),空间复杂度是O(1)
*/
void moveZeroes2(vector<int> &nums)
{
    for (int i = 0, j = 0; i < nums.size(); i++)
    {
        if (nums[i])
        {
            swap(nums[i], nums[j++]);
        }
    }
}

int main()
{
    vector<int> res = {0, 1, 0, 3, 12};
    moveZeroes2(res);
    for (auto u : res)
    {
        cout << u << " ";
    }
}