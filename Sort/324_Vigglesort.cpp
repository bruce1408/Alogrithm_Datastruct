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
// #define A(i) res[(1 + 2 * i) % (n | 1)] 这个运算的结果是先奇数然后偶数排列 [1,3,5, 0,2,4,6]

void wiggleSort3(vector<int> &res)
{

    int n = res.size();
    #define A(i) res[(1 + 2 * i) % (n | 1)]

    auto midptr = res.begin() + n / 2;           // 找到原数组中间的这个数
    nth_element(res.begin(), midptr, res.end()); // 且区间中第n个元素，处理之后，排在第n个位置的数字他前面的都不比它大, 后面的都不比它小，不能保证有序
    int mid = *midptr;
    for (auto i : res)
        cout << i << " ";
    cout << endl;
    for (int i = 0, j = 0, k = n - 1; i <= k;)
    {
        // 先摆奇数的位置，然后再放偶数的位置
        if (A(i) > mid) // 相当于是奇数的位置大于mid，那么就说明后面的奇数往前面挪，较小位奇数位置填上这个的数
            swap(A(i++), A(j++));
        else if (A(i) < mid) // 否则，直接从最后面选择填补
            swap(A(i), A(k--));
        else
            i++;
    }
}

int main()
{
    vector<int> res = {1, 5, 1, 1, 6, 4};
    wiggleSort3(res);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
}
