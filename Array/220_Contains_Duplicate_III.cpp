#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

/**
 * Given an array of integers, 
 * find out whether there are two distinct indices i and j in the array 
 * such that the difference between nums[i] and nums[j] is at most t 
 * and the difference between i and j is at most k.
 * 数组中是否两个数的差是t=value，且对应的下标的差是k=index
 * */

/**
 * 方法 1，类似是一个滑动窗口k，然后在这个窗口k内的差值存在绝对值小于等于t即可
 * a - b <= t, 所以a - t <= b,这里找到第一个大于等于a-t的数字b，然后判断
 * b是不是存在，如果存在的话继续判断a - b 是不是小于等于t, 满足返回true
*/
bool containsNearbyAlmostDuplicate1(vector<int> &nums, int k, int t)
{
    map<long, long> res;
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i - j > k)
            res.erase(nums[j++]);
        // 找到第一个大于等于nums[i] - t 的数字
        auto a = res.lower_bound((long long)nums[i] - t); // long long 转换很关键，防止越界
        cout << "当前的a是：" << a->first << " " << a->second << endl;
        if (a != res.end() && abs(nums[i] - a->first) <= t)
            return true;
        res[nums[i]] = i;
    }
    return false;
}

/**
 * 方法 2,思路和方法 1相同，写法略有不同，set使用红黑树实现，所以自动完成排序，
 * 这里插入一个最小值和最大值,hh
*/
bool containsNearbyAlmostDuplicate2(vector<int> &nums, int k, int t)
{
    typedef long long LL;
    multiset<LL> res;
    int j = 0;
    res.insert(1e18), res.insert(-1e18);

    for (int i = 0; i < nums.size(); i++)
    {
        if (i - j > k)
            res.erase(res.find(nums[j++])); // 删除滑窗外的数字
        auto it = res.lower_bound(nums[i]); // 找到第一个大于等于nums[i]的数
        if (*it - nums[i] <= t)
            return true;
        --it;
        if (nums[i] - *it <= t)
            return true;
        res.insert(nums[i]);
    }
    return false;
}

int main()
{
    vector<int> res = {1, 5, 9, 1, 5, 9}; // 这里两个数字之差的绝对值为3，下标的差值为2
    cout << containsNearbyAlmostDuplicate2(res, 2, 3) << endl;
}