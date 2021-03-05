#include <iostream>
#include <vector>
using namespace std;

/**
 * 363，给定一个二维数组，然后求计算这个不超过k的最大值
*/

/**
 * 方法 1，使用二维数组的前缀和来做即可，但是暴力解法，时间复杂度是O(n^2 * m^2)
*/
int maxSumSubmatrix(vector<vector<int> > &matrix, int k)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;
    int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
    int sum[m][n];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int t = matrix[i][j];
            if (i > 0)
                t += sum[i - 1][j];
            if (j > 0)
                t += sum[i][j - 1];
            if (i > 0 && j > 0)
                t -= sum[i - 1][j - 1];
            sum[i][j] = t;
            // 计算从0，0到ij的子矩阵的最大值部分
            for (int r = 0; r <= i; ++r)
            {
                for (int c = 0; c <= j; ++c)
                {
                    int d = sum[i][j];
                    if (r > 0)
                        d -= sum[r - 1][j];
                    if (c > 0)
                        d -= sum[i][c - 1];
                    if (r > 0 && c > 0)
                        d += sum[r - 1][c - 1];
                    if (d <= k)
                        res = max(res, d);
                }
            }
        }
    }
    return res;
}
