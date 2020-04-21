#include <iostream>
#include <vector>
using namespace std;

/**
 * On a plane there are n points with integer coordinates points[i] = [xi, yi].
 * Your task is to find the minimum time in seconds to visit all points.
 * 
 * Input: points = [[1,1],[3,4],[-1,0]]
 * Output: 7
 * Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0] 
 * Time from [1,1] to [3,4] = 3 seconds 
 * Time from [3,4] to [-1,0] = 4 seconds
 * Total time = 7 seconds
 * 
 * Example 2:
 * Input: points = [[3,2],[-2,2]]
 * Output: 5
*/

/**
 * 方法 1，看过例子之后发现，一般是两个点之间的坐标的差的绝对值的最大值相加即可
*/
int minTimeToVisitAllPoints(vector<vector<int>> &points)
{
    int sum = 0;
    for (int i = 0; i < points.size() - 1; i++)
    {
        sum += max(abs(points[i][0] - points[i + 1][0]), abs(points[i][1] - points[i + 1][1]));
    }
    return sum;
}

int main()
{
    vector<vector<int>> res = {
        {1, 1},
        {3, 4},
        {-1, 0}};
    cout << minTimeToVisitAllPoints(res) << endl;
}