#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Given a 2D integer matrix M representing the 
 * gray scale of an image, you need to design a
 *  smoother to make the gray scale of each cell
 *  becomes the average gray scale (rounding down)
 *  of all the 8 surrounding cells and itself. 
 * If a cell has less than 8 surrounding cells,
 *  then use as many as you can.
 * 
 * Input:
 * [[1,1,1],
 *  [1,0,1],
 *  [1,1,1]]
 * 
 * Output:
 * [[0, 0, 0],
 *  [0, 0, 0],
 *  [0, 0, 0]]
 * Explanation:
 * For the point (0,0), (0,2), (2,0), (2,2): 
 * floor(3/4) = floor(0.75) = 0
 * For the point (0,1), (1,0), 
 * (1,2), (2,1): 
 * floor(5/6) = floor(0.83333333) = 0
 * For the point (1,1): 
 * floor(8/9) = floor(0.88888889) = 0
 * 
 * 其实题目要求就是求灰度值，对于每一个点来说，求周围的点的个数和1的
 * 累加和，然后相处即可
*/

/**
 * 方法 1 对于每一个点，求周围的点的累加和再除以周围点的总和即可。
 * 这个题目最值得学习的就是如何搜索周围的点，比如上下左右等八个方位，需要构造一个数组来做，
 * 然后坐标分别相加就是数组的位置，然后看该位置是否满足行>=0且小于行数，列>=0且小于列数。
*/
vector<vector<int>> imageSmoother(vector<vector<int>> &M)
{
    vector<vector<int>> res = M, dirs{
                                     {0, -1},
                                     {0, 1},
                                     {-1, 0},
                                     {1, 0},
                                     {-1, -1},
                                     {-1, 1},
                                     {1, -1},
                                     {1, 1}};

    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M[i].size(); j++)
        {
            int pointSum = M[i][j], pointCount = 1;
            for (auto point : dirs)
            {
                int x = point[0] + i, y = point[1] + j;
                if (x < 0 || x >= M.size() || y < 0 || y >= M[0].size())
                    continue;
                pointCount += 1;
                pointSum += M[x][y];
            }
            res[i][j] = pointSum / pointCount;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> res = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};
    for (auto &i : imageSmoother(res))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
