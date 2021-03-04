#include <iostream>
#include <vector>
using namespace std;

/**
 * 221 给定一个二维矩阵，然后矩阵中有1或者0，求解由1构成的正方形的最大面积
*/

/**
 * 方法 1，使用动态规划来做；
 * f[i][j] 表示用ij结尾的正方形的最大长度；
 * f[i][j]的初始化，i表示行，j表示列，然后如果j等于0的话，
 * 说明正方形的列的长度宽度是0列，不管i是多少行，宽度都是1，
 * 否则f[i][j]等于f[i][j-1]上一个列的宽度+1;=>f[i][j] = f[i][j-1] + 1;
 * 
*/
class Solution
{
public:
    int maximalSquare(vector<vector<char> > &s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        int m = s[0].size();
        // int n = s.size(), m = s[0].size();

        // 状态fij表示ij结尾的格子的最长宽度是多少
        vector<vector<int> > f(n, vector<int>(m));
        // 状态初始化部分

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                // 如果s[i][j]是1的话，说明有值
                if (s[i][j] == '1')
                {
                    // j=0表示只有1列，宽度是1
                    if (j == 0)
                        f[i][j] = 1;
                    // 否则ij表示的是f[i][j-1] + 1;
                    else
                        f[i][j] = f[i][j - 1] + 1;
                }
                else
                    f[i][j] = 0; // 如果s[i][j]等于0的话，那么就是宽度为0
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int len = INT_MAX;
                for (int k = i; k < n; k++)
                {
                    len = min(len, f[k][j]);
                    if (len == 0)
                        break;
                    // 这里u表示的高度，然后和85题目不一样的是u和len相同表示正方形，不是矩形
                    int u = (k - i + 1);
                    if (len == u)
                        ans = max(ans, len * u);
                }
            }
        }
        return ans;
    }
};

/**
 * 方法 2，使用动态规划来做，和上面的思路一样，但是写法不一样
*/
int maximalSquare(vector<vector<char> > &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;
    int m = matrix.size(), n = matrix[0].size(), res = 0;
    vector<vector<int> > dp(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 || j == 0)
                dp[i][j] = matrix[i][j] - '0';
            else if (matrix[i][j] == '1')
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
            res = max(res, dp[i][j]);
        }
    }
    return res * res;
}
}
;