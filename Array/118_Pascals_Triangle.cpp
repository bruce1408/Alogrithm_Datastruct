#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

/**
 * 118 杨辉三角
 * Given a non-negative integer numRows, 
 * generate the first numRows of Pascal's triangle.
 * 
 * Example:
 * Input: 5
 * Output:
 * [
 *  [1],
 *  [1,1],
 *  [1,2,1],
 *  [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 * 打印杨辉三角即可
*/

/**
 * 方法 1，利用的杨辉三角的性质，两层for循环遍历；
 * 每层的不是开头的和最后的数字的话，其他的位置的数字应该按照
 * temp[j] 等于上层的当前res[i-1][j]位置和上层的前一个位置
 * res[i-1][j-1]位置的和
 * temp[j] = res[i-1][j-1]+res[i-1][j];
*/
vector<vector<int>> generate1(int n)
{
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(i + 1, 1); // 每层的初始化是1；
        for (int j = 1; j < temp.size() - 1; j++)
        {
            temp[j] = res[i - 1][j] + res[i - 1][j - 1];
        }
        res.push_back(temp);
    }
    return res;
}

/**
 * 方法 2，只用一个res二维数组，每次就对当前的这个res进行变换即可～
 * res[i][j] = res[i-1][j]+res[i-1][j-1];
 * */
vector<vector<int>> generate2(int numRows)
{
    vector<vector<int>> res(numRows, vector<int>());
    for (int i = 0; i < numRows; i++)
    {
        res[i].resize(i + 1, 1); // 对当前的这个数组变换
        for (int j = 1; j < i; j++)
        {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }
    return res;
}

int main()
{
    int num = 5;
    for (auto x : generate2(num))
    {
        for (auto i : x)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
