#include<iostream>
#include<vector>
using namespace std;

/**
 * On a staircase, the i-th step has some non-negative cost cost[i]
 * assigned (0 indexed).
 * Once you pay the cost, you can either climb one or two steps.
 * You need to find minimum cost to reach the top of the floor, 
 * and you can either start from the step with index 0, or the step with index 1.
 * 
 * Example 1:
 * Input: cost = [10, 15, 20]
 * Output: 15
 * Explanation: Cheapest is start on cost[1], 
 * pay that cost and go to the top
 * 
 * 爬台阶到最顶部的最小代价，开始的时候可以从0台阶开始，也可以从1台阶开始；
 * *重做一次
 * 
*/


/**
 * 方法 1，使用动态规划来做；
*/
int minCostClimbingStairs(vector<int>& cost) 
{
    int sumCount = 0, n = cost.size();
    vector<int>res(cost.size(), 0);
    res[0] = cost[0], res[1]= cost[1];
    for(int i=2; i<cost.size();i++)
    {
        res[i] = min(res[i-1], res[i-2])+cost[i];   
    }
    return min(res[n-1], res[n-2]);
}

/**
 * 方法 2
*/

int main()
{
    vector<int> res = {10,15,10};
    cout<<minCostClimbingStairs(res)<<endl;
}
