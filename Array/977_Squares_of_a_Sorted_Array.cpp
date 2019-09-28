#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/**
 * Given an array of integers A sorted 
 * in non-decreasing order, return an array of 
 * the squares of each number,
 *  also in sorted non-decreasing order.
 * 
 * Input: [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * 
 * 给定一个按照升序排列的含有负数的数组，然后输出每个元素平方之后
 * 的排序。其实这道题目可以看成是对负数的绝对值排序。都是一样的道理
*/

/**
 * 方法 1 就是思路自然，想到的是对元素平方，然后再利用排序
 * 算法来做，这样总的时间复杂度是 nlgn 的时间复杂度。
*/
vector<int> sortedSquares(vector<int> &A)
{
    vector<int> res;
    for (auto &i : A)
    {
        i *= i;
    }
    sort(A.begin(), A.end());
    return A;
}

/**
 * 方法 2，这道题目和绝对值排序其实一样，新建一个数组存放结果，
 * 先按照绝对值排序，然后再遍历每个数平方，把最大的存放到新建的数组res中
*/
vector<int> sortedSquares2(vector<int> &A)
{
    int slow = 0, fast = A.size() - 1;
    vector<int> res(A.size());
    while (slow <= fast)
    {
        int leftNum = A[slow] * A[slow];
        int rightNum = A[fast] * A[fast];

        if (abs(A[slow]) < abs(A[fast]))
        {
            res[fast - slow] = rightNum;
            fast--;
        }
        else
        {
            res[fast - slow] = leftNum;
            slow++;
        }
    }
    return res;
}

/**
 * 方法 3，和上面的方法 2的思路类似，写法上上面的更好理解
*/
vector<int> sortedSquares3(vector<int> &A)
{
    vector<int> res(A.size());
    int left = 0, right = A.size() - 1;
    for (int i = right; i >= 0; i--)
    {
        int leftNum = A[left] * A[left];
        int rightNum = A[right] * A[right];
        if (abs(A[left]) < abs(A[right]))
        {
            res[i] = rightNum;
            right--;
        }
        else
        {
            res[i] = leftNum;
            left++;
        }
    }
    return res;
}


vector<int> sortedSquares4(vector<int> &A)
{


}


int main()
{
    vector<int> res = {-3, -3, -2, 1};
    for (auto i : sortedSquares3(res))
    {
        cout << i << endl;
    }
}
