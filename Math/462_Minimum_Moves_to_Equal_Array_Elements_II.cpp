#include <iostream>
#include <vector>
using namespace std;

/**
 * 462 详细做法可以参考货仓选址问题
*/
int minMoves2(vector<int> &nums)
{
    int res = 0, n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        res += abs(nums[i] - nums[n / 2]);
    }
    return res;
}
