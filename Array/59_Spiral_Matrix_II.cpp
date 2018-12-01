#include<iostream>
#include<vector>
using namespace std;
/**
    给定一个矩阵，顺时针螺旋设置矩阵的数字,
    基本思路就是从左往右，设定四个变量，上、下、左、右，然后
    奇数的话就是中间那个数字为k，偶数不用考虑
*/

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int k=1;
    int top = 0, bottom = n-1, left = 0, right = n-1;
    while(left<right && top<bottom)
    {
        for(int i = left; i<right; i++) matrix[top][i] = k++;
        for(int i = top; i<bottom; i++) matrix[i][right] = k++;
        for(int i = right; i>left; i--) matrix[bottom][i] = k++;
        for(int i = bottom; i>top; i--) matrix[i][left] = k++;
        left++;right--;top++;bottom--;
    }

    // 奇数情况
    if(n%2!=0)
    {
        matrix[n/2][n/2] = k;
    }
    return matrix;
}

int main()
{
    vector<vector<int>> res = generateMatrix(3);    
    for(auto i:res)
    {
        for(auto j: i) cout<<j<<" ";
        cout<<endl;

    }
}