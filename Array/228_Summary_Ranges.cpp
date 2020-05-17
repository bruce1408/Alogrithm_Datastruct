#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * Example 1:
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
*/

/**
 * 方法 1，使用逻辑算法，按照题目逻辑和思路来写，代码不够优雅和简洁。
*/
vector<string> summaryRanges(vector<int> &nums)
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
 * 方法 2，教科书级别的写法，很优雅。
 * 每次检查下一个数是不是递增的。
 * 如果是，则继续往下遍历，如果不是了，我们还要判断此时是一个数还是一个序列，一个数直接存入结果，序列的话要存入首尾数字和箭头“->"。
 * 我们需要两个变量i和j，其中i是连续序列起始数字的位置，j是连续数列的长度，当j为1时，说明只有一个数字，若大于1，则是一个连续序列，代码如下：
*/
vector<string> summaryRanges2(vector<int> &nums)
{
    vector<string> res;
    int i = 0, n = nums.size();
    while (i < n)
    {
        int j = 1;
        while (i + j < n && (long)nums[i + j] - nums[i] == j)
            ++j;
        res.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
        i += j;
    }
    return res;
}

int main()
{
    vector<int> res = {0, 1, 2, 4, 5, 7};
    for (auto i : summaryRanges2(res))
    {
        cout << i << " ";
    }
    cout << endl;
}