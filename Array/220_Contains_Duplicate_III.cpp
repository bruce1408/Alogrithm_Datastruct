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
 * 方法 1
*/
bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
    map<int, int> temp;
    for (int i = 0; i < nums.size(); i++)
    {
        temp[i] = nums[i];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (temp.find(i)->second - temp.find(i + k)->second == t ||
            temp.find(i)->second - temp.find(i + k)->second == -t)
            return true;
    }
    return false;
}

/**
 * 方法 2
*/
bool containsNearbyAlmostDuplicate1(vector<int> &nums, int k, int t)
{
    map<long long, int> m;
    int j = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i - j > k)
            m.erase(nums[j++]);
        auto a = m.lower_bound((long long)nums[i] - t);
        if (a != m.end() && abs(a->first - nums[i]) <= t)
            return true;
        m[nums[i]] = i;
    }
    return false;
}

int main()
{
    vector<int> res = {1, 2, 3, 1};
    cout << containsNearbyAlmostDuplicate1(res, 3, 0) << endl;
}