#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/**
 * 返回的是lower_bound 是大于等于x的最小下标
 * 这里如果multiset是空的话，那么lower_bound或者是upper_bound都返回begin的地址，也就是第一个插入元素的位置
*/
bool minnum(vector<int> &nums, int k, int t)
{
    typedef long long LL;
    multiset<LL> res;
    // res.insert(1e18), res.insert(-1e18);

    res.insert(1e18);
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = res.lower_bound(nums[i]);
        cout << "大于等于当前数1的第一个数是: " << *it << endl;
        if (it == res.begin())
            cout << "multiset是空，所以返回的是第一个插入元素的位置" << endl;
        if (*it - 8 < 9)
            cout << "yes i " << endl;
        --it;
        if (6 - *it <= 9)
            cout << "yes" << endl;
        cout << "it 之前的数字：" << *it << endl;

        // cout << i << endl;
        // if (i - j > k)
        //     res.erase(res.find(nums[j++])); // 删除滑窗外的数字

        // auto it = res.lower_bound(nums[i]); // 找到第一个大于等于nums[i]的数
        // cout << "大于等于nums[i]的数" << nums[i] << " " << *it << endl;
        // if (*it - nums[i] <= t)
        //     return true;
        // cout << "当前的iter " << *it << endl;

        // for (multiset<LL>::iterator iter = res.begin(); iter != res.end(); iter++)
        //     cout << *iter << endl;
        // if (it == res.begin())
        //     cout << "beginn" << endl;
        // --it;
        // cout << "d" << endl;
        // if (nums[i] - *it <= t)
        //     return true;
        // res.insert(nums[i]);
        // cout << "insert" << endl;
    }
    return false;
    // cout << "大于等于当前数7的第一个数是: " << *res.lower_bound(1) << endl;
    // for (multiset<int>::iterator iter = res.begin(); iter != res.end(); iter++)
    //     cout << *iter << endl;
}

int main()
{
    vector<int> res = {1, 5, 9, 1, 5, 9};
    minnum(res, 2, 3);
}