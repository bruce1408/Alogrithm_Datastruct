#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/**
 * Given an integer array sorted in non-decreasing order, 
 * there is exactly one integer in the array that occurs more than 25% of the time.
 * Return that integer.
 * 
 * Input: arr = [1,2,2,6,6,6,6,7,10]
 * Output: 6
*/

/**
 * 方法 1，利用的是一次遍历，时间复杂度是n，但是既然是排序的话，应该能想到的是二分查找来做
*/
int findSpecialInteger(vector<int>& arr) {
    int n = arr.size(), m = ceil(n * 0.25), count=0, curr=0, after=0;
    while(curr<n-1)
    {
        if(arr[curr]==arr[curr+1]) count+=1;
        else count=0
        if(count>=m) return arr[curr];
        curr+=1;
    }
    return arr[0];
}

/**
 * 方法 2，二分查找来做
*/

int main()
{
    vector<int>res = {1,2,2,6,6,6,6,7,10};
    cout<<findSpecialInteger(res)<<endl;

}