#include<iostream>
#include<vector>
using namespace std;

/**
 * maxHeap,构建最大堆
*/
template<class type>
void heapAdjust(vector<type>& vec, int index, int length)
{
    int i = index;
    int j = 2*i;
    for(; j<=length; j*=2)
    {
        if(j+1<=length && vec[j]<vec[j+1]) j++;
        if(vec[i]>vec[j]) break;
        swap(vec[i], vec[j]);
        i = j;
    }
}


/**
 * 最大堆的排序
*/
template<class type>
void heapSort(vector<type>&vec)
{
    int length = vec.size();
    for(int i=(length-1)>>1;i>=1;i--)
    {
        heapAdjust(vec, i, length-1);
    }
    
    for(int i=length-1;i>1;i--)
    {
        type temp = vec[1];
        vec[1] = vec[i];
        vec[i] = temp;
        heapAdjust(vec, 1, i-1);
    }
}

int main()
{
    vector<int>res = {0,50,10,90,30,70,40,80,60,20};
    heapSort(res);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}


