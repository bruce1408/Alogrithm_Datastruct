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
 * 方法 1，暴力搜索使用两层for循环来做，注意这里两层for循环是变体，
 * 增加了因为找到条件之后就终止
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
 * 方法 2，可以使用二分查找的思路来做，二分查找用来查找二维数组的情况
 */
bool searchMatrix2(vector<vector<int>> &mat, int t)
{
    
}
int main()
{
    vector<vector<int>> res = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}};
    cout << searchMatrix2(res, 3) << endl;
}