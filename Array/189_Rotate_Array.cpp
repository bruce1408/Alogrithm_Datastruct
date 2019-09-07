#include <iostream>
#include <vector>
using namespace std;

/**
 * Given an array, rotate the array to the right by k steps, 
 * where k is non-negative.
 * 对于一个数组来说，把后k个数组提到前面
 * 
 * Example 1:
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * 
*/

// 不能利用辅助数组,还可以利用上面的思路。
// void insert(vector<int> &nums)
// {
//     int temp = nums[nums.size() - 1];
//     for (int i = nums.size() - 1; i >= 0; i--)
//     {
//         nums[i] = nums[i - 1];
//     }
//     nums[0] = temp;
// }

// void rotate(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     while (k)
//     {
//         insert(nums);
//         k--;
//     }
// }


/***
 * 方法 1超时了，思路很自然，就是循环k次，每一次循环就把数组最后一个数字提出来，然后数组集体向后
 * 移动一位，原来最后的数字放到第一个位置即可。但是超时了，所以还需要寻找其他方法。
*/
void rotate1(vector<int> &nums, int k)
{
    int len = nums.size();
    for (int i = 0; i < k; i++)
    {
        int temp = nums[len - 1];
        for (int j = len - 1; j > 0; j--)
        {
            nums[j] = nums[j - 1];
        }
        nums[0] = temp;
    }
}

/**
 * 方法 2新建一个数组，利用下标之间的映射关系来做i=(i+k)%数组的长度;空间复杂度O(n)
*/
void rotate2(vector<int> &nums, int k)
{
    int len = nums.size();
    vector<int> res = nums;
    for (int i = 0; i < len; i++)
    {
        nums[(i + k) % len] = res[i];
    }
}

/**
 * 方法 3先翻转前部分数组，然后翻转后部分数组，最后翻转整个数组;空间复杂度是O(1)：
*/
void rotate3(vector<int> &nums, int k)
{
    int len = nums.size();
    if (nums.empty() || (k %= len) == 0)
        return;
    vector<int> res = nums;
    reverse(nums.begin(), nums.begin() + len - k);
    reverse(nums.begin() + len - k, nums.end());
    reverse(nums.begin(), nums.end());
}


/**
 * 方法 4
*/
int main()
{
    vector<int> res = {1, 2, 3, 4, 5, 6, 7};
    rotate2(res, 3);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}