#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 二分查找：时间复杂度是O(lgn)，比O(n)要好，但是有多种情况需要考虑清楚：
 * Although the basic idea of binary search is comparatively straightforward,
 * the details can be surprisingly tricky... 
 * 这句话可以这样理解：思路很简单，细节是魔鬼。
 * 
 * 不断的比较和要找的数字的大小，然后选择区间
 * 范围内继续查找，下面是最基本的二分查找算法，
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
        {
            right = mid - 1;
        }
        else if (res[mid] < k)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

/**
 * 方法 2，二分查找，边界我们取的是左闭右开区间，right取不到最后一个数组；
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
            right = mid;
        }
    }
    return left;
}

/**
 * 用法 2，二分查找；用它来查找第一个大于等于某个数字的下标
 * 方法 1，循环遍历，时间复杂度是O(n)
*/
int binarySearch2(vector<int> &res, int k)
{
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] >= k)
        {
            return i;
        }
    }
    return -1;
}

/**
 * 方法 2，使用二分查找，时间复杂度是O(lgn)
 * 查找第一个大于等于k的数字的下标；
*/
int binarySearch3(vector<int> &res, int k)
{
    int left = 0, n = res.size() - 1, right = n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (res[mid] >= k)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left <= n ? left : -1;
}

/**
 * 用法 3，查找第一个大于某个数的下标；
*/
// int binarySearch3(vector<int>&res, int k)
// {
//     int left = 0, n = res.size()-1, right = n;
//     while(left<=right)
//     {
//         int mid = (left+right)/2;
//         if(res[mid]>k)
//         {

//         }
//     }
// }
int main()
{
    vector<int> res = {1, 2, 2, 2, 4, 5, 6, 7, 9};
    cout << binarySearch1(res, 9) << endl;
}