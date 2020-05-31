#include <iostream>
#include <vector>
using namespace std;
/**
 * Given a list of non-negative integers representing the amount of money of each house,
 * determine the maximum amount of money you can rob tonight without alerting the police.
 * Example 1:
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: 
 * Rob house 1 (money = 1) and then rob house 3 (money = 3). Total amount you can rob = 1 + 3 = 4.
 * 
 * 给定一个数组，然后取数组中最大的数字之和，要求是相邻的数组不可以取值，比如，取1，就不能取2。例子中，取1，然后取3，中间不可以取相邻的数字，
 * 返回他们的和即可
*/

/**
 * 方法 1，是认为不能相邻的取数字，那么就是隔一个取数字，但是还可以相隔多个数字,所以方法 1有问题
*/
int rob(vector<int> &nums)
{
    int n = nums.size(), sum = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int temp = 0;
        while (j < n)
        {
            temp += nums[j];
            j += 2;
        }
        sum = max(sum, temp);
    }
    return sum;
}

/**
 * 方法 2，
*/
int main()
{
    vector<int> res = {2, 1, 1, 2};
    cout << rob(res) << endl;
}