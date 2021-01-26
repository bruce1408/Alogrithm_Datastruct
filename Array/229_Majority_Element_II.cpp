#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 229 给定一个数组，然后求重复次数超过n/3的个数的数字，返回一个数组
*/

/**
 * 方法 2，投票法，不使用排序算法~,题目要求不能排序
 * */
vector<int> majorityElement2(vector<int> &nums)
{
    vector<int> res;
    int timesNum = nums.size() / 3;
    int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
    // 第一个for循环选出对多的两个数字
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == candidate1)
            count1++;
        else if (nums[i] == candidate2)
            count2++;
        else if (count1 == 0)
        {
            candidate1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            candidate2 = nums[i];
            count2 = 1;
        }
        else
            --count1, --count2;
    }
    count1 = count2 = 0; // 重新开始计数
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == candidate1)
            count1++;
        else if (nums[i] == candidate2)
            count2++;
    }
    if (count1 > timesNum)
        res.push_back(candidate1);
    if (count2 > timesNum)
        res.push_back(candidate2);
    return res;
}

int main()
{
    vector<int> res = {3, 2, 2, 2, 1, 1, 2, 3, 3, 3};
    for (auto i : majorityElement2(res))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}