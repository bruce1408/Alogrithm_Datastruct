#include <iostream>
#include <vector>
using namespace std;

/**
 * 74 搜索一个二维矩阵，每一行都是按照升序排序，且下一行的第一个数大于上一行的最后一个数字
 * Write an efficient algorithm that searches for a value in an m x n matrix. 
 * This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last
 * integer of the previous row.
 * 
 * Example 1:
 * Input:
 * matrix = [
 * [1,   3,  5,  7],
 * [10, 11, 16, 20],
 * [23, 30, 34, 50]
 * ]
 * 
 * target = 3
 * Output: true
 */

/**
 * 方法 1，暴力搜索
*/
bool searchMatrix1(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    //这里注意，如果是一位的数组的话，那么这里就先判断是否行是0
    if (m == 0)
        return false;
    int n = matrix[0].size();
    int i = 0, j = 0;
    bool flag = false;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (matrix[i][j] == target)
            {
                flag = true;
                i = m;
                j = n;
            }
        }
    }
    return flag;
}

/**
 * 方法 2，可以使用二分查找的思路来做，用两个二分来确定范围
 * 第一个二分来确定在哪一行，第二个二分判断在哪一个列
 * 使用第一个二分确定行之后，要分情况讨论一下，
 * 首先如果l是第一行的话直接确定，
 * 如果l是其他行的话，判断上一行的最后一个数是不是大于等于t，如果大于的话，说明在l-1这一行
 * 否则最后应该是在l行不用减一
 * 确定行之后，在确定列，还是使用二分查找即可
 */
bool searchMatrix(vector<vector<int>> &mat, int t)
{

    if (mat.empty() || mat[0].empty())
        return false;
    int row = mat.size(), col = mat[0].size();
    // if (row == 1 && col == 1) //  这个判断条件和上面的等价
    //     return mat[0][0] == t ? true : false;
    int l = 0, r = row - 1;
    // 先确定在哪一行
    int k = 0;
    if (row > 1)
    {
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (mat[mid][0] >= t)
                r = mid;
            else
                l = mid + 1;
        }
        if (mat[l][0] == t)
            return true;
        // 行的三种情况
        if (l == 0) // 第一行
            k = 0;
        else if (mat[l - 1][col - 1] >= t)
            k = l - 1;
        else
            k = l;
    }

    l = 0, r = col - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (mat[k][mid] >= t)
            r = mid;
        else
            l = mid + 1;
    }
    if (mat[k][l] == t)
        return true;
    return false;
}

/**
 * 方法 3，整个二维数组是严格有序的，所以可以把二维数组转换为1位数组来组，要注意映射空间关系
 * mid -> [mid / col][mid % col]
 * 然后按照一位二分来做即可
 * */
bool searchMatrix3(vector<vector<int>> &mat, int t)
{
    if (mat.empty() || mat[0].empty())
        return false;
    int row = mat.size(), col = mat[0].size();
    int l = 0, r = row * col - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (mat[mid / col][mid % col] >= t)
            r = mid;
        else
            l = mid + 1;
    }
    if (mat[l / col][l % col] == t)
        return true;
    else
        return false;
}

int main()
{
    vector<vector<int>> res = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}};
    cout << searchMatrix2(res, 1) << endl;
}