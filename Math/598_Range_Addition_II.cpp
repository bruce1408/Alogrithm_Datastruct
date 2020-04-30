#include <iostream>
#include <vector>
using namespace std;

/**
 * Given an m * n matrix M initialized with all 0's and several update operations.
 * Operations are represented by a 2D array, and each operation is 
 * represented by an array with two positive integers a and b, which means 
 * M[i][j] should be added by one for all 0 <= i < a and 0 <= j < b.
 * 
 * You need to count and return the number of maximum integers in the matrix after performing all the operations.
 * 
 * 给定一个m x n的数组，然后有一个二维数组，按照这个二维数组的范围
 * 给这个mxn的数组
*/

/**
 * 方法 1，使用暴力解法，这个没什么好说的。就是暴力,也超时了！
*/
int maxCount(int m, int n, vector<vector<int>> &ops)
{
    int maxValue = 0, count = 0;
    vector<vector<int>> res(m, vector<int>(n));
    for (auto x : ops)
    {
        for (int i = 0; i < x[0]; i++)
        {
            for (int j = 0; j < x[1]; j++)
            {
                res[i][j] += 1;
                maxValue = max(maxValue, res[i][j]);
            }
        }
    }

    for (auto i : res)
    {
        for (auto j : i)
        {
            if (j == maxValue)
            {
                count += 1;
            }
        }
    }
    return count;
}

/**
 * 方法 2，优化方法 1，
*/
int main()
{
    vector<vector<int>> res = {
        {2, 2},
        {3, 3}};
    cout << maxCount(3, 3, res) << endl;
}