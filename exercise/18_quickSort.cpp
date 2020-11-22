#include <iostream>
#include <vector>
#include "../utils/cout_vec.h"
using namespace std;

/**
 * 快速排序，找出 pivot 那个数字，然后开始递归，这个数字就是分割排序
 * 计算出来的。
*/
int partition(vector<int> &res, int left, int right)
{
    int temp = res[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (res[j] <= temp)
        {
            i += 1;
            swap(res[j], res[i]);
        }
    }
    swap(res[i + 1], res[right]);
    return i + 1;
}

vector<int> quickSort1(vector<int> &res, int left, int right)
{
    int pivot = 0;
    if (left < right)
    {
        pivot = partition(res, left, right);
        quickSort1(res, left, pivot - 1);
        quickSort1(res, pivot + 1, right);
    }
    return res;
}

/**
 * 快速排序二，简洁写法
*/
void quickSort2(vector<int> &A, int l, int r)
{
    if (l >= r)
        return;
    int pivot = A[l];
    int i = l - 1, j = r + 1;
    while (i < j)
    {
        while (i < j && A[j] > pivot)
            j--;
        while (i < j && A[i] < pivot)
            i++;
        if (i < j)
            swap(A[i], A[j]);
    }
    // swap(A[l], A[i]);
    quickSort2(A, l, j);
    quickSort2(A, j + 1, r);
}

/**
 * 手写版本
*/
void quickSort3(vector<int> &res, int l, int r)
{
    int pivot = res[l];
    int i = l, j = r;
    while (i < j)
    {
        while (i < j && res[i] <= pivot)
            i++;
        while (i < j && res[j] >= pivot)
            j--;
        if (i < j)
            swap(res[i], res[j]);
    }
    quickSort2(res, l, i - 1);
    quickSort2(res, i + 1, r);
}

int main()
{
    vector<int> res = {5, 1, 9, 3, 7, 4, 8, 6, 1};
    // vector<int> temp(6);
    // mergeSort2(res, temp, 0, 6);
    // cout<<partition(res, 0, 8)<<endl;
    // for(auto i:res)
    // {
    //     cout<<i<<" ";
    // }
    int n = res.size() - 1;
    quickSort2(res, 0, n);
    // quickSort3(res, 0, n);

    print(res);
}