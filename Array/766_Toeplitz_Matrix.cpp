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
 * 方法 1思路很自然，就是把第一行的数字和第一列的数字遍历，然后每次遇到这个数字的时候就行与列同时
 * 加1与它进行对比，如果不等直接返回false，如果相同的话那么就最后返回true。
*/
bool isToeplitzMatrix(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int column = matrix[0].size();
    for (int i = 0; i < row; i++)
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

    for (int j = 0; j < column; j++)
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
 * 方法 2比较暴力，直接是每一个数字都和它右下角的数字进行对比，然后得到结果
*/
bool isToeplitzMatrix1(vector<vector<int>>&matrix)
{
    for(int i=0;i<matrix.size()-1;i++)
    {
        for(int j=0;j<matrix[i].size()-1;j++)
        {
            if(matrix[i][j]!=matrix[i+1][j+1]) return false;
        }
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
    cout << isToeplitzMatrix(res) << endl;
}
