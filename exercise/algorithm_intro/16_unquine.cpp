#include <iostream>
#include <vector>
using namespace std;

/**
 * 14 找出一个数组中的重复数字
 * 给定一个数组长度是n+1,然后数据范围是从1~n
 * 然后找到任意一个重复的数字即可，数组不可以修改
 * 
*/

/**
 * 方法 1，会改变原来数组，因为对每一个数*-1，然后找到对应的数，如果大于0，说明出现了2次，输出即可 
*/
int duplicate1(vector<int> &res)
{
    for (int i = 0; i < res.size(); i++)
    {
        res[res[i]] = res[res[i]] * -1;
        if (res[res[i]] > 0)
            return res[i];
    }
    return -1;
}

/**
 * 方法 2，使用抽屉原理来解决问题，n+1个苹果放进n个箱子，至少有一个箱子会出现2个苹果，所以使用二分不断缩小查询的边界。
*/
int duplicate2(vector<int> &res)
{
    int l = 1, r = res.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        int s = 0;
        for (auto i : res)
        {
            if (i >= l && i <= mid) // 如果数组的数在 l-mid 之间且含端点，那么统计次数+1，
                s++;
        }
        if (s > mid - l + 1) // 如果统计次数大于区间总长度，那么说明重复的数在此区间，继续缩小范围，让 r = mid
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    vector<int> res = {2, 1, 5, 4, 3, 2, 6, 7};
    // cout << duplicate(res) << endl;
    cout << duplicate2(res) << endl;
}