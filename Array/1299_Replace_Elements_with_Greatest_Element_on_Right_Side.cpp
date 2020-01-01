#include<iostream>
#include<vector>
using namespace std;

/**
 * 
*/
vector<int> replaceElements(vector<int>& arr)
{
    int rightNum = -1, n = arr.size();
    for(int i=n-1;i>=0;i--)
    {
        int temp = arr[i];
        arr[i] = rightNum;
        rightNum = max(temp, rightNum);
    }
    return arr;
    
}
int main()
{
    vector<int>res = {56903,18666,60499,57517,26961};
    for(auto i: replaceElements(res))
    {
        cout<<i<<" ";
    }
}