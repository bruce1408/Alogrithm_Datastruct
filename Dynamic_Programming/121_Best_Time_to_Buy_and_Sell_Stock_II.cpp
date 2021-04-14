/**
 * 买卖股票，可以无限次买入卖出
*/
class Solution
{
public:
    int maxprofit(vector<int> &nums)
    {
        int res = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] < nums[i + 1])
                res += nums[i + 1] - nums[i];
        }
        return res;
    }
}