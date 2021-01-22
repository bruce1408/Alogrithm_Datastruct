#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * 324 摆动排序II
 * 给定一个数组，然后重新排列成为nums[0] < nums[1] > nums[2] < nums[3]
 * 输入
 * 1，5，1，1，6，4
 * 输出
 * 1,4,1,5,1,6
 * 只可以使用O(n)的时间复杂度和O(1)的空间复杂度 
*/

/**
 * 方法 1，先对原数组进行排序，然后不考虑题目要求的时间和空间复杂度
*/
void wiggleSort1(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> res;
    int l = nums.size() - 1, mid = (nums.size() + 1) / 2;
    int i = l, j = mid;
    while (i >= mid || j > 0)
    {

        if (j > 0) // 先从中间开始，不取中间的这个直到0为止
            res.push_back(nums[--j]);
        if (i >= mid) // 从最后一个数字开始，取到中间的mid数字为止
            res.push_back(nums[i--]);
    }
    nums = res;
}

/**
 * 方法 2，还是使用上面的思路，但是写法简单，不过不满足题目要求
*/
void wiggleSort2(vector<int> &nums)
{
    vector<int> tmp = nums;
    int n = nums.size(), mid = (n + 1) / 2, j = n;
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; ++i)
    {
        // 当前的i是奇数还是偶数，如果是偶数从中间开始，否则从最后一个开始
        nums[i] = i & 1 ? tmp[--j] : tmp[--mid];
    }
}

/**
 * 方法 3，按照题目的时间空间要求来做；
 * 最好的是O(n)的时间和O(logn)的空间
 * 1、找中位数，快速选择算法 可以在O(n)时间选择第k个数字
 * 2、所有数字分成3大类，
 *  第1类是大于中位数的数 2
 *  第2类是等于中位数的数 1
 *  第3类是小于中位数的数 0
*/
void wiggleSort3(vector<int> &nums)
{


}

int main()
{
    vector<int> res = {1, 5, 1, 1, 6, 4};
    wiggleSort1(res);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}