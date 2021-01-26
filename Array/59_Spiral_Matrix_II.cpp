#include <iostream>
#include <vector>
using namespace std;
/**
 * 59 和 54 基本一样，
 * 54 是顺时针打印遍历每一个数字，59是给出一个n，然后填进去，构成一个n*n的矩阵
 * 给定一个矩阵，顺时针螺旋设置矩阵的数字,基本思路就是从左往右，设定四个变量，上、下、左、右，
*/

/**
 * 方法 1，设置一个方向数组
*/
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> res(n, vector<int>(n));
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    vector<vector<bool>> state(n, vector<bool>(n));
    for (int i = 0, x = 0, y = 0, d = 0; i < n * n; i++)
    {
        res[x][y] = i + 1;
        state[x][y] = true;

        int a = dx[d] + x;
        int b = dy[d] + y;

        if (a < 0 || a >= n || b < 0 || b >= n || state[a][b])
        {
            d = (d + 1) % 4;
            a = dx[d] + x;
            b = dy[d] + y;
        }
        x = a, y = b;
    }
    return res;
}

int main()
{
    vector<vector<int>> res = generateMatrix(3);
    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}