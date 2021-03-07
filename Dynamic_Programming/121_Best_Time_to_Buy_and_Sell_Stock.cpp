#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

/**
 * 121, 给定一个数组，然后数组i表示股票第i天的价格，然后选择一个利益最大化的情况
 * 
 * Example 1:
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and 
 * sell on day 5 (price = 6), profit = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger 
 * than buying price.
 * 
 * 求利益最大化，数组中两个数字相减的差最大，这两个数字必须减数
 * 索引大于被减数，保证先买后卖；
 */

/**
 * 方法 1，暴力搜索，时间复杂度太高了，O(n^2)的时间复杂度，两次遍历，
 * 一次头开始，还有一次从上个位置加1开始遍历，如果取 后面的数减前面的数字的最大值即可，
 * 最后返回；
*/
int maxProfit1(vector<int> &prices)
{
    int bestSelling = 0, n = prices.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bestSelling = max(bestSelling, prices[j] - prices[i]);
        }
    }
    return bestSelling;
}

/**
 * 方法 2，只用一次遍历即可，推荐做法，详见leetcode53题
*/
int maxProfit2(vector<int> &prices)
{
    int res = 0, buy = INT_MAX;
    for (int price : prices)
    {
        buy = min(buy, price);       // 买到的最小值
        res = max(res, price - buy); // 卖出的收益最大
    }
    return res;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << maxProfit1(nums) << endl;

    return 0;
}