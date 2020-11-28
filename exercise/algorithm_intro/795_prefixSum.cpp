#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include "../../utils/cout_vec.h"
using namespace std;

/**
 * 方法 1，和方法 2思路都一样，就是写法有点不同；
 * 前缀和求解，可以很方便计算前n项目的和，不用多循环遍历；
*/
vector<int> prefixSum(vector<int> &res, vector<vector<int>> &pairs)
{
    vector<int> nums(res.size());
    vector<int> result;
    for (int i = 1; i < res.size(); i++)
    {
        nums[i] = nums[i - 1] + res[i];
    }
    for (int i = 0; i < pairs.size(); i++)
    {
        result.push_back(nums[pairs[i][1]] - nums[pairs[i][0] - 1]);
    }
    return result;
}

/**
 * 方法 2，写法简单
*/
vector<int> prefixSum1(vector<int> &res)
{
    vector<int> prefix(res.size());
    for (int i = 1; i < res.size(); i++)
    {
        prefix[i] = prefix[i - 1] + res[i];
    }
    return prefix;
}
int main()
{
    int n, m;
    cout << "请输入两个数字n和m，n表示数组长度，m表示区间对数：" << endl;
    cin >> n >> m;
    vector<int> res(n + 1);
    for (int i = 1; i < n + 1; i++)
        cin >> res[i];
    vector<vector<int>> cord;
    /**
     * 方法 1写法
    */
    // while (m--)
    // {
    //     int x1, x2;
    //     cin >> x1 >> x2;
    //     cord.push_back({x1, x2});
    // }
    // for (auto i : prefixSum(res, cord))
    //     cout << i << endl;
    /**
     * 方法 2写法
    */
    auto c = prefixSum1(res);
    while (m--)
    {
        int x1, x2;
        cin >> x1 >> x2;
        cout << c[x2] - c[x1 - 1] << endl;
    }
}
