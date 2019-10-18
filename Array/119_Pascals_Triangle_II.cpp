#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

/**
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
 * 方法 1，利用杨辉三角的每个元素的组合公式，Cn，k = n!/(n-k)!*k!
 * 但是涉及到阶乘，就会有发生溢出的问题，数值太大了，整数范围表示的数不够；
*/
int factori(int n)
{
    int sum = 1;
    while (n > 1)
    {
        sum *= n;
        n--;
    }
    return sum;
}
vector<int> getRow(int rowIndex)
{
    vector<int> res(rowIndex + 1, 1);
    for (int i = 1; i < rowIndex; i++)
    {
        res[i] = factori(rowIndex) / (factori(i) * factori(rowIndex - i));
    }
    return res;
}

/**
 * 方法 2, 第一次看的时候比较难理解，后来看明白了，本题目的算法就是
 * 第n层，我们设置一个长度是n+1的数组，因为本题从0开始计数，然后
 * 使用两次for循环，第一次从1到n-1；就是头和尾的1不用考虑，遍历
 * 第二层for循环就是j从i开始，到j>=1;其实就是从后往前不断的把相邻的
 * 数字加上去，最后构成了杨辉三角的第n层的数字；
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

int main()
{
    int num = 5;
    for (auto x : getRow1(num))
    {
        cout << x << " ";
    }
}
