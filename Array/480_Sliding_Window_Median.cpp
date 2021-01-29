#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/**
 * 480 中位数是有序序列最中间的那个数。如果序列的大小是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。
 * 例如：
 * [2,3,4]，中位数是 3
 * [2,3]，中位数是 (2 + 3) / 2 = 2.5
*/

/**
 * 方法 1，使用两个multiset来维护长度为k的窗口
*/
class Solution
{
public:
    int k;
    multiset<int> left, right; // 设置两个set
    // 求解中位数函数，如果是奇数的话，就选择右边的第一个数字，如果是偶数的话，那么就选择左集合的最右端点，右集合的最左端点
    double get_medium()
    {
        if (k % 2) 
            return *right.begin();
        return ((double)*left.rbegin() + *right.begin()) / 2;
    }

    vector<double> medianSlidingWindow(vector<int> &nums, int index)
    {
        k = index;
        // 先右集合保存k个数字
        for (int i = 0; i < k; i++)
            right.insert(nums[i]);
        
        for (int i = 0; i < k / 2; i++)
        {
            left.insert(*right.begin());
            right.erase(right.begin());
        }

        vector<double> res;
        res.push_back(get_medium());
        for (int i = k; i < nums.size(); i++)
        {
            int x = nums[i], y = nums[i - k];
            if (x >= *right.begin())
                right.insert(x);
            else
                left.insert(x);

            if (y >= *right.begin())
                right.erase(right.find(y));
            else
                left.erase(left.find(y));

            while (left.size() > right.size())
            {
                right.insert(*left.rbegin());
                left.erase(left.find(*left.rbegin()));
            }

            while (right.size() > left.size() + 1)
            {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            res.push_back(get_medium());
        }
        return res;
    }
};

int main()
{
    vector<int> res = {1, 3, -1, -3, 5, 3, 6, 7};
    Solution s;
    for (auto x : s.medianSlidingWindow(res, 3))
    {
        cout << x << " ";
    }
    cout << endl;
}