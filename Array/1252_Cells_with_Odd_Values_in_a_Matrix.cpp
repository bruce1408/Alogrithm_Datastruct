#include <iostream>
#include <vector>
using namespace std;

/**
 * Given n and m which are the dimensions of a matrix 
 * initialized by zeros and given an array indices where 
 * indices[i] = [ri, ci]. For each pair of [ri, ci] 
 * you have to increment all cells in row ri and column ci
 * by 1.
 * 
 * Return the number of cells with odd values in 
 * the matrix after applying the increment to all indices
 * 
 * 
*/

/**
 * 方法 1,遍历indices,然后开始对每一对indices对应的行和列加1
 * 然后再暴力解题,判断奇数的元素的个数即可;
 * 总体来说是brute force
 * 时间复杂度O(n * m)
*/
int oddCells(int n, int m, vector<vector<int>> &indices)
{
    vector<vector<int>> res(n, vector<int>(m, 0));
    int countNum = 0;
    int rows = indices.size();
    for (int index = 0; index < rows; index++)
    {
        for (int i = 0; i < m; i++)
        {
            res[indices[index][0]][i]++;
        }
        for (int j = 0; j < n; j++)
        {
            res[j][indices[index][1]]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (res[i][j] % 2 != 0)
            {
                countNum += 1;
            }
        }
    }
    return countNum;
}

/**
 * 方法 2, 奇数偶数判断我们使用位运算来做也是可以的
 * 异或的话是奇数次是1，偶数次的话就是0，所以最后行表示加了偶数次还是
 * 奇数次，列也同样可以表示成这样；
 * 最后行的每一个元素和列的每一个元素再次异或操作，得到的就是整个
 * 数组的异或结果 
 * O(n * m + k)
*/
int oddCells1(int n, int m, vector<vector<int>> &indices)
{
    vector<int> row(n);
    vector<int> column(m);
    int countNum = 0;
    for (auto element : indices)
    {
        row[element[0]] ^= 1;
        column[element[1]] ^= 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            countNum += row[i] ^ column[j];
        }
    }
    return countNum;
}

/**
 * 方法 3，利用特殊的公式来计算，奇数行*偶数列 + 偶数行*奇数列
 * 就是最后的数组包含的奇数的元素，因为只有奇数行，偶数列 或者是
 * 偶数行 奇数列才能构成一个数组是奇数的元素；
*/
int oddCells2(int n, int m, vector<vector<int>> &indices)
{
    vector<int> row(n);
    vector<int> column(m);
    int countNum = 0;
    int contRow = 0, contCol = 0;
    for (auto element : indices)
    {
        row[element[0]] ^= 1;
        column[element[1]] ^= 1;
    }
    for(auto x:row)
    {
        contRow += x ? 1:0;
    }
    for(auto y:column)
    {
        contCol += y ? 1:0;
    }
    return  (n-contRow)*contCol + (m-contCol)*contRow;
}

int main()
{
    vector<vector<int>> indices = {{0, 1}, {1, 1}};
    cout << oddCells(2, 3, indices) << endl;
    cout << oddCells2(2, 3, indices) << endl;
}