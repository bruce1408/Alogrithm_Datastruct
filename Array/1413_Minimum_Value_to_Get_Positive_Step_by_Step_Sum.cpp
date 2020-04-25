#include <iostream>
#include <vector>
using namespace std;

/**
 * Example 1:
 * Input: nums = [-3,2,-3,4,2]
 * Output: 5
 * Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
 *                 step by step sum
 *                 startValue = 4 | startValue = 5 | nums
 *                   (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
 *                   (1 +2 ) = 3  | (2 +2 ) = 4    |   2
 *                   (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
 *                   (0 +4 ) = 4  | (1 +4 ) = 5    |   4
 *                   (4 +2 ) = 6  | (5 +2 ) = 7    |   2
 * 
 * 从正数开始startValue，然后遍历这个数组，累积和要不小于1的最小的正数，那就返回，比如4，有一个值和加之后是0，不满足，5 满足 返回
*/

/**
 * 方法 1，使用暴力解法，就是不断迭代遍历，如果满足条件就返回
*/
int minStartValue(vector<int> &nums)
{
    int i = 1, j = 0, sum;
    bool flag = true;
    while (flag)
    {
        sum = i;
        for (j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum < 1)
            {
                j = 0;
                sum = 0;
                i++;
                break;
            }
        }
        if (j == nums.size())
        {
            flag = false;
            return i;
        }
    }
    return i;
}

/**
 * 方法 2，使用时间复杂度是O(n)
*/
int minStartValue1(vector<int> &nums)
{
    int ans = 1;
    int curVal = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        curVal += nums[i];
        if (curVal < 1)
        {
            ans += (1 - curVal);
            curVal = 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> res = {-3, 2, -3, 4, 2};
    cout << minStartValue1(res) << endl;
}