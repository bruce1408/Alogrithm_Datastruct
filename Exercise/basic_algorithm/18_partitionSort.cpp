#include<iostream>
#include<vector>
using namespace std;

/**
 * 分割排序，找出一个数，前面的数都小于这个数
 * 后面的数都大于这个数字即可
*/

/**
 * 方法 1，归并，每次mergesort取得是区间长度的左和右，而不是数组的
 * 下标，这个是最大的不同
 * merge是合并两个已经排好序的数组
 * 
*/
int partition(vector<int>&res, int left, int right)
{   
    int temp = res[right];
    int i = left-1;
    for(int j=left;j<right;j++)//从1到倒数第二个区间范围内比遍历
    {   
        if(res[j]<=temp) // 如果当前是j的数比temp小，和j交换即可
        {
            i+=1;
            swap(res[i], res[j]);
        }
    }
    swap(res[i+1], res[right]);// 最后把i+1和中间数交换，保证满足条件
    return i+1;
}

int main()
{
    vector<int> res = {3,9,8,1,5,6,2,5};
    vector<int> temp(6);
    // mergeSort2(res, temp, 0, );
    cout<<partition(res, 0, 7)<<endl;
    for(auto i: res)
    {
        cout<<i<<" ";
    }
}