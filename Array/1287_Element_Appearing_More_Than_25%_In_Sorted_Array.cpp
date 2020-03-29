#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/**
 * Given an integer array sorted in non-decreasing order, 
 * there is exactly one integer in the array that occurs more than 25% of the time.
 * Return that integer.
 * 
 * Input: arr = [1,2,2,6,6,6,6,7,10]
 * Output: 6
*/

/**
 * 方法 1，利用的是一次遍历，时间复杂度是n，但是既然是排序的话，应该能想到的是二分查找来做
*/
int findSpecialInteger1(vector<int> &arr)
{
    int n = arr.size(), m = ceil(n * 0.25), count = 0, curr = 0;
    while (curr < n - 1)
    {
        if (arr[curr] == arr[curr + 1])
        {
            count += 1;
        }
        else
        {
            count = 0;
        }
        if (count >= m)
        {
            return arr[curr];
        }
        curr += 1;
    }
    return arr[0];
}

/**
 * 方法 2，还是利用O(n)时间复杂度的方法来做，非常简单
 * 因为只要是遍历这个数组，发现a[i] == a[len/4 + i]
 * 那么就找到了这个数字，比我上面的写法要简单的多的多
*/
int findSpecialInteger2(vector<int> &arr)
{
    int n = arr.size() / 4;
    for (int i = 0; i < n + i; i++)
    {
        if (arr[i] == arr[i + n])
        {
            return arr[i];
        }
    }
    return -1;
}

/**
 * 方法 3，因为排序了，所以使用二分查找的思路来做
 * 推荐方法 2 和 方法 3来做；
 * 
*/
int findSpecialInteger3(vector<int> &arr)
{
    const int n = arr.size() / 4;
    for (int i = 0; i < 4; i++)
    {
        const int dis = i * n;
        auto iter = equal_range(arr.begin(), arr.end(), arr[dis]);
        if (distance(iter.first, iter.second) > n)
        {
            return arr[dis];
        }
    }
    return -1;
}

/**
 * 方法 4， 和方法 3写法不同而已，其他都一样；
*/
int findSpecialInteger4(vector<int> &arr)
{
    int m(arr.size() >> 1), q(m >> 1);
    auto pos = equal_range(begin(arr), begin(arr) + m, arr[q]);
    if (distance(pos.first, pos.second) > q)
    {
        return *pos.first;
    }
    pos = equal_range(begin(arr) + m, end(arr), arr[m + q]);
    if (distance(pos.first, pos.second) > q)
    {
        return *pos.first;
    }
    return arr[m];
}
int main()
{
    vector<int> res = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    cout << findSpecialInteger4(res) << endl;
}