#include <iostream>
#include <vector>
using namespace std;
/**
 * 54 旋转数组
 * 给定一个矩阵，顺时针螺旋打印矩阵的数字,
 * 基本思路就是从左往右旋转打印，设定四个变量，上、下、左、右，然后
 * 循环打印，考虑三种情况，一个是横条，一个是竖条，一个是只有一个元素
*/

/**
 * 方法 1，设置4个方向的
*/
vector<int> spiralOrder(vector<vector<int>> &mat)
{
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int row = mat.size(), col = mat[0].size();
    vector<int> ans;
    vector<vector<bool>> res(row, vector<bool>(col));
    if (!row)
        return ans;
    for (int i = 0, x = 0, y = 0, d = 0; i < row * col; i++)
    {
        ans.push_back(mat[x][y]);
        res[x][y] = true;

        int a = dx[d] + x;
        int b = dy[d] + y;
        if (a < 0 || a >= row || b < 0 || b >= col || res[a][b])
        {
            d = (d + 1) % 4;
            a = dx[d] + x, b = dy[d] + y;
        }
        x = a, y = b;
    }
    return ans;
}

int main()
{
    vector<vector<int>> res = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> index = spiralOrder(res);
    for (auto i : index)
    {
        cout << i << " ";
    }
    cout << endl;
}