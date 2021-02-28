#include <iostream>
using namespace std;

/**
 * 120 给一个二维数组，类似三角形的形式，
 * 然后求出这个二维数组的路径最小的和是多少
 * 使用动态规划来做
*/

/**
 * 方法 1，使用dp来做这个题目
 * 从下往上做，然后最后一行不算，从倒数第二行开始算起，从下往上不需要考虑边界，
 * 写法更加简单
*/
int minimumTotal(vector<vector<int> > &f)
{
    int n = f.size();
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < i + 1; j++)
        {
            f[i][j] = min(f[i + 1][j], f[i + 1][j + 1]) + f[i][j];
        }
    }
    return f[0][0];
}
