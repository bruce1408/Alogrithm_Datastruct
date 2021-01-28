#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

/**
 * 162 找出数组中的峰值，左边和右边的数都小于它
 * A peak element is an element that is greater than its neighbors.
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 * You may imagine that nums[-1] = nums[n] = -∞.
 * 
 * Input: nums = [1,2,3,1]
 * Output: 2
 * 
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5 
 * 找出数组的局部最大值，局部最大，不要求是全局最大。所以
 * 考虑比周围两个数字都大的数字，只需要和周围两个数字比较即可，和左右比较的话，
*/

/**
 * 方法 1，利用两个标记值，在数组的开头插入最小的数min，在最后插入最大的数
 * max，如果这里用遍历整个数组找最大值肯定会出现Time Limit Exceeded，
 * 但题目中说了这个峰值可以是局部的最大值，所以我们只需要找到第一个局部峰值就可以了。
 * 所谓峰值就是比周围两个数字都大的数字，那么只需要跟周围两个数字比较就可以了。既然要跟左右的数字比较，
 * 就得考虑越界的问题，题目中给了nums[-1] = nums[n] = -∞，那么我们其实可以把这两个整型最小值直接加入到数组中，
 * 然后从第二个数字遍历到倒数第二个数字，这样就不会存在越界的可能了。由于题目中说了峰值一定存在，
 * 那么有一个很重要的corner case我们要注意，就是当原数组中只有一个数字，
 * 且是整型最小值的时候，我们如果还要首尾垫数字，就会形成一条水平线，从而没有峰值了，
 * 所以我们对于数组中只有一个数字的情况在开头直接判断一下即可
 * 时间是O(n)的，不满足条件
*/
int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;
    nums.insert(nums.begin(), INT_MIN); // 开头插最小
    nums.push_back(INT_MAX);            // 最后插最大
    for (int i = 1; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) // 每一个i都大于它的前后两个数字即可；
            return i - 1;                                   // 大于前一个数字，和后一个数字
    }
    return -1;
}

/**
 * 方法 2，对方法 1的改进，
 * 判断前一个数字只要大于当前数，那么这个数字的前一个数字就是局部最大数返回前一个数的下标索引即可
 * 否则，最后返回数组最后一个数字的下标索引；
 */
int findPeakElement1(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] < nums[i - 1])
            return i - 1;
    }
    return nums.size() - 1;
}

/**
 * 方法 3，使用二分查找来做，这个题目要求找到峰值，那么只要是当前点的前一个和后一个数都小于它，那么就是峰值，输出即可，或者是左、右边界。
 * 首先一定有峰值，可证明，从左端点开始，前一个数默认是负无穷，然后第一个数大于它，只要第二个数是小于第一个数字，那么第一个就是峰值，否则数组
 * 一直上升到最右端点，最右端点的前一个点小于它，右侧默认是负无穷，所以峰值是右端点，即肯定存在峰值。
 * 这道题目使用二分来做，判断 mid 和 mid+1 之间的大小，如果mid >  mid+1,说明mid这个点右侧小于mid数，只要左侧也有一个数字小于mid数字即可
 * 这里分情况：
 * 如果mid左侧从的数字也小于mid，那么说明mid就是峰值，可以立即返回，但是mid左侧的数字大于mid，
 * 那么左侧一直大于mid，到最左端点出，出现峰值，所以峰值位置在左区间，那么r = mid
 * 同理，则 l = mid+1；
 * 最后返回l或r即可
*/
int findPeakElement2(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (nums[mid] > nums[mid + 1])
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    vector<int> nums = {1, 3, 2, 1};
    int k = findPeakElement(nums);
    cout << k << endl;
    return 0;
}