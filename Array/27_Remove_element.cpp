#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * Given an array nums and a value val, 
 * remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, 
 * you must do this by modifying the input array in-place with O(1) extra memory.
 * The order of elements can be changed. 
 * It doesn't matter what you leave beyond the new length.
 * 
 * Example 1:
 * Given nums = [3,2,2,3], val = 3,
 * Your function should return length = 2, 
 * with the first two elements of nums being 2.
 * It doesn't matter what you leave beyond the returned length.
 * 题目描述，删除指定的元素，然后返回当前新的数组的长度
*/

/**
 * 方法 1，利用vector的erase的方法，最基本的算法
 * */
int removeElement(vector<int> &nums, int val)
{
    int len = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == val)
        {
            nums.erase(nums.begin() + i);
            i--;
            len--;
        }
    }
    return len;
}

/**
 * 方法 2，利用一个指针，然后每次不等于这个数的时候，那么就把后面的数字往前拷贝即可，最后
 * 返回的指针的数字res
*/
int removeElement2(vector<int> &nums, int val)
{
    int res = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != val)
            nums[res++] = nums[i];
    }
    return res;
}

int main()
{
    vector<int> nums = {3, 2, 2, 3};
    // vector<int> nums = {3,3};
    cout << removeElement2(nums, 3) << endl;
    return 0;
}