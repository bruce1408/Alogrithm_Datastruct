#include <iostream>
#include <vector>
using namespace std;

/**
 * Say you have an array for which the ith element 
 * is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit.
 * You may complete as many transactions as you like 
 * (i.e., buy one and sell one share of the stock multiple times).
 * 
 * Note: You may not engage in multiple transactions at the same time
 * (i.e., you must sell the stock before you buy again).
 * 
 * Example 1:
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: 
 * Buy on day 2 (price = 1) and sell on day 3 (price = 5), 
 * profit = 5-1 = 4.
 * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), 
 * profit = 6-3 = 3.
 * 
 * 这道跟之前那道 Best Time to Buy and Sell Stock 买卖股票的最佳时间很类似，
 * 但都比较容易解答。这道题由于可以无限次买入和卖出。
 * 我们都知道炒股想挣钱当然是低价买入高价抛出，那么这里我们只需要从第二天开始，
 * 如果当前价格比之前价格高，则把差值加入利润中，因为我们可以昨天买入，
 * 今日卖出，若明日价更高的话，还可以今日买入，明日再抛出。以此类推，
 * 遍历完整个数组后即可求得最大利润。
*/

/**
 * 方法 1，炒股想挣钱当然是低价买入高价抛出，那么这里我们只需要从第二天开始，
 * 如果当前价格比之前价格高，则把差值加入利润中，因为我们可以昨天买入，
 * 今日卖出，若明日价更高的话，还可以今日买入，明日再抛出。以此类推，
 * 遍历完整个数组后即可求得最大利润。
*/
int maxProfit(vector<int> &prices)
{
    if (prices.size() == 0)
        return 0;
    int preMin = prices[0], sumNum = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > preMin)
        {
            sumNum += prices[i] - preMin;
        }
        preMin = prices[i];
    }
    return sumNum;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(nums) << endl;
    return 0;
}
