#include <iostream>
#include <vector>
using namespace std;

/**
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
 * 
 * 找出这个数组中缺少的数字
*/

/**
 * 方法 1，需要一个新的数组，新数组中每一元素装的是原来数组中数字出现的次数，
 * 然后遍历新数组，如果在下标位置次数是0，说明没有这个数字，那么这个数字+1放进temp数组即可
 * 空间复杂度是O(n)，时间复杂度是O(n),优点是不会改变原来的数组;
 * 
*/
vector<int> findDisappearedNumbers1(vector<int> &nums)
{
    vector<int> res(nums.size());
    vector<int> temp;
    for (int i = 0; i < nums.size(); i++)
    {
        res[nums[i] - 1]++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (res[i] == 0)
            temp.push_back(i + 1);
    }
    return temp;
}

/**
 * 方法 2，不需要使用多余的空间，而是对于每一个存在的数字，让其取它的相反数字，正数变成负数即可，
 * 负数就不用变了，然后开始遍历数组，如果是存在该数字大于0，那么就缺少这个数字，然后放入temp即可
 * 时间复杂度是O(n), 空间复杂度是常数级别的.这样的优点是
 * 缺点是改变了原来的数组;
 * 
*/
vector<int>findDisappearedNumbers2(vector<int> &res)
{
    vector<int>temp;
    for(int i=0;i<res.size();i++)
    {
        int idx = abs(res[i])-1; // 这一步只出现的是数组的下标的索引值;
        res[idx] = (res[idx]>0) ? -res[idx] : res[idx];
    }
    for(int i=0;i<res.size();i++)
    {
        if(res[i]>0)
        {
            temp.push_back(i+1);
        }
    }
    return temp;
}

int main()
{
    vector<int> res = {4, 3, 2, 7, 8, 3, 1};
    vector<int> out = findDisappearedNumbers2(res);
    for (auto i : out)
    {
        cout << i << " ";
    }
    return 0;


}