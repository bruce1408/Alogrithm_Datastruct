#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

/**
 * 39 给定一个无序的数组和一个目标值t，求出所有数组中的组合之和等于t的情况，然后保存到结果数组中
 * 注意，数组是不含有重复元素的,数组中的元素可以重复使用
 * 2，3，6，7, t = 7
 * 输出 2, 2, 3 和 7
 * 
*/

/**
 * 方法 1，方法错误，没有考虑组合，而是利用规律来做，漏掉了几种情况。
*/
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    for (int i = 0; i < candidates.size(); i++)
    {
        vector<int> temp;
        int tempNum = candidates[i];
        int count = 2;
        if (target % candidates[i] == 0)
        {
            for (int x = 0; x < target / candidates[i]; x++)
            {
                temp.push_back(candidates[i]);
            }
        }
        else
        {
            int tempCount = target / candidates[i];
            while (tempNum <= target)
            {
                int remainNum = target % tempNum;
                auto iter = find(candidates.begin(), candidates.end(), remainNum);
                if (iter != candidates.end())
                {
                    for (int j = 0; j < tempCount; j++)
                    {
                        temp.push_back(candidates[i]);
                    }
                    temp.push_back(remainNum);
                }
                else
                {
                    tempCount = count;
                }
                tempNum = pow(candidates[i], count);
                count += 1;
            }
        }
        if (temp.size() != 0)
        {
            res.push_back(temp);
        }
    }
    set<vector<int>> tempRes(res.begin(), res.end());
    return vector<vector<int>>(tempRes.begin(), tempRes.end());
}

/**
 * 方法 2
*/
void helper(vector<int> &candidates, int target, int start, vector<int> &out, vector<vector<int>> &res)
{
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> out;
    vector<vector<int>> res;
    helper(candidates, target, 0, out, res);
    return res;
}

int main()
{
    vector<int> res = {1, 3, 5};
    int a = 8;
    for (auto i : combinationSum(res, a))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}