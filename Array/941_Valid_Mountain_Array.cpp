#include <iostream>
#include <vector>
#include <set>
using namespace std;

/**
 * Given an array A of integers, 
 * return true if and only if it is a valid mountain array. 
 * 
 * Example 1:
 * Input: [2,1]
 * Output: false
 * 
 * Example 2:
 * Input: [3,5,5]
 * Output: false
 * 
 * 判断一个数组是不是mountain array的条件是数组中一部分是升序的，还有一部分是降序的
 * 例如 0，3，2，1；感觉有山的那种凸起的规律就是mountain array
 * 就是这个数的前部分数组是升序的，后部分数组是降序的即可
 */

/**
 * 方法 1，数组中的最大数和最大数的位置下标，比如A[i],然后最大数把这个数组分成两部分，
 * 一部分是A[0]-A[i];还有一部分是A[i]-A[n];设置两个布尔类型的变量leftPart, rightPart，
 * 用来记录每一部分是否满足条件，如果第一部分都是升序的排列的，那么leftPart为true，
 * 如果第二部分是降序的话，那么rightPart是true，否则是false；
 * 最后返回的是两部分做与运算即可；时间复杂度是O(n)
*/
bool validMountainArray1(vector<int> &A)
{
    if (A.size() < 3)
        return false;
    int maxNum = 0, maxIndex = 0;
    bool leftPart = false, rightPart = false;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > maxNum)
        {
            maxNum = A[i];
            maxIndex = i;
        }
    }
    for (int i = 1; i <= maxIndex; i++)
    {
        if (A[i] <= A[i - 1])
        {
            leftPart = false;
            break;
        }
        else
        {
            leftPart = true;
        }
    }
    for (int i = maxIndex; i < A.size() - 1; i++)
    {
        if (A[i] <= A[i + 1])
        {
            rightPart = false;
            break;
        }
        else
        {
            rightPart = true;
        }
    }
    return rightPart && leftPart;
}

/**
 * 方法 2，代码简洁优雅，思路自然,两个指针，一个从头走，一个从尾部走
 * 然后如果在满足条件的情况下，最后两个指针相遇即返回true
*/
bool validMountainArray2(vector<int> &A)
{
    int i = 0, len = A.size(), j = len-1;
    while (i + 1 < len && A[i + 1] > A[i])
        i++;
    while (j > 0 && A[j] < A[j - 1])
        j--;
    return i > 0 && j < len - 1 && i == j;
}

int main()
{
    vector<int> nums = {3, 5, 5};
    cout << validMountainArray2(nums);
    return 0;
}