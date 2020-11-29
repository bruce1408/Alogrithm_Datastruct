#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;
/**
 * 前缀和数组求解，对于一个数组a来说，前缀和数组的求和公式为：
 * s[i][j] = s[i-1][j] + s[i][j-1]-s[i-1][j-1] + a[i][j]；
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
        result.push_back(nums[pairs[i][1]] - nums[pairs[i][0]] + res[pairs[i][0]]);
    }
    return result;
}

int main()
{
    int n, m, q;
    // cout << "请输入两个数字n和m，n表示数组长度，m表示区间对数：" << endl;
    cin >> n >> m >> q;
    vector<vector<int>> prefixSum(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> res(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            cin >> res[i][j];
            prefixSum[i][j] = prefixSum[i][j - 1] + prefixSum[i - 1][j] - prefixSum[i - 1][j - 1] + res[i][j];
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >>y1 >> x2>>y2;
        cout<<prefixSum[x2][y2] - prefixSum[x2][y1-1]-prefixSum[x1-1][y2] + prefixSum[x1-1][y1-1]<<endl;
    }
}