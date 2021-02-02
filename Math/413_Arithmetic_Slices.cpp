#include <iostream>
using namespace std;
/**
 * 413. Arithmetic Slices
 * 给一个等差数列数组，然后求解这个等差中含有多少子数组也是等差数列
*/

/**
 * 方法 1，用差分数组来求解更加简单，等差数列就是前向减去后向的值相同，然后数目大于等于3
 * 然后遍历这个数组，只要求出差分，然后找到有多少是数值相同的，然后这段数值相同的序列中含有的子数组是
 * n * (n - 1) / 2;
*/
int numberOfArithmeticSlices(vector<int> &A)
{
    for (int i = A.size() - 1; i > 0; i--)
    {
        A[i] -= A[i - 1];
    }
    int res = 0;
    for (int i = 1; i < A.size(); i++)
    {
        int j = i;
        while (j < A.size() && A[i] == A[j])
            j++;
        int k = (j - i);
        res += (k - 1) * k / 2;
        i = j - 1;
    }
    return res;
}
