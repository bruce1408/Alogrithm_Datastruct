#include <iostream>
#include <vector>
using namespace std;

/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty.
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 * 
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
 * 
 * 对两个已经排好序的数组求他们的联合中位数，如果是奇数，直接求中间的数，否则求中间两位的平均数
*/

/**
 * 第一种方法：直接合并然后讨论。但是时间复杂度是O(n+m)
 * */
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int len1 = nums1.size();
    int len2 = nums2.size();
    vector<int> res;
    if (nums1.size() == 0 && nums2.size() == 0)
        return 0;
    else if (nums1.size() == 0 && nums2.size() != 0)
    {
        return (nums2.size() % 2 == 1 ? (double)nums2[len2 / 2] : (double)(nums2[len2 / 2] + nums2[len2 / 2 - 1]) / 2);
    }
    else if (nums1.size() != 0 && nums2.size() == 0)
    {
        return (nums1.size() % 2 == 1 ? (double)nums1[len1 / 2] : (double)(nums1[len1 / 2] + nums1[len1 / 2 - 1]) / 2);
    }
    else
    {
        int i = 0, j = 0;
        while (i < len1 && j < len2)
        {
            if (nums1[i] < nums2[j])
            {
                res.push_back(nums1[i++]);
            }
            else
            {
                res.push_back(nums2[j++]);
            }
        }
        while (i < len1)
        {
            res.push_back(nums1[i++]);
        }
        while (j < len2)
        {
            res.push_back(nums2[j++]);
        }
    }
    int len = res.size();
    return (len % 2 == 1 ? (double)res[len / 2] : (double)(res[len / 2] + res[len / 2 - 1]) / 2);
}

/**
 * 第二种方法，利用的是二分查找，这样你的时间复杂度才可能是O(log(n+m))
 * */
double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2)
{
    int len1 = nums1.size();
    int len2 = nums2.size();
    if (len1 > len2)
        return findMedianSortedArrays2(nums2, nums1);
    int cut1 = 0;
    int cut2 = 0;
    int cutL = 0, cutR = len1;
    int len = len1 + len2;
    while (cut1 <= len1)
    {
        cut1 = (cutR - cutL) / 2 + cutL;
        cut2 = len / 2 - cut1;
        double L1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        double L2 = (cut1 == 0) ? INT_MIN : nums2[cut2 - 1];
        double R1 = (cut1 == len1) ? INT_MAX : nums1[cut1];
        double R2 = (cut2 == len2) ? INT_MAX : nums2[cut2];
        // 关键步骤
        if (L1 > R2)
        {
            cutR = cut1 - 1;
        }                 // 如果是不满足，那么左切口向左移动一位
        else if (L2 > R1) //  第二个数组的左边大于右边的话，那么肯定是第一个切口要向右边移动；
        {
            cutL = cut1 + 1;
        }
        else // 满足条件L1<R2,L2<R1
        {
            return (len / 2 == 0) ? (max(L1, L2) + min(R1, R2)) / 2 : min(R1, R2);
        }
    }
    return 0;
}

// 有点问题
double findMedianSortArrys3(vector<int> &num1, vector<int> &num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 > len2)
        return findMedianSortArrys3(num2, num1);
    int low = 0;
    int high = len1;
    while (low <= high)
    {
        int partitionx = (low + high) / 2;
        int partitiony = (len1 + len2 + 1) / 2 - partitionx;

        int maxLeftx = (partitionx == 0) ? INT_MIN : num1[partitionx - 1];
        int minrightx = (partitionx == len1) ? INT_MAX : num1[partitionx];

        int maxLefty = (partitiony == 0) ? INT_MIN : num1[partitiony - 1];
        int minrighty = (partitiony == len2) ? INT_MAX : num1[partitiony];

        if (maxLeftx <= minrighty && maxLefty <= minrightx)
        {
            if ((len1 + len2) % 2 == 0)
                return (max(maxLeftx, maxLefty) + max(minrightx, minrighty)) / 2;
            else
                return max(maxLeftx, maxLefty);
        }
        else if (maxLeftx > minrighty)
            high = partitionx - 1;
        else
            low = partitionx + 1;
    }
}

/**
 * 方法 4， 合并两个数组，按照降序从大到小放到新数组temp中去，然后判断这个temp的size是多少，如果是
 * 偶数，那么直接返回的是中间两位的平均值，如果是奇数，那么直接返回中间这个数即可
*/
double findMedianSortedArrays4(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> temp;
    while (!nums1.empty() && !nums2.empty())
    {
        if (nums1.back() > nums2.back())
        {
            temp.push_back(nums1.back());
            nums1.pop_back();
        }
        else
        {
            temp.push_back(nums2.back());
            nums2.pop_back();
        }
    }
    while (!nums1.empty())
    {
        temp.push_back(nums1.back());
        nums1.pop_back();
    }
    while (!nums2.empty())
    {
        temp.push_back(nums2.back());
        nums2.pop_back();
    }
    int n = temp.size();
    return (n % 2 == 0) ? (temp[n / 2 - 1] + temp[n / 2]) / 2.0 : temp[n / 2];
}

/**
 * 方法 5，逐个对比两个数组，
*/
double findMedianSortedArrays5(vector<int> &nums1, vector<int> &nums2)
{
    int len1 = nums1.size(), len2 = nums2.size(), totallength = len1 + len2;
    int point1 = 0, point2 = 0, compare_times = totallength / 2 + 1, medianum = 0, beforemedia = 0;
    while (compare_times > 0)
    {
        if (point1 < len1 && point2 < len2)  // 1和2数组都在范围内
        {
            if (nums1[point1] < nums2[point2])
            {
                int temp = medianum;
                beforemedia = temp;
                medianum = nums1[point1];
                point1++;
            }
            else
            {
                int temp = medianum;
                beforemedia = temp;
                medianum = nums2[point2];
                point2++;
            }
        }
        else if (point1 < len1)
        {
            int temp = medianum;
            beforemedia = temp;
            medianum = nums1[point1];
            point1++;
        }
        else if (point2 < len2)
        {
            int temp = medianum;
            beforemedia = temp;
            medianum = nums2[point2];
            point2++;
        }
        compare_times--;
    }
    cout << "the medianum is: " << medianum << endl;
    if (totallength % 2)
    {
        return medianum;
    }
    else
    {
        return (beforemedia + medianum) / 2.0;
    }
}

int main()
{
    vector<int> a = {3, 4};
    vector<int> b = {1, 2};
    cout << findMedianSortedArrays5(a, b) << endl;
    return 0;
}