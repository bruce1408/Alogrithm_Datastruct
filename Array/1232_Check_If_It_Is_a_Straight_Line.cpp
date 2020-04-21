#include <iostream>
#include <vector>
using namespace std;
/**
 * 判断是否直线
 * 两点确定一条直线,但是不能用两点式，因为如果是垂直于坐标轴的话，有可能分母为0，那么就不能用
 * 两点式，所以改写两点式方程如下：
 * 也就是点斜式改成两点式即可！
 * (x-x1)*(y2-y1)  = (y-y1)*(x2-x1)，且题目要去的是包含点大于等于2，所以可以
 * 用这个方程来写没问题；
*/

/**
 * 方法 1，用两点式的改写版本来做这道题目，把分母乘上去就可以了，然后判断每一个点
 * 是不是满足直线方程即可完成
 * 时间复杂度是O(n)
*/
bool checkStraightLine(vector<vector<int>> &coordinates)
{
    int tempx = (coordinates[1][0] - coordinates[0][0]); // x2-x2
    int tempy = (coordinates[1][1] - coordinates[0][1]); // y2-y1
    for (int i = 0; i < coordinates.size(); i++)
    {
        if ((coordinates[i][1] - coordinates[0][1]) * tempx != (coordinates[i][0] - coordinates[0][0]) * tempy)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> res = {
        {-3, -2},
        {-1, -2},
        {2, -2},
        {-2, -2},
        {0, -2}};
    cout << checkStraightLine(res) << endl;
}