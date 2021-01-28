#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/**
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
 * find the area of largest rectangle in the histogram.
 * 
 * 给一个直方图，宽都是1，高是数组的值，求出面积最大的直方图。
*/
/**
 * 方法 1，单调栈，推荐使用
*/
int largestRectangleArea(vector<int>& heights) 
{
    int n = heights.size(), bar = 1, maxbar = INT_MIN;
    for(int i=0;i<n;i++)
    {
        
    }
}
int main()
{
    vector<int>res = {2,1,5,6,2,3};
    cout<<largestRectangleArea(res)<<endl;
}