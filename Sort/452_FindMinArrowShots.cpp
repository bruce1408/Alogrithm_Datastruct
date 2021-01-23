#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * 输入：points = [[10,16],[2,8],[1,6],[7,12]]
 * 输出：2
 * 解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球
 * 
*/

/**
 * 方法 1，对二维数组按照右端点进行排序，
 * 然后设置ans来记录结果，初始化为1，默认第一个端点，然后从第二个开始算起，如果右端点包含
 * 上面的右端点的话，那么就继续遍历，知道遇到不包含右端点的情况，ans加1，同时更新新的右端点的数
 * 为当前点的右端点即可
*/
class Solution
{
public:
    // 按照右端点进行从小到大进行排序 如果是左端点的话就是a[0]
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        // 按照右端点进行从小到大排序
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), cmp);
        int right = points[0][1]; // 默认的是第一个右端点，然后
        int ans = 1;
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > right)
            {
                ans += 1;
                right = points[i][1];
            }
        }
        return ans;
    }
};