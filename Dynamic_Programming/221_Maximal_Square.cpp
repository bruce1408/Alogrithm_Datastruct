#include <iostream>
#include <vector>
using namespace std;

/**
 * 221 给定一个二维矩阵，然后矩阵中有1或者0，求解由1构成的正方形的最大面积
 * 和85题目非常类似
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
 * 边界条件处理完了，再来看一般情况的递推公式怎么办，对于任意一点dp[i][j]，
 * 由于该点是正方形的右下角，所以该点的右边，下边，右下边都不用考虑，
 * 关心的就是左边，上边，和左上边。这三个位置的dp值 suppose 都应该算好的，
 * 还有就是要知道一点，只有当前 (i, j) 位置为1，dp[i][j] 才有可能大于0，
 * 否则 dp[i][j] 一定为0。当 (i, j) 位置为1，
 * 此时要看 dp[i-1][j-1], dp[i][j-1]，和 dp[i-1][j] 这三个位置，
 * 我们找其中最小的值，并加上1，就是 dp[i][j] 的当前值了，
 * 这个并不难想，毕竟不能有0存在，所以只能取交集，
 * 最后再用 dp[i][j] 的值来更新结果 res 的值即可，
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
                // ij这个位置的左上，上边，左边的三个情况取最小即可
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
            res = max(res, dp[i][j]);
        }
    }
    return res * res;
}