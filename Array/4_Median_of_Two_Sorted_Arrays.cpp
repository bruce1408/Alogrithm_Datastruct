#include <iostream>
#include <vector>
using namespace std;

/**
 * 4 寻找两个正序数组的中位数
 * 给定两个数组，然后找到这两个数组的中位数即可
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 示例 2：
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
*/

/**
 * 方法 1, 直接合并然后讨论。但是时间复杂度是O(n+m),空间复杂度是O(n+m)，不推荐
*/
double findMedianSortedArrays1(vecetor<int> &a, vector<int> &b)
{
    int i = 0, j = 0;
    vector<double> res;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
            res.push_back(a[i++]);
        else
            res.push_back(b[j++]);
    }
    while (i < a.size())
        res.push_back(a[i++]);
    while (j < b.size())
        res.push_back(b[j++]);
    int n = res.size();
    // 如果是奇数直接返回中间的数字，否则返回中间两个数和的平均值
    return n & 1 ? res[n / 2] : (res[n / 2] + res[n / 2 - 1]) / 2;
}

/**
 * 方法 2，利用的是二分查找，这样你的时间复杂度才可能是O(log(min(n,m)))
 * ubuntu 里面的INT_MAX 要改成 INT64_MIN 才可以
 * */

double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2)
{
    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2)
        return findMedianSortedArrays(nums2, nums1);

    int lo = 0, hi = N2 * 2;
    while (lo <= hi)
    {
        int mid2 = (lo + hi) / 2;
        int mid1 = N1 + N2 - mid2;

        double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
        double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1) / 2];
        double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2) / 2];

        if (L1 > R2)
            lo = mid2 + 1;
        else if (L2 > R1)
            hi = mid2 - 1;
        else
            return (max(L1, L2) + min(R1, R2)) / 2;
    }
    return -1;
}

/**
 * 方法 3，使用递归来解决，时间复杂度是log(n)的也可，比二分的边界条件少很多，而且很好理解
 * 然后每次查找数组中的k/2个数
*/
double findNum(vector<int> &a, int i, vector<int> &b, int j, int k)
{
    // 这里数组从下标i和j开始,开始处理边界问题
    // 假设a数组长度要小于b数组的长度
    if (a.size() - i > b.size() - j)
        return findNum(b, j, a, i, k);

    // 数组a空了，那么返回b数组的k个数字即可，k 下标从1开始，所以这里减去1
    if (a.size() == i)
        return b[j + k - 1];

    // 如果k==1，那么返回a数组和b数组中的第一个较小的值即可
    if (k == 1)
        return min(a[i], b[j]);

    // 找到数组a和b的k/2下标，因为a数组长度可能小于k/2，找它长度和k/2最小值，这里返回的是size_type类型，强转为int，
    int s1 = min(i + k / 2, (int)a.size()), s2 = j + k / 2;

    // 如果a[k/2] < b[k/2], 小于a[k/2]的个数一定小于k， 那么显然，a的k/2前部分去掉，然后调整新的k值
    if (a[s1 - 1] < b[s2 - 1]) // 下标从1开始，减去1
    {
        return findNum(a, s1, b, j, k - (s1 - i)); // k减去前面k/2个数，是(s1 - i)
    }
    else
    {
        return findNum(a, i, b, s2, k - (s2 - j));
    }
}

double findMedianSortedArrays3(vector<int> &a, vector<int> &b)
{
    int len = a.size() + b.size();
    if (len % 2 == 0)
    {
        int left = findNum(a, 0, b, 0, len / 2); // 这里的k其实从1开始，不是从0开始的下标
        int right = findNum(a, 0, b, 0, len / 2 + 1);
        return (left + right) / 2.0;
    }
    else
    {
        return findNum(a, 0, b, 0, len / 2 + 1); // 下标依然从1开始，所以要加1
    }
}

int main()
{
    vector<int> a = {1, 3};
    vector<int> b = {2};
    cout << findMedianSortedArrays3(a, b) << endl;
    return 0;
}