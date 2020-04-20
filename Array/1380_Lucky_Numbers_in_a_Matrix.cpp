#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Given a m * n matrix of distinct numbers, 
 * return all lucky numbers in the matrix in any order.
 * A lucky number is an element of the matrix such that 
 * it is the minimum element in its row and maximum in its column.
 * 
 * Example 1:
 * 
 * Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
 * Output: [15]
 * Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
 * 寻找幸运数，就是一个二维数组里面，行的数目最小，列的数字最大的这个数
*/

/**
 * 方法 1，使用逻辑算法，设置两个数组，一个用来存放行的最小值所在的列，还有一个是用来存放列的最大值所在的行
 * 如果最后，行的最小值数组进行遍历，如果这个行的最小值所在数组遍历的结果是的值是列，它和列的最小值的数组的
 * 行相同的话，接直接输出当前的这个数字。
*/
vector<int> luckyNumbers(vector<vector<int>> &matrix)
{

    vector<int> minRow(matrix.size(), 0);
    vector<int> maxCol(matrix[0].size(), 0);
    vector<int> res;
    // 行要找的是最小的值
    for (int i = 0; i < matrix.size(); i++)
    {
        int col = 0, minNum = INT_MAX;
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] < minNum)
            {
                minNum = matrix[i][j];
                col = j;
            }
        }
        minRow[i] = col;
    }
    // 列要找的是最大值
    for (int j = 0; j < matrix[0].size(); j++)
    {
        int row = 0, maxNum = INT_MIN;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][j] > maxNum)
            {
                maxNum = matrix[i][j];
                row = i;
            }
        }
        maxCol[j] = row;
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        int num = minRow[i];
        if (maxCol[num] == i)
        {
            res.push_back(matrix[i][num]);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> res = {
        {1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
    for (auto i : luckyNumbers(res))
    {
        cout << i << " ";
    }
}