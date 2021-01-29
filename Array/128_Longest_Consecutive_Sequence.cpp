#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * 128 最长连续序列
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
*/

/**
 * 方法 1，使用hash存储每个元素，然后遍历数组，如果当前数存在，但是当前数减一不存在，那么就冲当前数开始遍历
 * 同时删除这个数组避免重复，看当前数+1是否存在，如果存在，那么继续遍历连续的下一个数，最后退出循环的时候更新res
*/
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> s;
    for (auto x : nums)
        s.insert(x);

    int res = 0;
    for (auto x : nums)
    {
        // x -1 不存在 x存在
        if (s.count(x) && !s.count(x - 1))
        {
            int y = x;
            s.erase(x);
            while (s.count(y + 1))
            {
                s.erase(y);
                y++;
            }
            res = max(res, y - x + 1);
        }
    }
    return res;
}

int main()
{
    vector<int> res = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(res) << endl;
}