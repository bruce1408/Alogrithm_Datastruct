#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
 * 示例：
 * 输入：nums = [5,2,6,1]
 * 输出：[2,1,1,0] 
 * 解释：
 * 5 的右侧有 2 个更小的元素 (2 和 1)
 * 2 的右侧仅有 1 个更小的元素 (1)
 * 6 的右侧有 1 个更小的元素 (1)
 * 1 的右侧有 0 个更小的元素
*/

/**
 * 方法 1，暴力来一次,肯定超时了
*/
vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] >= nums[j])
                cnt++;
        }
        res.push_back(cnt);
    }
    return res;
}

/**
 * 方法 2，使用树状数组的做法
 * 
*/
class Solution
{
public:
    vector<int> c; // 类内初始化的话在主函数resize一下
    // vector<int> c{vector<int>(20002,0)}; // 或者使用这个也可以初始化

    int n = 20001;
    int lowbit(int x)
    {
        return x & -x;
    }

    int getSum(int x)
    {
        int sum = 0;
        for (int i = x; i; i -= lowbit(i))
            sum += c[i];
        return sum;
    }

    void update(int x, int v)
    {
        for (int i = x; i <= n; i += lowbit(i))
            c[i] += v;
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        c.resize(20002);
        vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            nums[i] += 10001;
            res[i] = getSum(nums[i] - 1);
            update(nums[i], 1);
        }
        return res;
    }
};

int main()
{
    vector<int> res = {5, 2, 6, 1};
    Solution s;
    for (auto i : s.countSmaller(res))
        cout << i << " ";
    cout << endl;
}