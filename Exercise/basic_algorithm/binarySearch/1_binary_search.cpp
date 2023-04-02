#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 二分查找写法 1
 * 二分查找：左闭右闭区间，推荐模板
 * 时间复杂度是O(lgn)，比O(n)要好，但是有多种情况需要考虑清楚：
 * Although the basic idea of binary search is comparatively straightforward, the details can be surprisingly tricky... 
 * 这句话可以这样理解：思路很简单，细节是魔鬼。
 * 
 * 不断的比较和要找的数字的大小，然后选择区间范围内继续查找，下面是最基本的二分查找算法，
 * 方法 1，使用的其实就是左闭右闭区间，right是数组res.size()-1;
 * 可以取到最后一位的数字，所以这里用小于等于号来做；
*/
int binarySearch(vector<int> &res, int k)
{
    int left = 0, right = res.size() - 1; // right 可以取到数组的最后一位数组
    while (left <= right)                 // 所以这里用的是小于等于号；
    {
        int mid = (left + right) / 2;
        if (res[mid] > k)
            right = mid - 1;
        else if (res[mid] < k)
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}

/**
 * 二分查找写法 2
 * 二分查找，左闭右开区间，
 * right取不到数组的最后一个元素；
 * 最后的right要取到mid，因为right本来是右开区间，循环结束的条件就是left==right，所以
 * 一旦找到这个数字，那么就right赋值为mid，和left相等，循环结束，返回left或者right都可以；
 * 如果return left，那么可能的范围是[0, 数组长度]，例如数组[1,2,2,3,4]，
 * 如果k=2，返回的数字就是1，说明比2小的数字只有1个，
 * 如果k是5，返回的是5，说明比5小的数字是5，
 * 如果k是1，返回的是0，说明比1小的数字是0，整个函数返回的范围在0到数组长度之间；
 * 所以这个时候加上一句，是不是res[left]==k ? left : -1;
 * 如果最后left这个数是k，返回left下标索引，否则，返回-1，表示没有找到；
*/
int binarySearch1(vector<int> &res, int k)
{
    int left = 0, right = res.size();
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (res[mid] > k)
        {
            right = mid;
        }
        else if (res[mid] < k)
        {
            left = mid + 1;
        }
        else
        {
            return mid; // 收紧右侧边界来确定条件是否可以终止；
        }
    }
    /**
     * 1.return left；
     * 这个就是找到了，返回下标；找不到，返回数组长度
     * */

    /**
     * 2.return res[left]==k ? left : -1;
     * 这种返回方式是如果当前下标指向的数字是目标值，返回下标值
     * 否则返回的是-1；
     * 这种方式最好不要写，会有错误，因为left有可能是数组长度n，这个
     * 时候数组的下标会越界
     * */

    return -1;
}

/**
 * low_bound 写法 1
 * lower_bound 查找；left<=right 
 * 找到大于等于这个数的最小下标(首个下标)，在STL中如果有函数lower_bound
 * 如果要找的数字大数组中的所有数字，那么就返回最后一个元素的下标即可；
 * 注意是 大于等于某个数字 的最小下标，lower_bound
*/
int lower_bound0(vector<int> &res, int k)
{
    int left = 0, right = res.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (res[mid] >= k)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left; // 这个是标准的lower_bound输出，不存在的数且大于所有元素，返回最大下标，
    // left 是左侧边界；
    // return left <= n ? left : -1; // 不存在的数字返回-1；提醒找不到,下面这种写法也是可以的；
}

// yxc推荐写法
int low_bound3(vector<int> &res, int target)
{
    int l = 0, r = res.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (res[mid] >= target)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int upper_bound(vector<int> &res, int k)
{
    int left = 0, right = res.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (res[mid] <= k)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

/**
 * low_bound 写法 2
 * lower_bound 查找 left < right
*/
int lower_bound1(vector<int> &nums, int target)
{
    int left = 0, right = nums.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return right; // 结束条件是left==right，所以left和right都可以
}

/**
 * low_bound 写法 3
 * lower_bound 查找 left < right 
 * 这里返回值需要注意的就是根据STL的标准写法，
 * 如果这个数字不在这个数组中，且大于数组的所有元素，返回的应该是最后的元素的下标，
 * 而某些时候，我们需要的返回-1，告诉我们元素不存在，
 * 这样返回值那一部分需要简单的修改一下才可以
*/
int lower_bound2(vector<int> &res, int k)
{
    int left = 0, n = res.size(), right = n;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (res[mid] < k)
            left = mid + 1;
        else
            right = mid;
    }
    return left; // standord lower_bound 标准写法
    //// return res[left] >= k ? left : -1; 会越界，不能这么写！！
    // return left < n ? left : -1;
}


/** {1, 2, 2, 2, 3, 5, 7};
 * 查找第一个大于某个数的下标；也是stl里面 upper_bound的实现
 * 和 lower_bound 的区别是 upper_bound 是小于等于号，
 * 因为这里判断的是第一个大于这个数的位置下标，这里和下面的upper_bound_include主要是它取不到mid，如果相同的话，那么
 * 就跳过mid这个值，195行，left ！= mid, 而是left = mid+1取的是大于它的第一个元素的值。
*/
int upper_bound(vector<int> &res, int k)
{
    int left = 0, right = res.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (res[mid] <= k)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

/**
 * 使用二分来查找数组中最后一个大于等于该数字的位置, 使用yxc的模板来做, 包含等于该数字
 * 这个不是upper_bound是因为l = mid,如果相同的话就可以等于这个值，输出
*/
int upper_bound_include(vector<int> &res, int target)
{
    int l = 0, r = res.size() - 1;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (res[mid] <= target)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    int k = 3;
    while (k)
    {
        // cout << "input a number: " << endl;
        // vector<int> res = {1, 2, 2, 2, 3, 5, 7};
        // cout << binarySearch(res, k) << endl;
        // break;
        // vector<int>::iterator lowerLocation = lower_bound(res.begin(), res.end(), k);
        // vector<int>::iterator upperLocation = upper_bound(res.begin(), res.end(), k, greater<int>());
        // vector<int>::iterator upperLocation = upper_bound(res.begin(), res.end(), 1);
        // cout << "the lower_bound self write is: " << lower_bound0(res, k) << " " << lower_bound1(res, k) << " "
        //      << lower_bound2(res, k) << endl;
        // cout << "the office lower_bound is: " << lowerLocation - res.begin() << endl;
        // cout << "the upper_bound is by muself is:" << upper_bound0(res, k) << endl;
        // cout << "the office upper_bound is: " << upperLocation - res.begin() << endl;
        // cout << "the lower_bound_1 is:" << find(res, k) << endl;

        /**
         * lower_bound 和 upper_bound 的用法介绍。
         * 如果原数组是从小到大排序的，
         * 那么lower_bound是返回第一个大于或者等于目标数的位置
         * upper_bound是返回第一个大于目标数的位置
         * 
         * 如果原数组是从大到小排序的，
         * 那么lower_bound是返回第一个小于或者等于目标数的位置
         * upper_bound是返回第一个小于目标数的位置
        */
        // 逆序排列
        // vector<int> res1 = {4, 3, 2, -1, -2, -3};
        // vector<int>::iterator lowerLocation = lower_bound(res1.begin(), res1.end(), k, greater<int>());
        // vector<int>::iterator upperLocation = upper_bound(res1.begin(), res1.end(), k, greater<int>());
        // cout << k << endl;
        // cout << "the office lower_bound is: " << lowerLocation - res1.begin() << endl;
        // cout << "the office upper_bound is: " << upperLocation - res1.begin() << endl;

        // 升序排列
        vector<int> res2 = {-3, -2, -1, 2, 3, 4};
        vector<int>::iterator lowerLocation = lower_bound(res2.begin(), res2.end(), k);
        vector<int>::iterator upperLocation = upper_bound(res2.begin(), res2.end(), k);
        cout << k << endl;
        cout << "the office lower_bound is: " << lowerLocation - res2.begin() << endl;
        cout << "the office upper_bound is: " << upperLocation - res2.begin() << endl;
        k--;
    }
}