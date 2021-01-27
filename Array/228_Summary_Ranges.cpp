#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 228 区间合并
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * Example 1:
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
*/

/**
 * 方法 1，使用逻辑算法，按照题目逻辑和思路来写，代码不够优雅和简洁。
*/
vector<string> summaryRanges1(vector<int> &nums)
{
    int n = nums.size();
    vector<string> res;
    int i = 0;
    int count = 1;
    while (i < n)
    {
        if (i == n - 1)
            res.push_back(to_string(nums[i]));
        int j = i + 1;
        while (j < n)
        {
            if (nums[i] + count == nums[j])
            {
                j++;
                count++;
            }
            else
            {
                count = 1;
                if (j == i + 1)
                    res.push_back(to_string(nums[i]));
                else
                {
                    res.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
                    i = j;
                }
                break;
            }
        }
        if (j - i >= 2)
            res.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
        i = j;
    }
    return res;
}

/**
 * 方法 2, 使用双指针算法
*/
vector<string> summaryRanges3(vector<int> &nums)
{
    vector<string> res;
    for (int i = 0; i < nums.size(); i++)
    {
        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[j - 1] + 1)
            j++;
        if (j == i + 1)
            res.push_back(to_string(nums[i]));
        else
            res.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
        i = j - 1;
    }
    return res;
}

int main()
{
    vector<int> res = {0, 1, 2, 4, 5, 7};
    for (auto i : summaryRanges1(res))
    {
        cout << i << " ";
    }
    cout << endl;
}