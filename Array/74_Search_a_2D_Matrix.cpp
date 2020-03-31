#include <iostream>
#include <vector>
using namespace std;

/**
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
 * 
 * 给定一个二维数组，和一个目标数，然后查找这个数字是否在这个数组里面，返回true 或者 false
*/
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    //这里注意，如果是一位的数组的话，那么这里就先判断是否行是0
    if(m==0)return false;
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


int main()
{
    vector<vector<int>> res = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}};
    cout << searchMatrix(res, 3) << endl;
}