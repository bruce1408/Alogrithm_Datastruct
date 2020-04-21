#include <iostream>
#include <vector>
using namespace std;

/**
 * Example 1:
 * 
 * Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
 * Output: 2
 * 
 * Explanation: 
 * For arr1[0]=4 we have: 
 * |4-10|=6 > d=2 
 * |4-9|=5 > d=2 
 * |4-1|=3 > d=2 
 * |4-8|=4 > d=2 
 * 
 * For arr1[1]=5 we have: 
 * |5-10|=5 > d=2 
 * |5-9|=4 > d=2 
 * |5-1|=4 > d=2 
 * |5-8|=3 > d=2
 * 
 * For arr1[2]=8 we have:
 * |8-10|=2 <= d=2
 * |8-9|=1 <= d=2
 * |8-1|=7 > d=2
 * |8-8|=0 <= d=2
 * 
 * 数组1中的所有数字和数组2中的数字进行绝对值的差，只要所有值都大于d的话，那么就统计进去。
*/

/**
 * 方法 1，暴力解法，时间复杂度是O(n*m)
*/
int findTheDistanceValue1(vector<int> &arr1, vector<int> &arr2, int d)
{
    int sum = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < arr2.size(); j++)
        {
            if (abs(arr1[i] - arr2[j]) > d)
            {
                count += 1;
            }
            else
            {
                break;
            }
        }
        if (count == arr2.size())
        {
            sum += 1;
        }
    }
    return sum;
}

/**
 * 方法 2,双指针法来做；思路有点惊奇，不过时间复杂度降低了，是mlogm + nlogn + m + n
*/
int findTheDistanceValue2(vector<int> &arr1, vector<int> &arr2, int d)
{
    sort(begin(arr1), end(arr1));     // 正序排序
    sort(arr2.rbegin(), arr2.rend()); // 逆序排序
    int ans = 0;
    for (int a : arr1)
    {
        while (arr2.size() && (a - arr2.back()) > d)
            arr2.pop_back();
        ans += arr2.empty() || arr2.back() - a > d;
    }
    return ans;
}

/**
 * 方法 3，使用二分搜索来做,这种思路很惊奇，是利用规律来查找第二个数组中第一个大于或者是等于这个 a-d的迭代器
 * 或者是第一个大于这个a+d的迭代器，如果两个相同，那么就加1；
 * 时间复杂度是O(n)
*/
int findTheDistanceValue3(vector<int> &arr1, vector<int> &arr2, int d)
{
    sort(begin(arr2), end(arr2));
    int ans = 0;
    for (int a : arr1)
    {
        auto it1 = lower_bound(begin(arr2), end(arr2), a - d); // 第一个 大于或者等于 a-d 的迭代器
        auto it2 = upper_bound(begin(arr2), end(arr2), a + d); // 第一个 大于 a+d 的迭代器
        cout << "ite1 is: " << it1 - arr2.begin() << endl;
        cout << "ite2 is: " << it2 - arr2.begin() << endl;

        if (it1 == it2)
            ++ans;
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    cout << findTheDistanceValue3(arr1, arr2, 2) << endl;
}
