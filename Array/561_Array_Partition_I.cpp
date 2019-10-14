#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Given an array of 2n integers, 
 * your task is to group these integers into n pairs of integer, 
 * say (a1, b1), (a2, b2), ..., 
 * (an, bn) which makes sum of min(ai, bi) for all i from 1 to n 
 * as large as possible.
 * 一共是2n个数，选取n对，然后这n对中选择每一对最小的数字，所有n对中最小数字的和要最大
 * Example 1:
 * Input: [1,4,3,2]
 * Output: 4
 * Explanation: n is 2, 
 * and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
*/

/**
 * 方法 1 例如是[1，4，3，2] 这4个数字，如果选择[1, 4] 和 [2, 3]那么和就是1 + 2 =3；
 * 最大的数字和其他远远小于他的数字放在一起被浪费了，所以，最好的方法是最大的数字和次大的数字
 * 在一起，这样才可以，这样的话需要排序，[1,2,3,4] 最后的结果才能是和最大为4
*/
int arrayPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int sumNum = 0;
    int i = 0;
    while (i < len)
    {
        sumNum += nums[i];
        i += 2;
    }
    return sumNum;
}

/**
 * 方法 1-1 和上面的思路一样但是，利用的是for循环来做的
*/
int arrayPairSum1(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int len = nums.size(), sumNum = 0;
    for (int i = 0; i < len; i += 2) // 每次加2；
    {
        sumNum += nums[i];
    }
    return sumNum;
}

/**
 * 方法 2 需要传建一个hashmap，然后每次间隔1位加，最后的数字就是最大的数，不用排序，
 * 这里的一个经典例子就是对于重复的数字，应该怎么解决，这道题利用出现的次数自减1来实现。
 * 不用改变原来的数组 时间复杂度是O(n),空间复杂度是O(n) 
 * 时间确实更快
 * 且不用改变原来的数组
*/
int arrayPairSum2(vector<int> &nums)
{
    vector<int> valueIndex(2001, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        valueIndex[nums[i] + 1000]++;
    }
    int sunMun = 0;
    bool flag = true;
    for (int i = 0; i < 2001;) // 考虑重复的数字去除
    {
        if (valueIndex[i] > 0)
        {
            if (flag)
            {
                sunMun += (i - 1000);
                flag = false;
                --valueIndex[i];
            }
            else
            {
                flag = true;
                --valueIndex[i];
            }
            // i++; //切记不可使用这一句话，这一句是对于重复数字来讲的情况
        }
        else i++;
    }
    return sunMun;
}

int main()
{
    vector<int> res = {1, 2, 3, 2};
    // cout<<arrayPairSum(res)<<endl;
    cout << arrayPairSum2(res) << endl;
}