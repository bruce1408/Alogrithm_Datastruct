#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 多做几遍！好题
 * Given an integer array, you need to find one continuous subarray that 
 * if you only sort this subarray in ascending order, then the whole 
 * array will be sorted in ascending order, too.
 * You need to find the shortest such subarray and output its length.
 * Example 1:
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * 
 * 给定一个数组，然后找出最短的不是升序的子数组，这个子数组如果按照升序排序之后仍然
 * 原来的数组仍然是升序排列的数组。
*/

/**
 * 方法 1创建一个和原来一样的数组，然后排序，排序之后的新数组开始和
 * 原来的数组一一对比对应位置上的元素是否相同，如果是不同，记录开始和结束的位置，
 * 开始位置和结束位置都初始为-1，如果下次相同位置上的数字不同，那么结束标志一直更新即可，
 * 开始位置为第一次不同时候的标记位，最后把这个位置相减即可得到最小子数组的长度
 * O(n)时间 O(n)空间
*/
int findUnsortedSubarray1(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int length = 0;
    int start = -1, end = -1;
    vector<int> temp = nums;
    sort(temp.begin(), temp.end()); // 对这个辅助数组排序
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != temp[i]) // 对应的数组位置的数字不相同，那么记录位置。
        {
            if (start == -1)
                start = i; // 对应位置数字不同，那么更新相应位置上的数字，
            end = i;       // end只要不相同就更新
        }
    }
    if (start == end)
        length = 0;
    else
        length = end - start + 1;
    return length;
}

/**
 * 方法 2和上面的方法思路一样，新建一个和原来一样的数组，然后排序，设置两个指针，
 * 一个指向开头，一个指向结尾，如果指向开头的指针小于数组长度且和排序后的数组相应位置数字相同，
 * 那么后移，同样，指向结尾的指针如果它大于起始指针且对应数组数字相同，则自减1位向前移，
 * 最后尾指针减去头指针+1即可。
*/
int findUnsortedSubarray2(vector<int> &nums)
{
    vector<int> res = nums;
    vector<int> index;
    int n = nums.size();
    int beginIndex = 0, rearIndex = n - 1;

    sort(res.begin(), res.end());
    while (beginIndex < n && res[beginIndex] == nums[beginIndex])
    {
        beginIndex++;
    }
    while (rearIndex > beginIndex && res[rearIndex] == nums[rearIndex])
    {
        rearIndex--;
    }
    return rearIndex - beginIndex + 1;
}
/**
 * 这个方法写错了 不用创建新的数组，而是找到原来数组中的最大值和最小值，然后判断，
 * 如果当前的数字比
 * 最小值要大，退出此次循环，记录这个位置，在从后往前遍历，如果值比最大值还要小，那么说明也是
 * 位置不对，退出此次循环，记录这个位置，如果两个位置相同，返回0，否则返回位置的差值+1
*/
// int findUnsortedSubarray1(vector<int> &nums)
// {
//     int minNum = nums[0], maxNum = nums[0];
//     for (int i = 0; i < nums.size(); i++) // 找到最大值和最小值
//     {
//         if (nums[i] > maxNum)
//             maxNum = nums[i];
//         else if (nums[i] < minNum)
//             minNum = nums[i];
//     }

//     int left = 0, right = nums.size() - 1;
//     for (; left < nums.size(); left++)
//     {
//         if (nums[left] > minNum)
//             break;
//     }
//     for (; right >= 0; right--)
//     {
//         if (nums[right] < maxNum)
//             break;
//     }
//     cout << minNum << " " << maxNum << endl;
//     return right - left + 1 > 0 ? right - left + 1 : 0;
// }

/**
 * 方法 3很厉害，只用O(n)的时间复杂度，空间复杂度是O(1)
 * 主要思路就是如何找出在这个无序区间内的最小值和最大值！[2,6,4,8,10,9,15]中的无序区间是
 * [6,4,8,10,9]它的最小值是4，最大值是10，最小值是从第二个开始找，最大值是从倒数第二个找起。
 * 首先判断数组中的不按照升序的最大数和最小数，以[2,6,4,8,10,9,15]为例子，第一次不按照升序
 * 的最小数字是4，不按照升序的最大数字是10，找到之后，用两个指针，i和j，i从第一个开始，如果当前
 * 的数字比最小数4还要大，那么就说明这个数组是不按照升序的顺序，记录下来，退出循环，如果当前
 * 数字比这个数字小，那继续遍历；同样，指针j从后开始，如果当前数字比最大的数字还要大，那么正常，
 * 按照的是升序的，继续往前遍历，如果当前的数字比最大的数字要小，说明这个数不是升序排列的，记录位置
 * 最后j的位置减去i的位置+1即可。
 * 
*/
int findUnsortedSubarray3(vector<int> &nums)
{
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for (int i = 1; i < nums.size(); ++i)
        if (nums[i] < nums[i - 1]) // 当前位置比前面位置的数字还要小，可能是最小值
            minVal = min(nums[i], minVal);

    for (int i = nums.size() - 2; i >= 0; --i)
        if (nums[i] > nums[i + 1]) //当前位置数字比后面数字还要大，那么可能是最大值；这样的思路很容易写位置的初始化
            maxVal = max(nums[i], maxVal);

    int i = 0;
    for (; i < nums.size(); ++i) // 从第一个开始，知道当前数字大于最小值那么记录位置
        if (nums[i] > minVal)
            break;

    int j = nums.size() - 1;
    for (; j >= 0; --j)
        if (nums[j] < maxVal) // 从最后一个开始，如果当前数字比最大的数字还要小，那么记录位置
            break;
    cout << minVal << " " << maxVal << endl;
    cout << i << " " << j << endl;
    return i > j ? 0 : j - i + 1;
}

int main()
{
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    cout << findUnsortedSubarray3(nums) << endl;
    return 0;
}