#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int rows = triangle.size();
    int sumNum = 0;
    for (int i = 0; i < rows; i++)
    {
        int minNum = INT_MAX;
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (triangle[i][j] < minNum)
            {
                minNum = triangle[i][j];
                        }
        }
        sumNum += minNum;
    }
    return sumNum;
}

int main()
{
    vector<vector<int>> res = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
    cout << minimumTotal(res) << endl;
}
