#include <iostream>
#include <vector>
using namespace std;

/**
 * 442 给定一个整数数组，然后其中有些元素的出现次数超过两次，找出所有出现两次的元素
 * 输入：
 * [4,3,2,7,8,2,3,1]
 * 输出
 * [2,3]
 * 要求不用额外的空间且时间复杂度是o(n)
*/

/**
 * 方法 1,重复出现的2次的数不能使用额外空间，如果是可以的话那么就好做了，直接记录出现的次数
 * 然后输出出现次数为2的数字即可，但是这里使用一种奇技淫巧
 * 比如数组是:
 * 输入:
 * [4,3,2,7,8,2,3,1]
 * for 循环开始遍历 每个数，因为数据是从1-n开始，所以减去1
 * nums[x-1] 这个数*-1，然后如果遇到大于0的情况，那么就是重复出现了
 * 输出:
 * [2,3]
*/
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        if (nums[abs(nums[i]) - 1] > 0)
            res.push_back(abs(nums[i]));
    }
    return res;
}

int main()
{
    vector<int> res = {1, 2, 3, 1, 3, 6, 6};
    vector<int> out = findDuplicates(res);
    for (auto i : out)
    {
        cout << i << " ";
    }
    return 0;
}