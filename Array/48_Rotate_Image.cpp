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

void rotate(vector<vector<int>>& matrix) 
{
    if(matrix.size() == 0) return;
    int n = matrix.size();
    for(int layer = 0; layer < n/2; layer++)
    {
        int first = layer;
        int last = n - 1 - layer;
        for(int i = first; i<last; i++)
        {
            int offset = i - first;
            int top = matrix[first][i]; //save top
            matrix[first][i] = matrix[last-offset][first]; //left->top
            matrix[last-offset][first] = matrix[last][last - offset ]; //bottom->left
            matrix[last][last-offset] = matrix[i][last]; //right->bottom
            matrix[i][last] = top; //saved top -> right
        }
    }
}




