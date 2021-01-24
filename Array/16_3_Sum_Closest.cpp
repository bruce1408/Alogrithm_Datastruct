#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

/**
 * 16 给定一个数组，和一个数看，然后求解数组三数之和最接近k的这个和是多少
 * 没有重复数组。
*/

/**
 * 方法 1，使用双指针来做即可
*/
int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int ans = nums[0] + nums[1] + nums[2];
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target)
                return sum;
            if (abs(sum - target) < abs(ans - target))
                ans = sum;
            else if (sum < target)
                left++;
            else
                right--;
        }
    }
    return ans;
}

/**
 * 方法 2，使用双指针来做即可，参考y总的代码
*/
int threeSumClosest2(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    pair<int, int> res(INT_MAX, INT_MAX);
    for (int i = 0; i < nums.size(); i++)
        for (int j = i + 1, k = nums.size() - 1; j < k; j++)
        {
            while (k - 1 > j && nums[i] + nums[j] + nums[k - 1] >= target)
                k--;
            int s = nums[i] + nums[j] + nums[k];
            res = min(res, make_pair(abs(s - target), s));
            if (k - 1 > j)
            {
                s = nums[i] + nums[j] + nums[k - 1];
                res = min(res, make_pair(target - s, s));
            }
        }
    return res.second;
}

int main()
{
    vector<int> res = {-1, 2, 1, -4};
    cout << threeSumClosest(res, 2);
    return 0;
}