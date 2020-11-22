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
 * 
*/
void merge(vector<int> &res, int left, int mid, int right)
{
    int n1 = mid - left, n2 = right - mid;
    vector<int> l(n1 + 1), r(n2 + 1); // 多一个就是最后长出来的数组不用单独判断，而是自己设的最大值判断
    for (int i = 0; i < n1; i++)
        l[i] = res[left + i];
    for (int j = 0; j < n2; j++)
        r[j] = res[mid + j];
    l[n1] = INT_MAX, r[n2] = INT_MAX; //最后取最大的数字判断
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
 * 方法 3，这个是很多教材上的写法，异曲同工，但是个人感觉没有方法1更好理解。
*/
void merge3(vector<int> &res, vector<int> &temp, int left, int mid, int right)
{
    for (int i = left; i < right; i++)
        temp[i] = res[i];
    int s1 = left, s2 = mid + 1, t = left;
    while (s1 <= mid && s2 < right)
    {
        if (temp[s1] <= temp[s2])
            res[t++] = temp[s1++];
        else
            res[t++] = temp[s2++];
    }
    while (s1 < mid)
        res[t++] = temp[s1++];
    while (s2 < right)
        res[t++] = temp[s2++];
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
 *  方法 4, 使用归并排序进行，写法更加简洁
*/
void mergeSort4(vector<int> &A, int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    mergeSort4(A, l, mid);
    mergeSort4(A, mid + 1, r);
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

int main()
{
    vector<int> res = {7, 6, 4, 3, 4, 1};
    vector<int> temp(6);
    // mergeSort2(res, temp, 0, 6);
    mergeSort4(res, 0, 6);
    print(res);
}