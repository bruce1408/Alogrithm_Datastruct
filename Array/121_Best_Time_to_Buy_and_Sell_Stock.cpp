#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

/**
 * Say you have an array for which the ith element is 
 * the price of a given stock on day i.
 * If you were only permitted to complete
 *  at most one transaction 
 * (i.e., buy one and sell one share of the stock), 
 * design an algorithm to find the maximum profit.
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and 
 * sell on day 5 (price = 6), profit = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger 
 * than buying price.
 * 
 * 
 */

/**
 * 方法 1，时间复杂度太高了，O(n^2)的时间复杂度，两次遍历，一次头开始，还有一次从上个
 * 位置加1开始遍历，如果取 后面的数减前面的数字的最大值即可，最后返回；
*/
int maxProfit(vector<int> &prices)
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
 * 方法 2，只用一次遍历即可，不用两次遍历
*/
// int maxProfit1(vector<int> &prices)
// {
//     for(int i=0,j=1;i<prices.size() && j<prices.size();i++)
//     {

//     }
// }

int main()
{
    vector<int> nums = {7, 2,4,3, 1};
    cout << maxProfit(nums) << endl;

    return 0;
}