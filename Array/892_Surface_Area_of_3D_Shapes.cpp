#include <iostream>
#include <vector>
using namespace std;

/**
 * On a N * N grid, we place some 1 * 1 * 1 cubes.
 * Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).
 * Return the total surface area of the resulting shapes.
 * 
 * 每一个小方块的面积是6，给定一个数组，然后求解该数组的总的表面积，可能会涉及到公共部分遮挡，所以需要对这部分进行消除即可
 * 具体做法就是归纳总结规律
*/

/**
 * 方法 1，使用归纳总结，如果是单个的小方块，那么表面积是6，如果是两个堆叠，那么是10=2*6-2，如果是3个堆叠，那么是6*3-6=12
 * 所以n个堆叠的面积是4*n+2
 * 但是现在可以摆成任意的形状，所以遍历这个二维数组，单个面积是4n+2，然后开始遍历，如果下一个有紧挨着的，那么要减去紧挨着的方框的最小值即可
*/
int surfaceArea(vector<vector<int>> &grid)
{
    int res = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] > 0)
                res += 4 * grid[i][j] + 2;
            if (i > 0)
                res -= min(grid[i][j], grid[i - 1][j]) * 2;
            if (j > 0)
                res -= min(grid[i][j], grid[i][j - 1]) * 2;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> res = {
        {1, 2},
        {3, 4}};
    cout << surfaceArea(res) << endl;
}