#include <iostream>
#include <vector>
using namespace std;

/**
 * Your are given an array of integers prices, 
 * for which the i-th element is the price of a given stock on day i; 
 * and a non-negative integer fee representing a transaction fee.
 * You may complete as many transactions as you like, 
 * but you need to pay the transaction fee for each transaction. 
 * You may not buy more than 1 share of a stock at a time
 * (ie. you must sell the stock share before you buy again.)
 * Return the maximum profit you can make.
 * 
 * Example 1:
 * Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
 * Output: 8
 * 这道题有了交易费，所以当卖出的利润小于交易费的时候，我们就不应该卖了，不然亏了
 * 
 * 动态规划来做，
 * *重做一遍
*/

/**
 * 方法 1，利用动态规划
*/
int maxProfit(vector<int> &prices, int fee)
{
    if (prices.size() == 0)
        return 0;
    vector<int> sold(prices.size(), 0), hold = sold;
    hold[0] = -prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);
        hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
    }
    return sold.back();
}

/**
 * 方法 2，动态规划，代码更加简洁
*/
int maxProfit(vector<int> &prices, int fee)
{
    int sold = 0, hold = -prices[0];
    for (int price : prices)
    {
        int t = sold;
        sold = max(sold, hold + price - fee);
        hold = max(hold, t - price);
    }
    return sold;
}
int main()
{
    vector<int> nums = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << maxProfit(nums, fee) << endl;
    return 0;
}
