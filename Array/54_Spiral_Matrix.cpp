#include<iostream>
#include<vector>
using namespace std;
/**
    给定一个矩阵，顺时针螺旋打印矩阵的数字,
    基本思路就是从左往右旋转打印，设定四个变量，上、下、左、右，然后
    循环打印，考虑三种情况，一个是横条，一个是竖条，一个是只有一个元素
*/

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    if(matrix.empty() || matrix[0].empty()) return {};
    int m = matrix.size(), n = matrix[0].size();
    vector<int> res;
    int top = 0, bottom = m-1, left = 0, right = n-1;
    while(left<right && top<bottom)
    {
        for(int i = left;i<right;i++) res.push_back(matrix[top][i]);
        for(int i = top;i<bottom;i++) res.push_back(matrix[i][right]);
        for(int i = right;i>left;i--) res.push_back(matrix[bottom][i]);
        for(int i = bottom;i>top;i--) res.push_back(matrix[i][left]);
        left++;right--;top++;bottom--;
    }

    // 出现的竖条情况 ,也包含中间一个数字的情况
    if(left == right)
    {
        for(int i= top;i<bottom;i++) res.push_back(matrix[i][left]);
    }
    else if(top==bottom) // 出现横条的情况
    {
        for(int i=left;i<right;i++) res.push_back(matrix[top][i]);
    }
    return res;
}

int main()
{
    vector<vector<int>> res = {{1,2},{2,3}};
    vector<int> index = spiralOrder(res);
    for(auto i:index)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}