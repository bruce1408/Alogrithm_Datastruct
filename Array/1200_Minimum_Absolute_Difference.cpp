#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * Given an array of distinct integers arr, 
 * find all pairs of elements with the 
 * minimum absolute difference of any two elements.
 * Return a list of pairs in ascending order(with respect to pairs), 
 * each pair [a, b] follows
 * 
 * a, b are from arr
 * a < b
 * b - a equals to the minimum absolute difference of 
 * any two elements in arr
 * 
 * Example 1:
 * Input: arr = [4,2,1,3]
 * Output: [[1,2],[2,3],[3,4]]
 * Explanation: The minimum absolute difference is 1.
 *  List all pairs with difference equal to 1 in ascending order.
*/


bool binarySearch(int target, vector<int>&arr)
{
    int left = 0, right = arr.size();
    while(left<right)
    {
        int mid = left+(right-left)/2;
        if(arr[mid]<target)
        {
            left = mid+1;
        }
        else if(arr[mid]>target)
        {
            right = mid;
        }
        else
        {
            return true;
        }
    }
    return false;
}
vector<vector<int>> minimumAbsDifference(vector<int>& arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>>res;
    int lengthN = arr.size();
    int absoluteSub = INT8_MAX;
    for(int i=lengthN-1;i>=1;i--)
    {
        if(arr[i]-arr[i-1]<absoluteSub)
        {
            absoluteSub = arr[i]-arr[i-1];
        }
    }
    for(int i=0;i<lengthN;i++)
    {
        vector<int>temp;
        if(binarySearch(arr[i]+absoluteSub, arr))
        {
            temp.push_back(arr[i]);
            temp.push_back(arr[i]+absoluteSub);
            res.push_back(temp);
        }
    }
    return res;    
}

int main()
{
    vector<int>res=  {4,2,1,3};
    for(auto x:minimumAbsDifference(res))
    {
        for(auto j: x)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
