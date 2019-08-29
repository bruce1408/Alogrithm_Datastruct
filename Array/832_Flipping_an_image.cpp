#include <iostream>
#include <vector>
using namespace std;

/**
 * 832题目 旋转一个二维数组，先水平翻转，然后把1变成0即可，
 * 思路就是先把数组挨个水平翻转，然后再把数组看是否为1，则置0
 * 需要两个for 循环来做，思路自然，但是vector需要知道数组的维度大小。而且第二维度的数组要
 * 取到一半，否则翻转结果还是原来的数组
*/
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        int firstDim = A.size();
        int secondDim = A[0].size();
        cout << "firstDim: " << firstDim << endl;
        cout << "secondDim: " << secondDim << endl;
        // 第一个for循环 水平翻转
        for (int i = 0; i < firstDim; i++)
        {
            for (int j = 0; j < secondDim / 2; j++)
            {
                int temp = A[i][j];
                A[i][j] = A[i][secondDim - j - 1];
                A[i][secondDim - j - 1] = temp;
            }
        }

        // 第二个for循环用来置1、0
        for (int i = 0; i < firstDim; i++)
        {
            for (int j = 0; j < secondDim; j++)
            {
                if (A[i][j] == 1)
                    A[i][j] = 0;
                else
                    A[i][j] = 1;
            }
        }
        return A;
    }
};

/**
 * 方法2，和上面的方法一样，但是写法却很简单，会改变原来的数组
*/
vector<vector<int>> flipAndInvertImage1(vector<vector<int>> &A)
{
    for (auto &row : A)
        reverse(row.begin(), row.end()); // 没一行翻转，然后遍历和1异或
    for (auto &row : A)
    {
        for (int &num : row)
            num ^= 1;
    }
    return A;
}

/**
 * 方法3 上面的方法会改变数组，所以在这里新建一个数组,按照行的顺序，但是每行从后往前遍历
 * 依次和1异或，或者是取反即可。
*/
vector<vector<int>> flipAndInvertImage2(vector<vector<int>> &A)
{
    vector<vector<int>> res(A.size()); // vector知识点，不可以用数组下标，而是push_back
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = A[0].size() - 1; j >= 0; j--)
        {
            res[i].push_back(A[i][j] ^ 1);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> p = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 0, 0}};

    // Solution s;
    // vector<vector<int>> res = s.flipAndInvertImage(p);
    // vector<vector<int>> res;
    // res = flipAndInvertImage1(p);

    vector<vector<int>> res = flipAndInvertImage2(p);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}