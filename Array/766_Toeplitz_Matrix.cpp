#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * A matrix is Toeplitz if every diagonal from top-left to 
 * bottom-right has the same element.Now given an M x N matrix, 
 * return True if and only if the matrix is Toeplitz.
 * 
 * 托普利兹矩阵 判别
 * 主对角线和其平行的线上面的元素相等的话，那么就是满足条件。
 * 
 * Input：
 * matrix = [
 * [1,2,3,4],
 * [5,1,2,3],
 * [9,5,1,2]
 * ]
 * Output: True
 * 
*/

/**
 * 方法 1思路很自然，就是把第一行的数字和第一列的数字遍历，第一行的数字列为0，所以初始可以表示为[i][0]
 * 然后数组的下标不得超过矩阵范围，每次行和列加1，加1之后正是斜对角的元素，如果matrix[indexI][indexJ] 和
 * matrix[indexI + 1][indexJ + 1]不相等，那么不满足条件，直接return false；否则，接着判断第一列的情况；
 * 加1与它进行对比，如果不等直接返回false，如果相同的话那么就最后返回true。
*/
bool isToeplitzMatrix(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int column = matrix[0].size();
    for (int i = 0; i < row; i++) // 第一行的情况
    {
        int indexI = i, indexJ = 0;
        while (indexJ < row - 1 && indexJ < column - 1) 
        {
            if (matrix[indexI][indexJ] != matrix[indexI + 1][indexJ + 1])
            {
                return false;
            }
            indexI++, indexJ++;
        }
    }

    for (int j = 0; j < column; j++) // 第一列的情况
    {
        int indexI = 0, indexJ = j;
        while (indexI < row - 1 && indexJ < column - 1)
        {
            if (matrix[indexI][indexJ] != matrix[indexI + 1][indexJ + 1])
            {
                return false;
            }
            indexI++, indexJ++;
        }
    }
    return true;
}

/**
 * 方法 2比较暴力，直接是每一个数字都和它右下角的数字进行对比，然后得到结果,和方法 1
 * 思路很像
*/
bool isToeplitzMatrix1(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size() - 1; i++)
    {
        for (int j = 0; j < matrix[i].size() - 1; j++)
        {
            if (matrix[i][j] != matrix[i + 1][j + 1])
                return false;
        }
    }
    return true;
}

/**
 * 方法 3 从矩阵看是从左下到右上遍历，行p从row-1 to 0, 列q从0 to column-1；然后行和列p, q 加1，看这个数和加1后的数组值
 * 是否相等，如果不等直接返回false；遍历后 p>0的话p--,否则就是q++；
*/
bool isToeplitzMatrix2(vector<vector<int>> &matrix)
{
    int row = matrix.size(), column = matrix[0].size();
    int p = row - 1, q = 0;
    while (p >= 0 && q < column)
    {
        int i = p, j = q, val = matrix[i][j];
        while (i + 1 < row && j + 1 < column)
        {
            if (val != matrix[i++][j++])
                return false;
        }
        (p > 0) ? --p : ++q; // p 和 q 的变化关系
    }
    return true;
}

int main()
{
    vector<vector<int>> res = {
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {9, 5, 1, 2}};
    // vector<vector<int>> res = {{1, 2},
    //                            {2, 2}};
    cout << isToeplitzMatrix2(res) << endl;
}
