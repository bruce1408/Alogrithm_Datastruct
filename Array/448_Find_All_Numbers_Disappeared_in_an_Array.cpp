#include <iostream>
#include <vector>
using namespace std;

/**
 * 448 求一个数组里面缺失的数字
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), 
 * some elements appear twice and others appear once.
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * Could you do it without extra space and in O(n) runtime? 
 * You may assume the returned list does not count as extra space.
 * 
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 * Output:
 * [5,6]
 * 找出这个数组中缺少的数字
 * */

/**
 * 方法 1，不需要使用多余的空间，而是对于每一个存在的数字，让其取它的相反数字，正数变成负数即可，
 * 负数就不用变了，然后开始遍历数组，如果是存在该数字大于0，那么就缺少这个数字，然后放入temp即可
 * 时间复杂度是O(n), 空间复杂度是常数级别的.这样的优点是
 * 缺点是改变了原来的数组;
 * 
*/
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[abs(nums[i]) - 1] > 0) // 如果这个数字是大于0的话，那么说明没有标记，则进行标记为*-1
            nums[abs(nums[i]) - 1] = nums[abs(nums[i]) - 1] * -1, cout << nums[abs(nums[i]) - 1] << endl;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            res.push_back(i + 1);
    }
    return res;
}

int main()
{
    vector<int> res = {4, 3, 2, 7, 8, 3, 1};
    vector<int> out = findDisappearedNumbers(res);
    for (auto i : out)
    {
        cout << i << " ";
    }
    return 0;
}