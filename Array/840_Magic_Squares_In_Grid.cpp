#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column,
 * and both diagonals all have the same sum.
 * Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).
 * 
 * Example 1:
 * Input: [[4,3,8,4],
 *         [9,5,1,9],
 *         [2,7,6,2]]
 * Output: 1
 * 
 * 判断是否是神奇的数组，3x3的数组中，每行每列对角线相加都是相同的话，那么就是相同的数组，否则不是
*/

/**
 * 方法 1，使用逻辑解法，按照条件来写，是否每行每列对角线和是相同的，中心的数字是5
*/
bool isValid(vector<vector<int>> &grid, int i, int j)
{
    vector<int> cnt(10);
    for (int x = i; x < i + 2; ++x)
    {
        for (int y = j; y < j + 2; ++y)
        {
            int k = grid[x][y];
            if (k < 1 || k > 9 || cnt[k] == 1)
                return false;
            cnt[k] = 1;
        }
    }
    if (15 != grid[i][j] + grid[i][j + 1] + grid[i][j + 2])
        return false;
    if (15 != grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2])
        return false;
    if (15 != grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2])
        return false;
    if (15 != grid[i][j] + grid[i + 1][j] + grid[i + 2][j])
        return false;
    if (15 != grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1])
        return false;
    if (15 != grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2])
        return false;
    if (15 != grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2])
        return false;
    if (15 != grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2])
        return false;
    return true;
}

int numMagicSquaresInside(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size(), res = 0;
    for (int i = 0; i < m - 2; ++i)
    {
        for (int j = 0; j < n - 2; ++j)
        {
            if (grid[i + 1][j + 1] == 5 && isValid(grid, i, j))
                ++res;
        }
    }
    return res;
}

/**
 * 方法 2
*/
bool isValid2(vector<vector<int>> &grid, int i, int j)
{
    vector<int> res(10);
    for (int x = i; x < i + 2; x++)
    {
        for (int y = j; y < j + 2; y++)
        {
            int k = grid[x][y];
            if (k < 1 || k > 9 || res[k] == 1)
                return false;
            res[k] = 1;
        }
    }
    if (15 != grid[i][j] + grid[i][j + 1] + grid[i][j + 2])
        return false;
    if (15 != grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2])
        return false;
    if (15 != grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2])
        return false;
    if (15 != grid[i][j] + grid[i + 1][j] + grid[i + 2][j])
        return false;
    if (15 != grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1])
        return false;
    if (15 != grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2])
        return false;
    if (15 != grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2])
        return false;
    if (15 != grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2])
        return false;
    return true;
}

int numMagicSquaresInside2(vector<vector<int>> &grid)
{
    int res = 0, m = grid.size(), n = grid[0].size();
    for (int i = 0; i < grid.size() - 2; i++)
    {
        for (int j = 0; j < grid[i].size() - 2; j++)
        {
            if (grid[i + 1][j + 1] == 5 && isValid2(grid, i, j))
            {
                res++;
            }
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> res = {
        {4, 3, 8, 4},
        {9, 5, 1, 9},
        {2, 7, 6, 2}};
    cout << numMagicSquaresInside2(res) << endl;
}