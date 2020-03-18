#include<iostream>
#include<vector>
using namespace std;

/**
 * 选择排序是选择当前最小的数字。
 * 找出未排序数组的最小值的位置minNum，然后把minNum位置和未排序的起始
 * 位置相互交换即可
 * 
*/
vector<int>selectSort(vector<int>&res)
{
    int len = res.size();
    for(int i=0; i<len; i++)
    {
        int minNum = i;
        for(int j=i; j<len; j++)
        {
            if(res[j]<res[minNum])
            {
                minNum = j; // 把最小的数的位置找到给数组
            }
        }
        swap(res[i], res[minNum]); // 一轮结束后交换最小数字和未排序的数
    }
    return res;
}

int main()
{
    vector<int> res = {7,6,4,3,4,1};
    for(auto i:selectSort(res))
    {
        cout<<i<<endl;
    }
}