#include <iostream>
#include <vector>
using namespace std;

/**
 * An array is monotonic if it is either monotone increasing
 *  or monotone decreasing.An array A is monotone increasing if 
 * for all i <= j, A[i] <= A[j].  An array A is monotone decreasing
 *  if for all i <= j, A[i] >= A[j].Return true if and only if the 
 * given array A is monotonic.
 * 证明一个数组是否是单调的，要么是递增，要么是递减的，也可以是每个元素都相同。
 * 
 * Example 1:
 * Input: [1,2,2,3]
 * Output: true
 * Example 2:
 * Input: [6,5,4,4]
 * Output: true
 * Example 3:
 * Input: [1,1,1]
 * Output: true
*/

/**
 * 方法 1：下面总有一个一直是true的情况，各取一个是升序的布尔值和降序的布尔值，然后
 * 满足升序或者降序的条件就开始加1，最后看和数组长度-1进行比较，相等即为单调数组。
 * */
bool isMonotonic1(vector<int> &A)
{
    bool incflag = true, decflag = true;
    for (int i = 0; i < A.size() - 1; i++)
    {
        incflag &= A[i + 1] <= A[i];
        decflag &= A[i + 1] >= A[i];
    }
    return incflag || decflag;
}

/**
 * 方法 2： 使用两个指针，和方法 1 都类似的解法。时间复杂度都是O(n)
 * */
bool isMonotonic2(vector<int> &A)
{
    int ansDec = 0, ansInc = 0;
    int fast = 1, slow = 0;
    while (fast < A.size())
    {
        if (A[fast] - A[slow] >= 0)
            ansDec++;
        if (A[fast] - A[slow] <= 0)
            ansInc--;
        fast++;
        slow++;
    }
    if (ansDec == A.size() - 1 || ansInc == -(A.size() - 1))
        return true;
    else
        return false;
}

/**
 * 方法 3 ，类似的思路，记录2个指针，一个是升序的，一个是降序的，满足条件这个指针分别加1
 * 最后判断和数组长度-1的大小，如果是相等返回true，否则返回false；
*/
bool isMonotonic3(vector<int> &A)
{
    int increaseB = 0, decreaseB = 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        if (A[i] <= A[i + 1])
            increaseB += 1;
        if (A[i] >= A[i + 1])
            decreaseB += 1;
    }
    if (A.size() - 1 == increaseB || A.size() - 1 == decreaseB)
    {
        return true;
    }
    else
        return false;
}

/**
 * 方法 4 ，思路都一样，但是具体细节和实现更好一些
*/
bool isMonotonic4(vector<int> &A)
{
    int len = A.size();
    bool de = true, in = true;
    if (A.size() == 1)
        return true;
    for (int i = 0; i < len - 1; i++)
    {
        if (A[i] > A[i + 1])
            in = false;
        if (A[i] < A[i + 1])
            de = false;
    }
    return in || de;
}

int main()
{
    vector<int> res = {6, 5, 4, 7};
    cout << isMonotonic4(res);
    return 0;
}