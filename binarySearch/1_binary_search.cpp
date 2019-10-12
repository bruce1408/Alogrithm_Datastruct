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
            right = mid; // 收紧右侧边界来确定条件是否可以终止；
        }
    }
    // return left; // 如果查到了，返回下标；否则返回的是整个数组的长度，解释见开头
    return res[left] == k ? left : -1;
}

/**
 * 用法 2，二分查找；用它来查找第一个大于等于某个数字的下标
 * 
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
    vector<int> res = {1, 2, 2, 2, 3, 5, 6};
    cout << binarySearch1(res, 2) << endl;
}