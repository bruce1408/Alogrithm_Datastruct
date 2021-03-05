#include <iostream>
#include <vector>
using namespace std;

/**
 * 计算二维矩阵的前缀和,设置一个二维矩阵
 * s[i][j] 表示从左上角到[i][j]这个点的总和
*/
class NumMatrix
{
public:
    vector<vector<int> > s;
    NumMatrix(vector<vector<int> > &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return;
        int n = matrix.size(), m = matrix[0].size();
        s = vector<vector<int> >(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int x1, int y1, int x2, int y2)
    {
        x1++, y1++, x2++, y2++;
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
