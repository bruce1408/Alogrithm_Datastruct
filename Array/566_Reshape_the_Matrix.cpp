#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
/**
 * In MATLAB, there is a very useful function called 'reshape', 
 * which can reshape a matrix into a new one with different size 
 * but keep its original data.You're given a matrix represented 
 * by a two-dimensional array, and two positive integers r and c 
 * representing the row number and column number of the wanted reshaped matrix,
 *  respectively.The reshaped matrix need to be filled with all
 *  the elements of the original matrix in the same row-traversing
 *  order as they were.If the 'reshape' operation with given parameters 
 * is possible and legal, output the new reshaped matrix; Otherwise, 
 * output the original matrix.
 * Example 1:
 * Input: 
 * nums = 
 * [[1,2],
 * [3,4]]
 * r = 1, c = 4
 * Output: 
 * [[1,2,3,4]]
 * Explanation:
 * The row-traversing of nums is [1,2,3,4]. 
 * The new reshaped matrix is a 1 * 4 matrix, 
 * fill it row by row by using the previous list.
*/

/**
 * 方法 1 重塑矩阵,(两个数组同时遍历怎么处理)
*/
vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
{
    int row = nums.size(), column = nums[0].size();
    if (row * column != r * c)
        return nums;
    vector<vector<int>> res(r, vector<int>(c));
    vector<int> temp(row * column);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int k = i * c + j; // 数组拉直的操作
            res[i][j] = nums[k / column][k % column];
        }
    }
    return res;
}

/**
 * 使用一个for循环即可，把要转换大小的那个也拉直即可,时间更短了。
*/
vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
{
    int row = nums.size(), column = nums[0].size();
    vector<vector<int>> res(r, vector<int>(c));
    if(row * column != r * c) return nums;
    for(int i=0; i<r*c; i++)
    {
        res[i/c][i%c] = nums[i/column][i%column];
    }
    return res;
}

int main()
{
    vector<vector<int>> res = {{1, 2},
                               {2, 4}};
    vector<vector<int>> mat = matrixReshape(res, 1, 4);
}