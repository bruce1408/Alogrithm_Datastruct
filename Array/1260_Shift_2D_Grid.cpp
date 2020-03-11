#include <iostream>
#include <vector>
using namespace std;

/**
 * 1260 shift 2D Grid
 * Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.
 * In one shift operation:
 * Element at grid[i][j] moves to grid[i][j + 1]
 * Element at grid[i][n - 1] moves to grid[i + 1][0].
 * Element at grid[m - 1][n - 1] moves to grid[0][0].
 * Return the 2D grid after applying shift operation k times.
*/

/**
 * 方法 1，按照算法要求的逻辑去写即可，但是有个问题，就是时间复杂度比较高
 * 如果是k次的话，那么总共需要 k*m*n
*/
vector<vector<int>> moveGrid(vector<vector<int>> &grid)
{
    int rows = grid.size(), cols = grid[0].size();
    vector<int> temp;

    for (int i = 0; i < rows; i++)
    {
        temp.push_back(grid[i][cols - 1]);
    }
    for (int row = 0; row < rows; row++)
    {
        for (int col = cols - 2; col >= 0; col--)
        {
            int temp = col + 1;
            grid[row][temp] = grid[row][col];
        }
    }
    for (int num = 0; num < rows; num++)
    {
        if (num + 1 < rows)
        {
            grid[num + 1][0] = temp[num];
        }
    }
    grid[0][0] = temp[rows - 1];
    return grid;
}

vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
{
    while (k)
    {
        grid = moveGrid(grid);
        k--;
    }
    return grid;
}

/**
 * 方法 2，其实仔细观察(研究大神的代码)发现，还是有规律可循的，就是每个列的值
*/
vector<vector<int>> shiftGrid1(vector<vector<int>> &grid, int k)
{
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> res(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int n = (j + k) % cols;
            int addOne = (j + k) / cols;
            int m = (addOne + i) % rows;
            res[m][n] = grid[i][j];
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> res = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    for (auto row : shiftGrid1(res, 9))
    {
        for (auto j : row)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}