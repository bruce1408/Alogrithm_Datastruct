#include <iostream>
#include <vector>
using namespace std;

/**
 * Given a triangle, 
 * find the minimum path sum from top to bottom. 
 * Each step you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 *   [
 *    [2],
 *   [3,4],
 *  [6,5,7],
 * [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11
 * (i.e., 2 + 3 + 5 + 1 = 11).
*/
int minimumTotal(vector<vector<int>> &triangle)
{
    int rows = triangle.size();
    int sumNum = 0;
    for (int i = 0; i < rows; i++)
    {
        int minNum = INT_MAX;
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (triangle[i][j] < minNum)
            {
                minNum = triangle[i][j];
            }
        }
        sumNum += minNum;
    }
    return sumNum;
}

int main()
{
    vector<vector<int>> res = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
    cout << minimumTotal(res) << endl;
}
