#include <iostream>
#include <vector>
#include <map>
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
*/
bool containsNearbyAlmostDuplicate1(vector<int> &nums, int k, int t)
{
    map<long, long> res;
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i - j > k)
            res.erase(nums[j++]);
        cout << nums[i] - t << endl;
        auto a = res.lower_bound((long long)nums[i] - t); // long long 转换很关键，防止越界
        cout << "当前的a是：" << a->first << " " << a->second << endl;
        if (a != res.end() && abs(nums[i] - a->first) <= t)
            return true;
        res[nums[i]] = i;
    }
    return false;
}

/**
 * 方法 2
*/
bool containsNearbyAlmostDuplicate2(vector<int> &nums, int k, int t)
{
    return false;
}

int main()
{
    vector<int> res = {1, 1, 2, 2, 3, 3};
    cout << containsNearbyAlmostDuplicate1(res, 2, 3) << endl;
}