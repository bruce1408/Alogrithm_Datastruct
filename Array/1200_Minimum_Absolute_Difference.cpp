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

/**
 * 方法 1，利用排序和二分查找，排序之后遍历数组，找到差值最小的值
 * 然后再次遍历数组，利用二分查找来找到当前元素+绝对差值最小的这个值，要是找到，装入
 * 容器，直到遍历到最后即可；
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

vector<vector<int>> minimumAbsDifference1(vector<int>& arr)
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


/**
 * 方法 2，先排序，然后遍历数组，相邻两个元素进行对比，找到差值最小的那个
 * 把当前差值最小的元素放入容器，如果下次比这次还小，那么更新这次的元素，如果和这次的
 * 最小差值相同，那么直接装入容器即可；
*/
vector<vector<int>> minimumAbsDifference2(vector<int>& arr) 
{
    if (arr.empty()) return {};
    vector<vector<int>> res; 
    int n = arr.size();        
    sort(arr.begin(), arr.end());
    int lo = INT8_MAX, cur;

    for (int i = 0; i + 1 < n; ++i) {
        cur = arr[i+1] - arr[i];
        if (cur < lo && cur > 0) {
            lo = cur;
            res = {{arr[i], arr[i+1]}};
        } 
        else if (cur == lo) {
            res.push_back({arr[i], arr[i+1]});
        } 
        else {}   
    }
    return res;
}

int main()
{
    vector<int>res=  {4, 5, 1, 3};
    for(auto x:minimumAbsDifference2(res))
    {
        for(auto j: x)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
