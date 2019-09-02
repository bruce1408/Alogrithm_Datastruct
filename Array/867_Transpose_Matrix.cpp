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
vector<vector<int>> transpose(vector<vector<int>> &A)
{
    int m = A.size(), n = A[0].size();

    vector<vector<int>> res(n, vector<int>(m));
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