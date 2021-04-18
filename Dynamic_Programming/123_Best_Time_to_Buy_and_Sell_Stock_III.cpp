#include <iostream>
#include <vector>
using namespace std;

/**
 * 123 买卖股票问题
 * 只能有两次交易；
*/

/**
 * 方法 1，凡是交易两次的问题，在枚举的时候使用前后缀分解来做！
*/
int maxProfit(vector<int> &prices)
{
    if (prices.empty())
        return 0;
    int n = prices.size(), g[n][3] = {0}, l[n][3] = {0};
    for (int i = 1; i < prices.size(); ++i)
    {
        int diff = prices[i] - prices[i - 1];
        for (int j = 1; j <= 2; ++j)
        {
            l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
            g[i][j] = max(l[i][j], g[i - 1][j]);
        }
    }
    return g[n - 1][2];
}