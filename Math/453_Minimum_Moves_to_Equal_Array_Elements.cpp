#include <iostream>
#include <vector>
using namespace std;

/**
 * 453 数组中的元素可以加1，找出最小的操作次数是的每个元素的值相同
 * 这道题目需要反着想，每个数字通过最少的加1操作然后达到整个数组的数字都相同，那么可以
 * 找到最小的那个数字，然后其余数字减到最小数字也可以达到相同的目的，所以第一步找最小值，
 * 然后统计和最小值的差累加起来即可
*/

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int res = INT_MAX;
        for (auto x : nums)
        {
            res = min(res, x);
        }
        int cnt = 0;
        for (auto x : nums)
        {
            cnt += x - res;
        }
        return cnt;
    }
};