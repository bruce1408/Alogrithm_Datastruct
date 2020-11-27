#include <iostream>
#include <vector>
#include "../utils/cout_vec.h"
using namespace std;

/**
 * 归并排序,按照长度/2分成两部分，然后递归，直到每个数组数组元素是2，然后排序
 * 之后再合并即可
*/

/** 
 * 方法 1，归并，每次mergesort取得是区间长度的左和右，而不是数组的
 * 下标，这个是最大的不同
 * merge是合并两个已经排好序的数组
*/
void merge(vector<int> &res, int left, int mid, int right)
{
    int n1 = mid - left, n2 = right - mid;
    vector<int> l(n1 + 1), r(n2 + 1); // 多一个就是最后长出来的数组不用单独判断，而是自己设的最大值判断
    for (int i = 0; i < n1; i++)
        l[i] = res[left + i];
    for (int j = 0; j < n2; j++)
        r[j] = res[mid + j];
    l[n1] = INT_MAX, r[n2] = INT_MAX; // 最后取最大的数字判断
    int i = 0, j = 0;
    for (int k = left; k < right; k++)
    {
        if (l[i] <= r[j])
            res[k] = l[i++];
        else
            res[k] = r[j++];
    }
}

vector<int> mergeSort1(vector<int> &res, int left, int right)
{
    if (left + 1 < right) // 这个是隔的元素。
    {
        int mid = left + (right - left) / 2;
        mergeSort1(res, left, mid);
        mergeSort1(res, mid, right);
        merge(res, left, mid, right);
    }
    return res;
}

/**
 * 方法 2和方法1的思路一样，但是写法更加C++
*/
void Merge2(vector<int> &Array, int front, int mid, int end)
{
    vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid + 1);
    vector<int> RightSubArray(Array.begin() + mid + 1, Array.begin() + end + 1);

    int idxLeft = 0, idxRight = 0;
    LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
    RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());
    for (int i = front; i <= end; i++)
    {
        if (LeftSubArray[idxLeft] < RightSubArray[idxRight])
        {
            Array[i] = LeftSubArray[idxLeft];
            idxLeft++;
        }
        else
        {
            Array[i] = RightSubArray[idxRight];
            idxRight++;
        }
    }
}

void MergeSort2(vector<int> &Array, int front, int end)
{
    if (front >= end)
        return;
    int mid = (front + end) / 2;
    MergeSort2(Array, front, mid);
    MergeSort2(Array, mid + 1, end);
    Merge2(Array, front, mid, end);
}

/**
 * 方法 3，和方法 5 异曲同工，这个是很多教材上的写法
*/
void merge3(vector<int> &res, vector<int> &temp, int left, int mid, int right)
{
    for (int i = left; i <= right; i++)
        temp[i] = res[i];
    int i = left, j = mid + 1, t = left;
    while (i <= mid && j <= right)
    {
        if (temp[i] <= temp[j])
            res[t++] = temp[i++];
        else
            res[t++] = temp[j++];
    }
    while (i <= mid)
        res[t++] = temp[i++];
    while (j <= right)
        res[t++] = temp[j++];
}

void mergeSort3(vector<int> &res, vector<int> &temp, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort3(res, temp, left, mid);
    mergeSort3(res, temp, mid + 1, right);
    merge3(res, temp, left, mid, right);
}

/**
 *  方法 4, 和方法 5也是一样，使用归并排序进行；
*/
void mergeSort4(vector<int> &A, int l, int r)
{
    // 递归终止情况
    if (l == r)
        return;
    // 划分成子问题
    int mid = (l + r) >> 1;
    // 递归处理子问题
    mergeSort4(A, l, mid);
    mergeSort4(A, mid + 1, r);
    // 合并子问题
    int temp[r - l + 1], k = 0, i, j;
    for (i = l, j = mid + 1; i <= mid && j <= r; k++)
    {
        if (A[i] < A[j])
            temp[k] = A[i++];
        else
            temp[k] = A[j++];
    }
    while (i <= mid)
        temp[k++] = A[i++];
    while (j <= r)
        temp[k++] = A[j++];
    for (int i = l, k = 0; i <= r; i++, k++)
        A[i] = temp[k];
}

/**
 * 方法 5， 归并排序更加简单，首先分成两部分
 * 1、首先是确定分界点mid=l+r>>1
 * 2、然后进行递归排序左右区间
 * 3、接着把2个有序的序列进行合并，使用双指针，注意边界问题，都是闭区间，同时需要设置一个临时数组temp
 * 4、最后把结果复制到原数组中去即可
*/
void mergeSort5(vector<int> &res, vector<int> &temp, int l, int r)
{
    // 递归终止条件
    if (l >= r)
        return;
    // 确定分界点
    int mid = (l + r) >> 1;
    // 划分成子问题
    mergeSort5(res, temp, l, mid);
    mergeSort5(res, temp, mid + 1, r);
    // 合并子问题区间
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (res[i] < res[j])
            temp[k++] = res[i++];
        else
            temp[k++] = res[j++];
    }
    while (i <= mid)
        temp[k++] = res[i++];
    while (j <= r)
        temp[k++] = res[j++];
    for (int i = l, j = 0; i <= r; i++, j++)
    {
        res[i] = temp[j];
    }
}

int main()
{
    vector<int> res = {7, 6, 4, 3, 4, 1};
    int n = res.size();
    vector<int> temp(6);
    // mergeSort2(res, temp, 0, 6);
    // mergeSort3(res, temp, 0, n - 1);
    // mergeSort5(res, temp, 0, n - 1);
    print(res);
}