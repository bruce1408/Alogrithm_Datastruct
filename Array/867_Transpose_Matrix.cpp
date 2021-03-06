#include <iostream>
#include <vector>
using namespace std;

/**
 * Given a matrix A, return the transpose of A.
 * The transpose of a matrix is the matrix flipped over 
 * it's main diagonal, switching the row and column indices 
 * of the matrix.
 * Example 1
 * Input: [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[1,4,7],[2,5,8],[3,6,9]]
 * 
 * Example 2:
 * Input: [[1,2,3],[4,5,6]]
 * Output: [[1,4],[2,5],[3,6]]
 * 转置矩阵
*/

/**
 * 方法 1 最开始想的就是把原来矩阵转置，即 行和列互换然后赋值
 * 也就是说，n x n 的一个矩阵是没问题的，但是如果行和列不相同
 * 就没办法了，所以新建一个矩阵，行列互换。然后开始赋值操作即可。
 * 学习一下二维数组的初始化
*/
vector<vector<int>> transpose(vector<vector<int>> &A)
{
    int m = A.size(), n = A[0].size();

    // vector<vector<int>> res(n, vector<int>(m));
    vector<vector<int>> res(n, vector<int>(m, 0));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            res[j][i] = A[i][j];
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> res = {
        {1, 2, 3},
        {4, 5, 6}};

    for (auto &i : transpose(res))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}