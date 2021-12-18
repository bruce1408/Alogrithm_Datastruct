#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 27 给定一个数组和一个整数val，求删除这个val之后数组的长度
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
 * 方法 2，双指针算法
*/
int removeElement2(vector<int> &nums, int val)
{
    int k = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
            nums[k++] = nums[i];
    }
    return k;
}

int main()
{
    vector<int> nums = {5, 3, 1, 2, 2, 3};
    // vector<int> nums = {3,3};
    // cout << removeElement2(nums, 3) << endl;
    removeElement(nums, 5);
    for(auto x: nums)
    {
        cout<<x<<" ";
    }
    return 0;
}