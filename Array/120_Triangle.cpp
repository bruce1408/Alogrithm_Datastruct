#include <iostream>
#include <vector>
#include <climits>
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
 * 方法 2，纠正上面的算法，不是每一行的最小值，而是相邻的值且最小所以修改一下
*/
int minimumTotal1(vector<vector<int>> &triangle)
{
    if (triangle.size() == 0)
        return 0;
    int sumPath = triangle[0][0];
    int index = 0, j = 0;
    for (int i = 1; i < triangle.size(); i++)
    {
        index = j;
        if (triangle[i][index] < triangle[i][index + 1])
        {
            sumPath += triangle[i][index];
            j = index;
        }
        else
        {
            sumPath += triangle[i][index + 1];
            j = index + 1;
        }
    }
    return sumPath;
}
/**
 * 方法 3，找到上面一层的最小数，记录这个数的位置，因为从下面一行开始
 * 要在上面一层的邻近位置找，但是这个算法其实不是这样的，他其实是全局最小
 * 应该是用动态规划的算法，所以方法 1，方法 2，都不对；
 * 方法 3，每次取相邻的数字然后比较大小，相加即可
 * 但是这个解法是错的，有点问题；利用的是动态规划解法
*/
int minimumTotal2(vector<vector<int>> &triangle)
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

/**
 * 方法 4，改变triangle数组，生成了一个新的数组，当前行开头和结尾的数字是上一层的开头数字相加或者是结尾的数字相加，其他位置的数字
 * 按照上一层的最小值来相加，最后返回的是最后一行的最小的数字
*/
int minimumTotal4(vector<vector<int>> &triangle)
{
    for (int i = 1; i < triangle.size(); ++i)
    {
        for (int j = 0; j < triangle[i].size(); ++j)
        {
            if (j == 0)
            {
                triangle[i][j] += triangle[i - 1][j];
            }
            else if (j == triangle[i].size() - 1)
            {
                triangle[i][j] += triangle[i - 1][j - 1];
            }
            else
            {
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
    }
    return *min_element(triangle.back().begin(), triangle.back().end());
}

/**
 * 方法 5，使用动态规划的方法来做；把最后一行的数组单独提出来，
 * 然后再把倒数第二行长度求出来，最后一行的数组就用倒数第二行的长度遍历
 * j 从0开始，找到当前的j和下一个j，比较这两个的大小，然后取最小的那个，加上上一行的相邻值即可
 * 这种方法复制了三角形最后一行，作为用来更新的一位数组。然后逐个遍历这个DP数组，对于每个数字，
 * 和它之后的元素比较选择较小的再加上面一行相邻位置的元素做为新的元素，然后一层一层的向上扫描，
 * 整个过程和冒泡排序的原理差不多，最后最小的元素都冒到前面，第一个元素即为所求
*/
int minimumTotal5(vector<vector<int>> &triangle)
{
    vector<int> dp(triangle.back());
    for (int i = (int)triangle.size() - 2; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        }
    }
    return dp[0];
}

/**
 * 方法 6，自底向上逐步求解，比上面的好理解，建议掌握！
*/
int minimumTotal6(vector<vector<int>> &A)
{
    const int n = A.size();
    vector<vector<int>> dp(n, vector<int>(0));
    //最后一行把值复制
    for (int i = 0; i < A[n - 1].size(); i++)
    {
        dp[n - 1].push_back(A[n - 1][i]);
    }

    //倒数第二行开始计算，从下一行加起来，一直到最开始的第1行，自底向上
    for (int l = n - 2; l >= 0; l--)
    {
        for (int i = 0; i < A[l].size(); i++)
        {
            dp[l].push_back(min(dp[l + 1][i], dp[l + 1][i + 1]) + A[l][i]);
        }
    }
    return dp[0][0];
}
int main()
{
    vector<vector<int>> res = {
        {-1},
        {2, 3},
        {1, -1, -3}};
    cout << minimumTotal6(res) << endl;
}
