#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

/**
 * 4 给定一个数组，然后找出三个数字之和为0的数字，不可以重复
*/

/**
 * 方法 1，双指针算法，先固定变量i，范围到n-2，然后设置两个指针l和r分别去i+1和r-1，接着开始
 * 如果当前数的和加起来小于0，那么l++，如果大于0那么r--，如果等于0的情况，那么把当前的数组元素保存
 * 到结果数组，然后判断两个指针的下一个数字是不是和当前的数字相同，如果相同的话就直接跳过。最后两个指针各自移动1位即可
*/
vector<vector<int>> threeSum1(vector<int> &res)
{
    vector<vector<int>> ans;
    int n = res.size();
    sort(res.begin(), res.end());
    for (int i = 0; i < n - 2; i++)
    {
        // 防止重复数字 *
        if (i > 0 && res[i] == res[i - 1])
            continue;
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int s = res[i] + res[l] + res[r]; // 设置s为三数的和
            if (s == 0)                       // 如果和为0的话，那么就保存到结果数组，然后再看是否有重复的数字
            {
                ans.push_back({res[i], res[l], res[r]});
                while (l < r && res[l] == res[l + 1])
                    l++;
                while (l < r && res[r] == res[r - 1])
                    r--;
                l++, r--;
            }
            else if (s < 0)
                l++;
            else
                r--;
        }
    }
    return ans;
}

int main()
{
    vector<int> res = {-2, 0, 0, 2, 2};
    // threeSum(res);
    for (auto &i : threeSum1(res))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}