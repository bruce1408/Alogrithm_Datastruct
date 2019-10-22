#include <iostream>
#include <vector>
#include<climits>
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
 * 
 * 应该使用的是动态规划的方法
*/

/**
 * 方法 1，这个方法是错误的，误以为是选择每一层的最小数，其实不是
 * 是上一层和他相邻的数的最小的值才可以；
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

/**
<<<<<<< HEAD
 * 方法 2，找到上面一层的最小数，记录这个数的位置，因为从下面一行开始
 * 要在上面一层的邻近位置找，但是这个算法其实不是这样的，他其实是全局最小
 * 应该是用动态规划的算法，所以方法 1，方法 2，都不对；
=======
 * 方法 2，每次取相邻的数字然后比较大小，相加即可
 * 但是这个解法是错的，有点问题；利用的是动态规划解法
>>>>>>> a080dc5e6fa2ad3c29453b05f06fce651913273e
*/
int minimumTotal1(vector<vector<int>> &triangle)
{
    if (triangle.size() == 0)
        return 0;
    int rows = triangle.size(), sumCount = triangle[0][0], j = 0;
    for (int i = 1; i < rows; i++)
    {
        int index = j;
        if (j + 1 < triangle[i].size())
        {
            if (triangle[i][index] > triangle[i][index + 1])
            {
                j = index + 1;
                sumCount += triangle[i][index + 1];
            }
            else
            {
                j = index;
                sumCount += triangle[i][index];
            }
        }
    }
    return sumCount;
}

<<<<<<< HEAD
=======

>>>>>>> a080dc5e6fa2ad3c29453b05f06fce651913273e
int main()
{
    vector<vector<int>> res = {
        {-1},
        {2, 3},
        {1, -1, -3}};
    cout << minimumTotal1(res) << endl;
}
