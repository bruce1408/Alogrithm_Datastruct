#include<iostream>
#include<vector>
using namespace std;

int heightChecker(vector<int>& heights) 
{
    int count=1;
    for (int i=0;i<heights.size()-1;i++)
    {
        if(heights[i] >heights[i+1])
        {
            count++;
        }
    }
    return count;
}
