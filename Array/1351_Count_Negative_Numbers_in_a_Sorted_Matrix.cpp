#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法 1，暴力遍历数组即可
*/
int countNegatives(vector<vector<int>> &grid)
{
    int num = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] < 0)
            {
                num += 1;
            }
        }
    }
    return num;
}

/**
 * 方法 2，利用数组是降序的即可,使用的是二分里面的upper——bound，
 * 因为是逆序，所以，这里求得是upper，就是第一个小于的数的位置，从0开始计数
 * 然后总长度 - 位置，就是当前行的长度。
 * 升序lower 大于或等于，upper 是 大于
 * 降序lower 小于或等于，upper 是 小于
*/
int countNegatives2(vector<vector<int>> &grid)
{
    int num = 0, m = grid[0].size();
    for (int i = 0; i < grid.size(); i++)
    {
        vector<int>::iterator low = upper_bound(grid[i].begin(), grid[i].end(), 0, greater<int>());
        num = num + m - (low - grid[i].begin());
    }
    return num;
}

/**
 * 方法 3，这个方法很好！O(n)的时间复杂度来做，因为每行，每列的数组都是从大到小排序，
 * 所以，从每行的最后一位开始判断是不是小于0，如果小于0的话，那么这一列的数目都要加上，因为最开始的元素
 * 小于0，该列的其他肯定小于0，然后继续判断倒数第二列，以此类推，如果该行改列不是小于0的话，这个行要自加一位，
 * 判断下一行是不是小于0的情况。
*/
int countNegatives3(vector<vector<int>> &grid)
{
    int count = 0, i = 0, j = grid[0].size() - 1;
    while (i < grid.size() && j >= 0)
    {
        if (grid[i][j] < 0)
        {
            count += grid.size() - i;
            j--;
        }
        else
        {
            i++;
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> res = {
        {3, 2, -1},
        {2, -1, -2}};
    cout << countNegatives3(res) << endl;
}