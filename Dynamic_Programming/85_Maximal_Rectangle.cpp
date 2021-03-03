#include <iostream>
#include <vector>
using namespace std;

/**
 * 85 最大矩形；给定一个二维矩阵，然后矩阵元素只包含0-1两个数
 * 然后找到面积最大的矩形块输出即可
*/

/**
 * 方法 1，使用动态规划算法来做
 * fij状态表示ij结尾的这个矩形的长宽的最大长是多少
 * 参考链接：https://leetcode.wang/leetCode-85-Maximal-Rectangle.html
 * 也可以使用单调栈来做
*/
int maximalRectangle(vector<vector<char> > &matrix)
{
    int r = matrix.size();
    if (r == 0)
        return 0;
    int c = matrix[0].size();

    // dp[i][j] := max len of all 1s ends with col j at row i.
    vector<vector<int> > dp(r, vector<int>(c));

    // dp初始化部分
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
        {
            // 如果ij是1，且j是第一列的话，那么这个矩形的长永远是1，否则就是dpij-1 + 1
            if (matrix[i][j] == '1')
            {
                if (j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i][j - 1] + 1;
            }
            else
                dp[i][j] = 0; // 如果ij是0的话，那么长度是0
        }

    int ans = 0;

    // 开始计算面积部分，遍历行和列，因为列已经有了，所以遍历行，k从i开始到r
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
        {
            int len = INT_MAX;
            for (int k = i; k < r; k++)
            {
                len = min(len, dp[k][j]); // 找到最小的，然后求长度
                if (len == 0)
                    break;
                ans = max(len * (k - i + 1), ans); // 求解面积部分
            }
        }
    return ans;
}
