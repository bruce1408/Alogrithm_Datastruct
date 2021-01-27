#include <iostream>
#include <vector>
using namespace std;

/**
 * 238 给定一个数组，然后输出除了当前这个数的所有数的乘积
 * given [1,2,3,4], return [24,12,8,6]
 * 时间复杂度O(n)，不能使用除法
 */

/**
 * 方法 1，前后缀分解
 * 由于最终的结果都是要乘到结果res中，所以我们可以不用单独的数组来保存乘积，
 * 而是直接累积到res中，我们先从前面遍历一遍，将乘积的累积存入res中，然后从后面开始遍历，
 * 用到一个临时变量right，初始化为1，然后每次不断累积，最终得到正确结果
*/
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> res(nums.size(), 1);
    int n = nums.size();
    // 先求解不包括这个数的前缀做法
    for (int i = 1; i < nums.size(); i++)
    {
        res[i] = res[i - 1] * nums[i - 1];
    }

    // 这个数的后缀做法
    int s = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        res[i] = res[i] * s;
        s = s * nums[i];
    }
    return res;
}

int main()
{
    vector<int> res = {1, 2, 3, 4};

    for (auto i : productExceptSelf(res))
    {
        cout << i << " ";
    }
}