#include<iostream>
#include<vector>
using namespace std;

/**
 * 1299. Replace Elements with Greatest Element on Right Side
 * Given an array arr, replace every element in that array with the 
 * greatest element among the elements to its right, and replace the last
 * element with -1.After doing so, return the array.
 * 
 * 给定一个数组, 把他右边比自己大的数字替换当前数,最后以为是-1;
 * Example 1:
 * Input: arr = [17,18,5,4,6,1]
 * Output: [18,6,6,6,1,-1]
*/

/**
 * 方法 1, 从后往前遍历,设置一个初始值m为-1,临时数temp保存数组当前遍历的
 * 数字,然后把m赋值给数组当前元素,最后m和当前元素进行比较大小,最大数字赋值给m即可
*/
vector<int>replaceElements1(vector<int> &arr)
{
    int n = arr.size(), m = -1;
    for(int i=n-1;i>=0;i--)
    {
        int temp = arr[i];
        arr[i] = m;
        m = max(m, temp);
    }
    return arr;
}

int main()
{
    vector<int>res = {56903,18666,60499,57517,26961};
    for(auto i: replaceElements1(res))
    {
        cout<<i<<" ";
    }
}