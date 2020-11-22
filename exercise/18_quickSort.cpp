#include<iostream>
#include<vector>
#include"../utils/cout_vec.h"
using namespace std;

/**
 * 快速排序，找出pviot那个数字，然后开始递归，这个数字就是分割排序
 * 计算出来的。
*/
int partition(vector<int>&res, int left, int right)
{
    int temp = res[right];
    int i = left-1;
    for(int j=left; j<right;j++)
    {
        if(res[j]<=temp)
        {
            i+=1;
            swap(res[j], res[i]);
        }
    }
    swap(res[i+1], res[right]);
    return i+1;
}

vector<int>quickSort(vector<int>&res, int left, int right)
{
    int pivot=0;
    if(left<right)
    {
        pivot = partition(res, left, right);
        quickSort(res, left, pivot-1);
        quickSort(res, pivot+1, right);
    }
    return res;
}

int main()
{
    vector<int> res = {5,1,9,3,7,4,8,6,1};
    // vector<int> temp(6);
    // mergeSort2(res, temp, 0, 6);
    // cout<<partition(res, 0, 8)<<endl;
    // for(auto i:res)
    // {
    //     cout<<i<<" ";
    // }
    quickSort(res, 0, 8);
    print(res);

    
}