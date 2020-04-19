#include <iostream>
#include <vector>
using namespace std;

/**
 * Given an array of integers arr, a lucky integer is an integer which has
 * a frequency in the array equal to its value.
 * Return a lucky integer in the array. If there are multiple lucky integers
 * return the largest of them. If there is no lucky integer return -1.
 * 
 * Example 1:
 * Input: arr = [2,2,3,4]
 * Output: 2
 * Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
 * 
 * Example 2:
 * Input: arr = [1,2,2,3,3,3]
 * Output: 3
 * Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
*/

/**
 * 方法 1，使用的是一个记录次数的数组，因为范围从1--500，所以去500 ，方法 2 和方法 1
 * 类似，但是取的是501，所以不用涉及到下标的转换，更加方便
*/
int findLucky1(vector<int> &arr)
{
    vector<int> res(500);
    int maxValue = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        res[arr[i] - 1] += 1;
    }
    int index = 0;
    for (index = 0; index < res.size(); index++)
    {
        if (res[index] != 0 and res[index] == index + 1)
        {
            maxValue = index + 1;
        }
    }
    return maxValue;
}

/**
 * 方法 2，和上面的思路一样，不用转化
*/
int findLucky2(vector<int> &arr)
{
    int c[501] = {0};
    int ans = -1;
    for (int &n : arr)
        ++c[n];
    for (int i = 1; i < 501; ++i)
    {
        if (i == c[i])
        {
            ans = i;
        }
    }

    return ans;
}
int main()
{
    vector<int> arr = {19, 12, 11, 14, 18, 8, 6, 6, 13, 9, 8, 3, 10, 10, 1, 10, 5, 12, 13, 13, 9};
    cout << findLucky1(arr) << endl;
}