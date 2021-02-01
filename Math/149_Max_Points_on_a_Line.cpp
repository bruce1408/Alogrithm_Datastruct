#include <iostream>
#include <vector>
using namespace std;

/**
 * 149 找出共线最多的点
*/

/**
 * 方法 1，固定一个点，然后遍历所有其他点，然后计算和每个点的斜率，如果是两点是垂线，那么没有斜率，所以单独
 * 统计，然后如果两点相同的话，那么也单独统计，按照相同点算，按照斜率进行存储到hash表中，最后找到最大值。
 * 然后返回找到这个res最大和斜率最多的点+重合点的个数
*/
int maxPoints(vector<vector<int>> &points)
{
    typedef long double LD;
    int res = 0;

    for (auto p : points)
    {
        int samePoint = 0, verticalPoint = 0;
        unordered_map<LD, int> hash;
        for (auto q : points)
        {
            if (p == q)
                samePoint += 1;
            else if (p[0] == q[0])
                verticalPoint++;
            else
            {
                LD k = (LD)(p[1] - q[1]) / (p[0] - q[0]); // 强制类型转换
                hash[k]++;
            }
        }
        int c = verticalPoint;
        for (auto h : hash)
            c = max(c, h.second);
        res = max(res, c + samePoint);
    }
    return res;
}
