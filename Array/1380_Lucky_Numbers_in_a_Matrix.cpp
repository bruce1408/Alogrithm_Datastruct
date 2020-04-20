#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Given a m * n matrix of distinct numbers, 
 * return all lucky numbers in the matrix in any order.
 * A lucky number is an element of the matrix such that 
 * it is the minimum element in its row and maximum in its column.
 * 
 * Example 1:
 * 
 * Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
 * Output: [15]
 * Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
 * 寻找幸运数，就是一个二维数组里面，行的数目最小，列的数字最大的这个数
*/

/**
 * 方法 1，
*/
vector<int> luckyNumbers(vector<vector<int>> &matrix)
{
    int maxRow = 0, rowIndex = 0, colIndex = 0;
    
}

int main()
{  
    vector<vector<int>>res = {
        {3,7,8},
        {9,11,13},
        {15,16,17}
    };
    luckyNumbers(res);
}