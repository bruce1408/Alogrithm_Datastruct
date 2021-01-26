#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

/**
 * 119 杨辉三角
 * Given a non-negative index k where k ≤ 33, 
 * return the kth index row of the Pascal's triangle.
 * Note that the row index starts from 0.
 * 
 * Example:
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 给一个数字，然后返回的是这个杨辉三角的第k层的数组，杨辉三角
 * 层数从0开始技计数；
 * 这个题目有要求，只用O(k)的额外空间即可；
*/

/**
 * 方法 1, 第一次看的时候比较难理解，后来看明白了，本题目的算法就是
 * 第n层，我们设置一个长度是n+1的数组(因为从0开始)，本题从0开始计数，然后
 * 使用两次for循环，第一次从1到n-1；就是头和尾的1不用考虑，遍历
 * 第二层for循环j从i开始，到j>=1;从当前的数到最前的数字相加就是杨辉三角的j位置上的数字，
 * 其实就是从后往前不断的把相邻的数字加上去，最后构成了杨辉三角的第n层的数字；
*/
vector<int> getRow1(int rowIndex)
{
    vector<int> res(rowIndex + 1, 1);
    for (int i = 1; i < rowIndex; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            res[j] += res[j - 1];
        }
    }
    return res;
}

/**
 * 方法 2，使用滚动数组来做即可，为优化版本
 * 设置一个n+1 * n+1 的数组来保存这个结果然后最后输出n行即可
 * 但是空间不满足要求
*/
vector<int> getRow2(int k)
{
    vector<vector<int>> res(k + 1, vector<int>(k + 1));
    for (int i = 0; i <= k; i++)
    {
        res[i][0] = res[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
        }
    }
    return res[k];
}

/**
 * 方法 3，使用滚动数组来做即可 推荐做法
 * 因为下面一行之和上面一行有关系，计算1的时候需要用到0行，计算2行的时候不需要0行，因此可以替代
 * 从而0，2，4，6，8... 和 1，3，5，7，9都可以不断通过2行来更新
 * 如何判断奇偶的话呢，使用n & 1结果，所以上面可以优化成为下面的式子
*/
vector<int> getRow3(int k)
{
    vector<vector<int>> res(2, vector<int>(k + 1));
    for (int i = 0; i <= k; i++)
    {
        res[i & 1][0] = res[i & 1][i] = 1;
        for (int j = 1; j < i; j++)
        {
            res[i & 1][j] = res[(i - 1) & 1][j] + res[(i - 1) & 1][j - 1];
        }
    }
    return res[k & 1];
}

int main()
{
    int num = 5;
    for (auto x : getRow1(num))
    {
        cout << x << " ";
    }
}
