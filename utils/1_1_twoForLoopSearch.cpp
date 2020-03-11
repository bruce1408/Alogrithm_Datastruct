#include <iostream>
#include <vector>
using namespace std;
// 二维数组查找数组中的数字
/**
 * 方法 1，不需要两个for循环，而是一个while循环即可找到二维数组的当前数字的坐标
 * 给定一个二维数组，查找这个二维数组的这个数字，然后返回这个数字的横纵坐标
*/
vector<int> searchAxis(vector<vector<int>> &res, int target)
{
    vector<int> result(2, -1);
    int i = 0, j = 0;
    int col = res[0].size();
    while (true)
    {
        if (res[i][j] == target)
        {
            result[0] = i;
            result[1] = j;
            break;
        }
        j++;
        if (j == col)
        {
            i++;
            j = 0;
        }
    }
    return result;
}

/**
 * 方法 2，利用的是两重for循环来查找当前数字；
*/
vector<int> searchAxis1(vector<vector<int>> &res, int target)
{
    vector<int> result;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            if (res[i][j] == target)
            {
                result.push_back(i);
                result.push_back(j);
                break;
            }
        }
    }
    return result;
}

/**
 * 方法 3,还是两层for循环,如果找到这个数字了，那么就就让遍历的坐标
 * 直接等于最大值，不再进行循环
*/
vector<int> searchAxis2(vector<vector<int>> &res)
{
    int i = 0, j = 0, tempi = 0, tempj = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            int temp = res[i][j];
            if (res[i][j] == 4)
            {
                tempi = i, tempj = j;
                i = 3, j = 3;
            }
        }
    }
    return {};
}

int main()
{
    vector<vector<int>> res = {
        {1, 2, 3, 4},
        {4, 5, 6, 7},
        {8, 9, 10, 11}};

    for (auto i : searchAxis(res, 2))
    {
        cout << i << endl;
    }
}