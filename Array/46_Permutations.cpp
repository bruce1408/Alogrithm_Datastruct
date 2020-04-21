#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * Input: [1,2,3]
 * Output:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 * 
 * 返回一个数组的全排列即可
*/

/**
 * 方法 1，复杂版本的递归写法，通过方法2简化了
 * */
void permuteDFS(vector<int> &num, int level, vector<int> &visited, vector<int> &out, vector<vector<int>> &res)
{
    if (level == num.size())
    {
        res.push_back(out);
        return;
    }
    for (int i = 0; i < num.size(); ++i)
    {
        if (visited[i] == 1)
            continue;
        visited[i] = 1;
        out.push_back(num[i]);
        permuteDFS(num, level + 1, visited, out, res);
        out.pop_back();
        visited[i] = 0;
    }
}

vector<vector<int>> permute1(vector<int> &num)
{
    vector<vector<int>> res;
    vector<int> out, visited(num.size(), 0);
    permuteDFS(num, 0, visited, out, res);
    return res;
}
/**
 * 方法 2，简化版的递归实现全排列算法，也是最经典的方法
*/
void helper(vector<int> nums, int begin, vector<vector<int>> &result)
{
    if (begin >= nums.size())
    {
        result.push_back(nums);
        return;
    }
    for (int i = begin; i < nums.size(); i++)
    {
        swap(nums[begin], nums[i]);
        helper(nums, begin + 1, result);
        swap(nums[begin], nums[i]);
    }
}

vector<vector<int>> permute2(vector<int> nums)
{
    vector<vector<int>> result;
    helper(nums, 0, result);
    return result;
}

/**
 * 方法 3，使用另外一种方法
*/
vector<vector<int>> permute3(vector<int> &num)
{
    if (num.empty())
        return vector<vector<int>>(1, vector<int>());
    vector<vector<int>> res;
    int first = num[0];
    num.erase(num.begin());
    vector<vector<int>> words = permute3(num);
    for (auto &a : words)
    {
        for (int i = 0; i <= a.size(); ++i)
        {
            a.insert(a.begin() + i, first);
            res.push_back(a);
            a.erase(a.begin() + i);
        }
    }
    return res;
}

/**
 * 方法 4，使用迭代的方法来做,很难理解
*/
vector<vector<int>> permute4(vector<int> &num)
{
    vector<vector<int>> res{{}}; // 只有一个空数组的初始化方法
    for (int a : num)
    {
        for (int k = res.size(); k > 0; --k)
        {
            vector<int> t = res.front();
            cout << "t size is: " << t.size() << endl;
            res.erase(res.begin());
            for (int i = 0; i <= t.size(); ++i)
            {
                vector<int> one = t;
                one.insert(one.begin() + i, a);
                res.push_back(one);
            }
        }
    }
    return res;
}

/**
 * 方法 5，使用内置函数来做,next_permutation
*/
vector<vector<int>> permute5(vector<int> &num)
{
    vector<vector<int>> res;
    sort(num.begin(), num.end());
    res.push_back(num);
    while (next_permutation(num.begin(), num.end()))
    {
        res.push_back(num);
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    for (auto i : permute5(nums))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}