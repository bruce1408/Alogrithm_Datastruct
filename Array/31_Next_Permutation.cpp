#include <iostream>
#include <vector>
using namespace std;
/**
 * 31 下一个排列，给定一个数组，然后输出它的另一个不同的排列
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
*/

/**
 * 方法 1，逻辑解法，使用[1，2，7，4，3，1]来作为例子，如果说这个数组是逆序的，那么直接返回初始状态，
 * 如果这个数组不是逆序的，那么从最后一位遍历，如果说后一位大于前一位，那么这个时候就要有如下的操作
 * 记录当前的这个前一位的位置，然后在开始从后往前遍历，找到第一个大于这个位置的数，比如2的数字，发现是3，
 * 那么就交换2和3的位置，就是 [1,3,7,4,2,1],然后开始从3后面所有的位置都翻转一遍即可
 * 最后的数组是[1,3,1,2,4,7]
*/
void nextPermutation1(vector<int> &nums)
{
    int i, j, n = nums.size();
    for (i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            for (j = n - 1; j > i; j--)
            {
                if (nums[j] > nums[i])
                    break;
            }
            swap(nums[j], nums[i]);
            reverse(nums.begin() + i + 1, nums.end());
            return;
        }
    }
    reverse(nums.begin(), nums.end());
}

/**
 * 方法 2，使用比上面更加简洁的写法
*/
void nextPermutation2(vector<int> &nums)
{
    int n = nums.size(), i = n - 2, j = n - 1;
    while (i >= 0 && nums[i] >= nums[i + 1])
        --i;
    if (i >= 0)
    {
        while (nums[j] <= nums[i])
            --j;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}

/**
 * 方法 3，找到第一个非降序的位置，推荐解法
 * 思路比较绕，就是给定一个数组，例如 2,3,5,4,1
 * 首先从后往前找到第一个前面数小于后面数的位置k，上面的例子是5的时候，前面的数字3小于后面数字5，所以k是2
 * 如果这个数字小于等于0，那么说明整个数组是逆序的，那么返回翻转的结果即可
 * 否则，就找出大于nums[k-1]的最小的数字即可，t自加，然后翻转nums[t-1] , nums[k-1];
 * 最后把k到数组末尾的元素进行翻转
*/
void nextPermutation3(vector<int> &nums)
{
    // 第一步找到第一个逆序的数字,从后往前找
    int k = nums.size() - 1, n = nums.size();
    while (k > 0 && nums[k - 1] >= nums[k]) // 如果前一个数大于等于后一个数，k--
        k--;
    if (k <= 0) // 说明整个数组逆序，翻转一下即可
        reverse(nums.begin(), nums.end());
    else
    {
        int t = k;
        while (t < n && nums[k - 1] > nums[t]) // 找到最小的大于nums[k-1]的数然后交换
            t++;
        swap(nums[k - 1], nums[t - 1]);
        // 对剩下的从k的位置的数字进行反转
        reverse(nums.begin() + k, nums.end());
    }
}

int main()
{
    vector<int> res = {2, 3, 5, 4, 1};
    nextPermutation3(res);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}