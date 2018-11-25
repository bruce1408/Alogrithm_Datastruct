#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
using namespace std;

// 数组翻转90度的算法，方法一就是直接旋转
void rotate(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-1-i;j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-i-1][n-j-1];
            matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
            matrix[j][n-1-i]= temp;
        }
    }
}






